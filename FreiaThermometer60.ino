//FREIA thermometer, V. Ziemann, 221020
// DS18b20 1-wire temperature sensor
#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 2  // pin 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
#include <Adafruit_NeoPixel.h>
#define NUMPIXELS 60
#define PIN 6 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  Serial.begin(115200); delay(2000);
  sensors.begin();
  pixels.begin();  
}
void loop() {
  sensors.requestTemperatures();
  float temp=sensors.getTempCByIndex(0);
  int itemp=(int)temp;
  Serial.print(temp); Serial.print('\t'); Serial.println(itemp);
  pixels.clear();
  for (int k=0;k<20;k++) {  // incandescent mode
    for (int i=0;i<itemp+20;i++) {
      if (i<20) { 
        pixels.setPixelColor(i, pixels.Color(random(20),random(20), 100+random(30)));
      } else if (i<40) {
        pixels.setPixelColor(i, pixels.Color(random(20),100+random(30), random(20)));
      } else {
        pixels.setPixelColor(i, pixels.Color(130+random(30),random(20), random(20)));
      }   
 //     pixels.setPixelColor(i, pixels.Color(20+10*i+random(30),20, 100-10*i+random(30)));
     }
    pixels.show();   
    delay(50);
  }
}

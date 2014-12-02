/*
code by Tom Hastings
This sketch demonstrates a way to get your sketch to do something different every time you switch the arduino off and on again. 
It's like having a sliding switch - when the switch is set to '0' the led is off, when the switch is set to '1' the led is on.
It's really easy to add more states for the switch, so you could have '2' blink and '3' strobe or anything at all.
I find this to be the simplest way to switch between many possible states in a sketch, without having to poll for button presses (never
mind debouncing etc etc) All the hard work happens in Setup(), so your sketch is free to do what you want after.
 */
#include <EEPROM.h>

byte value;
int optionAddr = 0;
byte option;

const int ledPin = 13; // the pin that the LED is attached to


void setup() {
 pinMode(ledPin, OUTPUT);
 
//here we read 
 option = EEPROM.read(optionAddr); 
 option = option + 1;
 if (option >= 2) //2 options only, 0 or 1, you can have as many as you like 
 option = 0; // back to 0 if 
 EEPROM.write(optionAddr, option); //save the incremented option for next time
 
}

void loop() {
  //put your own functions inside the switch to do whatever you want!
  switch(option)
  {
case 0: //option is 0, led off
    LedOff();
    break;
case 1: //option is 0, led on
    LedOn();
    break;
default:
// do nothing
break;


  }//end switch

   
   
}//end loop


void LedOff()
{
  digitalWrite(ledPin, HIGH);
}

void LedOn()
{
  digitalWrite(ledPin, LOW);
}

//



#include "tone.h"


int main() {
	// internal RC oscillator calibration for 8MHz.
	OSCCAL = 176;

	// enable the piezo as output
	DDRD |= (1<<PD1);
	
	// enable internal pullup on PA7 (the button)
	PORTD |= (1<<PD7)|(1<<PD6)|(1<<PD2)|(1<<PD3);
	
	EICRA |= (1 << ISC01)|(1 << ISC11);    // set INT0 to trigger on ANY logic change
	EIMSK |= (1 << INT0)|(1 << INT1);
	sei();

	tracknumber=1;
	

	// loop forever!
	while(1) {
		if (var==1){play_();}
		
		if ((PIND&(1<<PD6))==0){
			next();
			
			_delay_ms(200);
		}
		
		if ((PIND&(1<<PD7))==0){
			pre();
			_delay_ms(200);
		}
		
		
		
		

	}
	
	return 0;
}
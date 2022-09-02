#include <iostream>
#include <string>

int cti(char c) {
	return ((int)c - (int)'0');
}

int main() {
	std::string str;
	std::cin >> str;
	
	int hour [2];
	int minute [2];
	hour[0] = cti(str[0]);
	hour[1] = cti(str[1]);
	minute[0] = cti(str[3]);
	minute[1] = cti(str[4]);

	int c = 0;
	while(true) {
		if ( (hour[0] == minute[1]) && (minute[0] == hour[1]) ) {
			break;
		}
		++minute[1];
		if (minute[1] >= 10) {
			minute[1] = 0;
			++minute[0];
			if (minute[0] >= 6) {
				minute[0] = 0;
				++hour[1];
				if (hour[1] >= 10) {
					hour[1] = 0;
					++hour[0];
				} else if ( (hour[1] == 4) && (hour[0] == 2) ) {
					hour[1] = 0;
					hour[0] = 0;
				}
			}
		}
		++c;
	}
	std::cout << c << '\n';
}
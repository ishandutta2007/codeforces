#include <iostream>
#include <cmath>

int m, d;

int main() {
	std::cin >> m >> d;
	int days = 0;
	switch(m) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		days = 31;
		break;
	case 2:
		days = 28;
		break;
	default:
		days = 30;
		break;
	}
	days -= 7 - (d - 1);
	std::cout << 1 + ceil(1.0 * days / 7);
}
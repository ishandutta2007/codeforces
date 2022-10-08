#include <iostream>

int a, b, c, a2, c2; //a = unused, b = num to combine, c = used
int sum;

int main() {
	std::cin >> a >> b;
	while(a > 0) {
		sum += a; //light up all unused candles
		a2 = (a + c) / b; //combine as many used candles as possible
		c2 = (a + c) % b; //remainder of used candles remain used
		a = a2;
		c = c2;
	}
	std::cout << sum << std::endl;
}
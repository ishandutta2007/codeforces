#include <iostream>

int main() {
	int a, b, x;
	std::cin >> a >> b >> x;

	++x;
	int curr = (a > b ? 1 : 0);
	while(x > 1) {
		if (curr == 1) --a;
		if (curr == 0) --b; 
		std::cout << (1-curr);
		curr = 1-curr;
		--x;
	}
	while(a > 0 || b > 0) {
		if (curr == 1) {
			if (b == 0) {
				curr = 0;
				continue;
			}
			--b;
			std::cout << "1";
		}
		if (curr == 0) {
			if (a == 0) {
				curr = 1;
				continue;
			}
			--a;
			std::cout << "0";
		}
	}
	std::cout << '\n';
}
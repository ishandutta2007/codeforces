#include <iostream>

int n;
int total = 0;

int main() {
	std::cin >> n;
	for(int i = 1; true; i++) {
		total += i * (i + 1) / 2;
		if(total > n) {
			std::cout << i - 1;
			break;
		}
	}
}
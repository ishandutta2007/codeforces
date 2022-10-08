#include <iostream>
#include <cmath>

int x, y;
int n;

int main() {
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			std::cin >> n;
			if(n == 1) {
				x = i + 1;
				y = j + 1;
			}
		}
	}
	std::cout << abs(x - 3) + abs(y - 3) << std::endl;
}
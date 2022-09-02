#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int w = 1;
	int h = 1;
	while(w * h < n) {
		if (w == h) {
			++w;
		} else {
			++h;
		}
	}
	std::cout << (2 * (w + h)) << '\n';
}
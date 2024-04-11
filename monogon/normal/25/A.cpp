#include <iostream>

int N;
int a, b, x;
int even, odd;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> x;
		if(x % 2) {
			odd++;
			b = i + 1;
		}else {
			even++;
			a = i + 1;
		}
	}
	std::cout << (odd == 1 ? b : a) << std::endl;
}
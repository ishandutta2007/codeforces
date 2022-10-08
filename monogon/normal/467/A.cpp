#include <iostream>

int N, a, b, sum;

int main() {
	std::cin >> N;
	for(int i = 0; i < N; i++) {
		std::cin >> a >> b;
		if(b - a >= 2)
			sum++;
	}
	std::cout << sum;
}
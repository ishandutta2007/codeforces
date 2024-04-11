#include <iostream>
#include <cmath>

long long N;

int main() {
	std::cin >> N;
	if(N % 2 == 0) std::cout << N / 2 << std::endl;
	else std::cout << (N - 1) / 2 - N << std::endl;
}
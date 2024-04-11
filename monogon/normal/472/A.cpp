#include <iostream>

int N;

int main() {
	std::cin >> N;
	if(N % 2 == 0)
		std::cout << 4 << " " << N - 4 << std::endl;
	else
		std::cout << 9 << " " << N - 9 << std::endl;
}
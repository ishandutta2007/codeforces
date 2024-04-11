#include <iostream>

int N;

int main() {
	std::cin >> N;
	std::cout << N / 5 + (N % 5 > 0);
}
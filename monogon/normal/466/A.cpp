#include <iostream>
#include <algorithm>

int N, M, a, b;

int main() {
	std::cin >> N >> M >> a >> b;
	std::cout << std::min(std::min(N * a, (1 + N / M) * b), (N / M) * b + (N % M) * a) << std::endl;
}
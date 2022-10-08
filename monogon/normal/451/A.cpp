#include <iostream>
#include <algorithm>

int N, M;

int main() {
	std::cin >> N >> M;
	std::cout << (std::min(N, M) % 2 ? "Akshat\n" : "Malvika\n");
}
#include <iostream>

int N, k, w;
int amount;

int main() {
	std::cin >> k >> N >> w;
	amount = k * w * (w + 1) / 2;
	std::cout << (amount < N ? 0 : amount - N) << std::endl;
}
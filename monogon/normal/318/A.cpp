#include <iostream>

long long n, k;

int main() {
	std::cin >> n >> k;
	if(k <= (n + 1) / 2)
		std::cout << 2 * k - 1 << std::endl;
	else
		std::cout << 2 * (k - (n + 1) / 2) << std::endl;
}
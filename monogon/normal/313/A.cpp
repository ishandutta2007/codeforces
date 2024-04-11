#include <iostream>
#include <algorithm>

int n;

int main() {
	std::cin >> n;
	std::cout << (n > 0 ? n : (n / 10) + (-n / 10) % 10 - std::min(-n % 10, (-n / 10) % 10));
}
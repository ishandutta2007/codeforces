#include <iostream>
#include <algorithm>

int a, b;

int main() {
	std::cin >> a >> b;
	std::cout << std::min(a, b) << " " << (std::max(a, b) - std::min(a, b)) / 2;
}
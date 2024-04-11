#include <iostream>
#include <algorithm>

int a, b;

int main() {
	std::cin >> a >> b;
	std::cout << (abs(a - b) <= 1 && (a > 0 || b > 0) ? "YES" : "NO");
}
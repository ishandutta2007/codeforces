
#include <iostream>
#include <cmath>

long long n, m, a;

int main() {
	std::cin >> n >> m >> a;
	std::cout << ((n / a) + (n % a > 0)) * ((m / a) + (m % a > 0)) << std::endl;
}
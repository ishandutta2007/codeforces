#include <iostream>

int main() {
	long long y;
	std::cin >> y;
	long long n = 1;
	while(n <= y) {
		n *= 10;
	}
	n /= 10;
	long long r = n;
	while(r <= y) {
		r += n;	
	}
	std::cout << r - y << '\n';
}
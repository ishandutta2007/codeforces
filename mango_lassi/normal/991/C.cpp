#include <iostream>

bool check(long long n, long long k) {
	long long a = 0;
	long long b = 0;
	long long rem;
	while(n > 0) {
		rem = std::min(k, n);
		n -= rem;
		a += rem;
		
		rem = n / 10;
		n -= rem;
		b += rem;
	}
	return a >= b;
}

int main() {
	long long n;
	std::cin >> n;
	long long low = 1;
	long long high = n;
	while(low != high) {
		long long mid = (low + high) >> 1;
		if (check(n, mid)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	std::cout << low << '\n';
}
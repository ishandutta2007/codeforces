#include <iostream>

int main() {
	long long n, m;
	std::cin >> n >> m;
	long long days = m;
	// every day d after m days decreases the amount of grain in the barn by d
	// Binary search d
	long long low = 1;
	long long high = 2 * (1e9);
	while(low != high) {
		long long mid = (low + high) / 2;
		long long offer = ((mid + 1) * mid) / 2;
		if (offer >= (n-m)) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	std::cout << std::min(n, m + low) << '\n';
}
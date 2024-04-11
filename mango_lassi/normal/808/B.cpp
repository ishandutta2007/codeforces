#include <iostream>
#include <iomanip>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::setprecision(20);

	long long n, k;
	std::cin >> n >> k;
	long long sum = 0;
	for (long long i = 1; i <= n; ++i) {
		long long v;
		std::cin >> v;
		long long mult = (k - std::max(0ll, k-i) - std::max(0ll, k-(n-i+1)));
		sum += v * mult;
	}
	std::cout << ((long double)sum) / (n-k+1) << '\n';
}
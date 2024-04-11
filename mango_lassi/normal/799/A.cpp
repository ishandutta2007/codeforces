#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, t, k, d;
	std::cin >> n >>t >> k >> d;
	if (n - (d / t) * k <= k) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}
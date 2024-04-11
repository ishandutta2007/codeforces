#include <iostream>

long long max [4];
long long inf = 3 * (1e18);

int main() {
	int n; long long p, q, r;
	std::cin >> n >> p >> q >> r;

	max[0] = 0;
	max[1] = -inf;
	max[2] = -inf;
	max[3] = -inf;
	for (int i = 0; i < n; ++i) {
		long long val;
		std::cin >> val;
		max[1] = std::max(max[1], max[0] + p * val);
		max[2] = std::max(max[2], max[1] + q * val);
		max[3] = std::max(max[3], max[2] + r * val);
	}
	std::cout << max[3] << '\n';
}
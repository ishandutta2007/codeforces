#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int m, b;
	std::cin >> m >> b;

	long long ans = 0;
	long long sum = 0;
	for (int y = 0; y <= b; ++y) {
		long long x = (b-y) * m;
		long long offer = (x * (x+1)) / 2 * (y+1) + (x+1) * sum;
		if (offer > ans) {
			ans = offer;
		}
		sum += y+1;
	}
	std::cout << ans << '\n';
}
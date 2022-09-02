#include <iostream>
#include <vector>
#include <algorithm>

const long long mod = 1e9 + 7;
const int N = 3 * 1e5;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	std::vector<int> coords;
	for (int i = 0; i < n; ++i) {
		int x;
		std::cin >> x;
		coords.push_back(x);
	}
	std::sort(coords.begin(), coords.end());
	long long sum = 0;
	long long mult = 0;
	long long pow = 2;
	for (int i = 1; i < n; ++i) {
		long long add = ((pow-1) * (coords[i] - coords[i-1])) % mod;
		mult = (mult + add) % mod;
		sum = (sum + mult) % mod;
		mult = (2 * mult) % mod;
		pow = (2 * pow) % mod;
	}
	if (sum < 0) {
		sum += mod;
	}
	std::cout << sum << '\n';
}
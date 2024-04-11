#include <iostream>
#include <vector>

const int N = 50;
const int SM = 100 * N;
const long double inf = 100000000000000.0; // 1e14
const long double margin = 0.00000000001; // 1/1e11
long double dp [N+1][SM+1];

// binary search x
int main() {

	int n, r;
	std::cin >> n >> r;
	std::vector<int> f (n);
	std::vector<int> s (n);
	std::vector<long double> chance (n);
	for (int i = 0; i < n; ++i) {
		int odds;
		std::cin >> f[i] >> s[i] >> odds;
		chance[i] = odds / 100.0;
	}

	long double max = inf;
	long double min = 1.0;
	std::cout.precision(20);
	std::cout.setf( std::ios::fixed );
	while(max - min > margin) {
		long double mid = (max + min) / 2;
		long double res;
		for (int i = 0; i <= r; ++i) {
			dp[n][i] = 0;
		}
		int max_can = r;
		for (int j = n-1; j >= 0; --j) {
			for (int i = 0; i <= max_can - f[j]; ++i) {
				int get_fast = i + f[j];
				int get_slow = i + s[j];
				bool fast_less = (get_fast <= max_can);
				bool slow_less = (get_slow <= max_can);
				long double if_fast = f[j] + (fast_less ? (dp[j+1][get_fast]) : mid);
				long double if_slow = s[j] + (slow_less ? (dp[j+1][get_slow]) : mid);
				long double offer = chance[j] * if_fast + (1 - chance[j]) * if_slow;
				dp[j][i] = std::min(mid, offer);
			}
			max_can -= f[j];
		}
		if (dp[0][0] < mid) {
			max = mid;
		} else {
			min = mid;
		}
	}

	std::cout << max << '\n';
}
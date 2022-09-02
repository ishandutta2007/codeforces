#include <iostream>

const int N = 49 * (int)1e4;
const int M = 1e6;
const int INF = (int)1e9 + 7;
int dp[M + 50];

int main() {
	for (int i = 1; i < M; ++i) {
		dp[i] = INF;
	}
	for (int i = 0; i < M; ++i) {
		dp[i + 4] = std::min(dp[i + 4], dp[i] + 1);
		dp[i + 9] = std::min(dp[i + 9], dp[i] + 1);
		dp[i + 49] = std::min(dp[i + 49], dp[i] + 1);
	}

	long long n;
	std::cin >> n;
	// First set all to ones
	// Then we have three options: +4, +9, +49
	// We can definetely represent all numbers in [N, 49*n - N]
	// Check which numbers we can represent in that interval

	long long res = 0;
	for (int i = 0; i < N; ++i) {
		if (dp[i] <= n) ++res;
	}
	for (int i = N; i < N + 49; ++i) {
		int base = dp[i];
		res += std::max((long long)0, n - base + 1);
	}
	std::cout << res << '\n';
}
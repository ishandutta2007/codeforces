#include<iostream>

const int N = 500;
const int K = 10;
const int C = (int)1e5;
long long dp[N + 1][K * N + 1];
int cards[C];
int plays[C];
long long happy[K + 1];
int k;

long long calc(int n, int c) {
	if (c == 0) return 0;
	if (n == 0) return 0;
	if (dp[n][c] != -1) return dp[n][c];
	long long res = 0;
	for (int i = 0; i <= std::min(k, c); ++i) {
		res = std::max(res, happy[i] + calc(n - 1, c - i));
	}
	dp[n][c] = res;
	return res;
}

int main() {
	int n;
	std::cin >> n >> k;
	for (int i = 0; i <= n; ++i) {
		for (int j = 1; j <= n * k; ++j) {
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < n * k; ++i) {
		int c;
		std::cin >> c;
		--c;
		++cards[c];
	}
	for (int i = 0; i < n; ++i) {
		int c;
		std::cin >> c;
		--c;
		++plays[c];
	}

	happy[0] = 0;
	for (int i = 1; i <= k; ++i) std::cin >> happy[i];

	long long res = 0;
	for (int i = 0; i < C; ++i) {
		long long sub = calc(plays[i], cards[i]);
		res += sub;
	}
	std::cout << res << '\n';
}
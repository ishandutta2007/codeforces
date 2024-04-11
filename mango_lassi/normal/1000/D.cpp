#include <iostream>

const int N = 1e3;
const int MOD = 998244353;
int val[N];
int dp[N + 1];
int cho[N+1][N+1];

int main() {
	cho[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		cho[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			cho[i][j] = (cho[i-1][j] + cho[i-1][j-1]) % MOD;
		}
	}

	int n;
	std::cin >> n;
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		std::cin >> val[i];
		dp[i+1] = dp[i];
		for (int j = 0; j < i; ++j) {
			int v = val[j] + 1;
			int len = i-j+1;
			if (v > 1 && v <= len) {
				dp[i+1] = (dp[i+1] + (long long)dp[j] * cho[len-2][v-2]) % MOD;
			}
		}
	}
	std::cout << (dp[n]+MOD-1) % MOD << '\n';
}
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, k, d;
long long dp[205][5];

int main() {
	scanf("%d%d%d", &n, &k, &d);
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i + j][1] += dp[i][1];
			if (j < d) {
				dp[i + j][0] += dp[i][0];
				dp[i + j][0] %= MOD;
			}
			else {
				dp[i + j][1] += dp[i][0];
			}
			dp[i + j][1] %= MOD;
		}
	}
	printf("%lld\n", dp[n][1]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, b, mod;
int a[505];
ll dp[2][505][505], ans;

int main() {
	scanf("%d%d%d%d", &n, &m, &b, &mod);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= b; k++) {
				if (i != 0) {
					dp[i % 2][j][k] = dp[(i - 1) % 2][j][k];
				}
				if (j - 1 >= 0 && k - a[i] >= 0) {
					dp[i % 2][j][k] += dp[i % 2][j - 1][k - a[i]];
				}
				dp[i % 2][j][k] %= mod;
			}
		}
	}
	for (int k = 0; k <= b; k++) {
		ans += dp[(n - 1) % 2][m][k];
		ans %= mod;
	}
	printf("%lld\n", ans);
	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 2e3 + 100;
const int mod = 998244353;
int power(int a, int b) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		int t = power(a, b / 2);
		return 1LL *t * t % mod;
	}
	return 1LL *a * power(a, b - 1) % mod;
}
int fact[N], ifact[N];
int dp[2][110][N * 2];
int sum[2 * N];
int a[N], b[N];
signed main() {
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int x;
		//x = 50;
		scanf("%d", &x);
		a[i] = std::max(0, x - k);
		b[i] = std::min(n, x + k);
	}
	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = 1LL * fact[i - 1] * i % mod;
	}
	ifact[N - 1] = power(fact[N - 1], mod - 2);
	for (int i = N - 2; i >= 0; i--) {
		ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
	}
	int cur = 0, nxt;
	dp[0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nxt = cur ^ 1;
		memset(dp[nxt], 0, sizeof dp[nxt]);
		memset(sum, 0, sizeof sum);
		for (int j = a[i], p = a[i - 1] - 1; j <= b[i]; j++) {
			while (p < b[i - 1] && p < j - 1) {
				p++;
				for (int k1 = 0; k1 < i; k1++) {
					sum[p + k1] = (sum[p + k1] + 1LL * fact[k1] * dp[cur][p - a[i - 1]][k1]) % mod;
				}
			}
			for (int k1 = 0; k1 <= i; k1++) {
				int id = j - a[i];
				dp[nxt][id][k1] = 1LL * sum[j + k1 - 1] * ifact[k1] % mod;
				if (a[i - 1] <= j && j <= b[i - 1]) {
					dp[nxt][id][k1] = (dp[nxt][id][k1] + dp[cur][j - a[i - 1]][k1 - 1]) % mod;
					dp[nxt][id][k1] = (dp[nxt][id][k1] + 1LL * dp[cur][j - a[i - 1]][k1] * (j + k1)) % mod;
				}
			}
		}
		cur = nxt;
	}
	int ans = 0;
	for (int i = a[n]; i <= b[n]; i++) {
		for (int j = 0; j + i <= n; j++) {
			ans = (ans + 1LL * dp[cur][i - a[n]][j] * fact[n - i] % mod * ifact[n - j - i]) % mod;
		}
	}
	printf("%d", ans);
	return 0;
}
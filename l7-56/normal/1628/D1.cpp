#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll maxn = 2010, mod = 1e9 + 7, inv2 = 500000004;
ll n,m,k,dp[maxn][maxn];
void work() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (ll i = 1; i <= n; ++i) {
		dp[i][0] = 0, dp[i][i] = k * i % mod;
		for (ll j = 1; j < i && j <= m; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod * inv2 % mod;
	}
	printf("%lld\n", dp[n][m]);
}

int main() {
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}
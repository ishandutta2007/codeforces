#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 10010, inf = LLONG_MAX;
ll n,c,p[maxn],s[maxn],dp[2][maxn];

int main() {
	scanf("%lld%lld", &n, &c);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &p[i]);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &s[i]);
	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;
	for (ll i = 1; i <= n; ++i) {
		ll a = i & 1, b = !a;
		for (ll j = 0; j <= i; ++j) {
			dp[a][j] = inf;
			if (j < i) dp[a][j] = min(dp[b][j] + p[i] + j * c, dp[a][j]);
			if (j) dp[a][j] = min(dp[b][j - 1] + s[i], dp[a][j]);
		}
	}
	ll ans = inf;
	for (ll i = 0; i <= n; ++i) ans = min(ans, dp[n & 1][i]);
	printf("%lld\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e5 + 10, inf = 4e18;
ll n,dp[maxn],a[maxn];

int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) dp[i] = -inf;
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		for (int j = i; j; --j)
			dp[j] = max(dp[j], dp[j - 1] + a[i] * j);
	}
	ll ans = 0;
	for (int j = 1; j <= n; ++j) ans = max(ans, dp[j]);
	printf("%lld\n", ans);
	return 0;
}
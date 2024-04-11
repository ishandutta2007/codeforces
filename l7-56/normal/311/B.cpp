#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll maxn = 1e5 + 10, maxp = 110;
ll n,m,p,d[maxn],h[maxn],t[maxn],a[maxn],s[maxn],dp[maxp][maxn],q[maxn],hd,tl,ans;

int main() {
	scanf("%lld%lld%lld", &n, &m, &p);
	for (ll i = 2; i <= n; ++i) scanf("%lld", &d[i]), d[i] += d[i - 1];
	for (ll i = 1; i <= m; ++i) scanf("%lld%lld", &h[i], &t[i]), a[i] = t[i] - d[h[i]];
	sort(a + 1, a + m + 1);
	for (ll i = 1; i <= m; ++i) s[i] = s[i - 1] + a[i];
	memset(dp, 0x3f, sizeof dp);
	ans = LLONG_MAX;
	dp[0][0] = 0;
	for (ll i = 1; i <= p; ++i) {
		hd = tl = 1, q[1] = 0;
		#define X(k) (k)
		#define Y(k) (dp[i - 1][k] + s[k])
		#define slope(x, y) (((ld)(Y(x) - Y(y))) / (X(x) - X(y)))
		dp[i][0] = 0;
		for (ll j = 1; j <= m; ++j) {
			while (hd < tl && slope(q[hd], q[hd + 1]) <= a[j]) ++hd;
			dp[i][j] = Y(q[hd]) - a[j] * X(q[hd]) - s[j] + a[j] * j;
			while (hd < tl && slope(q[tl - 1], q[tl]) > slope(q[tl], j)) --tl;
			q[++tl] = j;
		}
		ans = min(ans, dp[i][m]);
	}
	printf("%lld\n", ans);
	return 0;
}
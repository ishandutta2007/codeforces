#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

const ll maxn = 2e5 + 10, maxk = 60, inf = 3e18;
ll n,K,st[maxn],q[maxn],hd,tl;
ld sa[maxn],sb[maxn],dp[maxn][maxk];

int main() {
	scanf("%lld%lld", &n, &K);
	for (ll i = 1; i <= n; ++i) {
		scanf("%lld", &st[i]);
		ld t = st[i]; st[i] += st[i - 1];
		sa[i] = sa[i - 1] + st[i] / t;
		sb[i] = sb[i - 1] + 1 / t;
	}
	for (ll i = 1; i <= n; ++i) dp[i][0] = inf;
	for (ll j = 1; j <= K; ++j) {
		hd = tl = 1; q[1] = 0;
		#define X(k) (st[k])
		#define Y(k) (dp[k][j - 1] - sa[k] + st[k] * sb[k])
		#define slope(x, y) (X(x) == X(y) ? inf : (Y(x) - Y(y)) / (ld) (X(x) - X(y)))
		for (ll i = 1; i <= n; ++i) {
			while (hd < tl && slope(q[hd], q[hd + 1]) <= sb[i]) ++hd;
			dp[i][j] = Y(q[hd]) - sb[i] * X(q[hd]) + sa[i];
			while (hd < tl && slope(q[tl - 1], q[tl]) >= slope(q[tl], i)) --tl;
			q[++tl] = i;
		}
	}
	printf("%.6Lf\n", dp[n][K]);
	return 0;
}
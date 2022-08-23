#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

int n;
ld c, t;
ld ss[120];
ld dp[110][1100];

pair<int, int> a[120];

void solve() {
	cin >> n;
	cin >> c >> t;
	ss[0] = 1;
	for (int i = 1; i <= n; ++i)
		ss[i] = (0.9 * ss[i - 1]);
	int sum = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i].first >> a[i].second;
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < 110; ++i)
		for (int j = 0; j < 1100; ++j)
			dp[i][j] = 1e18;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j >= 0; --j) {
			ld go = a[i].first / ss[j + 1];
			for (int k = 0; k <= sum; ++k) {
				dp[j + 1][k + a[i].second] = min(dp[j + 1][k + a[i].second], dp[j][k] + go);
			}
		}
		sum += a[i].second;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= sum; ++j) {
			if (dp[i][j] > 1e17)
				continue;
			ld T = t - 10 * i;
			if (T <= 0)
				continue;
			if (c * dp[i][j] >= 1) {
				ld tt = (2 * sqrt(c * dp[i][j]) - 1) / c;
				if (tt <= T)
					ans = max(ans, ll(j));
			}
			else {
				ld tt = dp[i][j];
				if (tt <= T)
					ans = max(ans, ll(j));
			}
		}
	cout << ans << "\n";
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; ++i)
		solve();
	return 0;
}
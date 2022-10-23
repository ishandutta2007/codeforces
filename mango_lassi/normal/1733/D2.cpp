#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = (ll)1e18 + 7;

void solve() {
	int n;
	ll x, y;
	cin >> n >> x >> y;

	string src, tar;
	cin >> src >> tar;

	vector<int> xr(n, 0);
	for (int i = 0; i < n; ++i) xr[i] = (src[i] != tar[i]);
	
	int diff = 0, fi = n, la = -1;
	for (int i = 0; i < n; ++i) {
		diff += xr[i];
		if (xr[i]) fi = min(fi, i);
		if (xr[i]) la = max(la, i);
	}
	
	if (diff & 1) {
		cout << -1 << '\n';
	} else if (diff == 0) {
		cout << 0 << '\n';
	} else if (fi + 1 == la) {
		if (x <= y || n <= 3) cout << x << '\n';
		else if (n > 4 || fi != 1) cout << min(x, 2*y) << '\n';
		else cout << min(x, 3*y) << '\n';
	} else {
		x = min(x, y);
		vector<array<ll, 4>> dp(n + 1);
		dp[0] = {0ll, INF, INF, INF};
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j < 4; ++j) dp[i][j] = INF;
			for (int s = 0; s < 4; ++s) {
				for (int t = 0; t < 4; ++t) {
					int v = xr[i - 1] ^ (s & 1) ^ (t & 1);
					ll off = dp[i-1][s] + ((t & 1) ? x : 0ll);
					if ((t & 2) != (s & 2)) {
						v ^= 1;
						if ((s & 2)) off += y;
					}
					if (v == 0) dp[i][t] = min(dp[i][t], off);
				}
			}
		}
		cout << dp[n][0] << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
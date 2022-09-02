#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	array<ll, 4> dp;
	for (int i = 0; i <= n; ++i) {
		array<ll, 4> nxt;
		for (ll& v : nxt) v = INF;

		if (i == 0) {
			nxt[0] = 0;
			nxt[1] = abs(1 - as[0]);
			nxt[2] = abs(k - as[0]);
			nxt[3] = abs(1 - k) + min(nxt[1], nxt[2]);
		} else if (i == n) {
			ll a = as[i-1];
			for (int x = 0; x < 4; ++x) {
				nxt[x] = min(nxt[x], dp[x]);
				nxt[x | 1] = min(nxt[x | 1], dp[x] + abs(a - 1));
				nxt[x | 2] = min(nxt[x | 2], dp[x] + abs(a - k));
				nxt[x | 3] = min(nxt[x | 3], dp[x] + abs(a - 1) + abs(1 - k));
				nxt[x | 3] = min(nxt[x | 3], dp[x] + abs(a - k) + abs(k - 1));
			}
		} else {
			ll a = as[i-1];
			ll b = as[i];
			for (int x = 0; x < 4; ++x) {
				nxt[x] = min(nxt[x], dp[x] + abs(a - b));
				nxt[x | 1] = min(nxt[x | 1], dp[x] + abs(a - 1) + abs(1 - b));
				nxt[x | 2] = min(nxt[x | 2], dp[x] + abs(a - k) + abs(k - b));
				nxt[x | 3] = min(nxt[x | 3], dp[x] + abs(a - 1) + abs(1 - k) + abs(k - b));
				nxt[x | 3] = min(nxt[x | 3], dp[x] + abs(a - k) + abs(k - 1) + abs(1 - b));
			}
		}
		dp = nxt;
	}
	cout << dp[3] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
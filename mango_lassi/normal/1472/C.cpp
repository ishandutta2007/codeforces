#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> vals(n);
	for (ll& v : vals) cin >> v;

	ll res = 0;
	vector<ll> dp(n, 0);
	for (int i = n-1; i >= 0; --i) {
		ll t = (i + vals[i] >= n ? i + vals[i] : dp[i + vals[i]]);
		res = max(res, t - i);
		dp[i] = t;
	}
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
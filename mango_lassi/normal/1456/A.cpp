#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll p, k;
	cin >> n >> p >> k;
	--p;

	string as;
	cin >> as;

	ll x, y;
	cin >> x >> y;

	vector<ll> dp(n, 0);
	for (int i = n-1; i >= 0; --i) {
		if (as[i] == '0') dp[i] += x;
		if (i + k < n) dp[i] += dp[i + k];
	}

	ll res = dp[p];
	for (int j = 1; p + j < n; ++j) res = min(res, y * j + dp[p + j]);
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
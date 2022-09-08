#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res = max(res, as[i] - as[(i + 1) % n]);
		if (i < n-1) res = max(res, as[n-1] - as[i]);
		if (i > 0) res = max(res, as[i] - as[0]);
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
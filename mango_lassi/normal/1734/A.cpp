#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18 + 7;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	ll res = INF;
	for (int i = 0; i + 2 < n; ++i) {
		ll off = as[i + 2] - as[i];
		res = min(res, off);
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
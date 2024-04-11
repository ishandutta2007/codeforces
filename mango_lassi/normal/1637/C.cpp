#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0, ones = 0;
	for (int i = 1; i + 1 < n; ++i) {
		if (as[i] == 1) ++ones;
		res += (as[i] + 1) / 2;
	}
	if (ones == n-2 || (n == 3 && (as[1] & 1))) cout << -1 << '\n';
	else cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
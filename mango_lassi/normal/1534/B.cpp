#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll add = 0;
	for (int i = 0; i < n; ++i) {
		ll lf = (i == 0 ? 0 : as[i-1]);
		ll rf = (i == n-1 ? 0 : as[i+1]);
		ll cap = max(lf, rf);
		if (as[i] > cap) {
			add += as[i] - cap;
			as[i] = cap;
		}
	}

	ll res = as[0] + as[n-1];
	for (int i = 1; i < n; ++i) {
		res += abs(as[i] - as[i-1]);
	}
	cout << add + res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
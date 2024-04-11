#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	vector<ll> adds(n+10, 0);
	for (int i = 0; i < n; ++i) {
		if (i > 0) adds[i] += adds[i-1];

		if (adds[i] < as[i]) {
			res += as[i] - adds[i];
		} else {
			// Extra bounces at i+1
			adds[i + 1] += adds[i] - as[i];
			adds[i + 2] -= adds[i] - as[i];
		}

		as[i] = min(as[i], (ll)(n-1-i));
		adds[i + 1] += 1;
		adds[i + as[i] + 1] -= 1;
	}
	cout << res - 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
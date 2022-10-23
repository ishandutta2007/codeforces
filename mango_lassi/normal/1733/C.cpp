#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	
	cout << n-1 << '\n';
	if (n > 1) {
		cout << 1 << ' ' << n << '\n';
		if ((as[0] + as[n-1]) & 1) as[n-1] = as[0];
		else as[0] = as[n-1];

		ll v = as[0];
		for (int i = 1; i < n-1; ++i) {
			if ((as[i] + v) & 1) cout << 1 << ' ' << i+1 << '\n';
			else cout << i+1 << ' ' << n << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
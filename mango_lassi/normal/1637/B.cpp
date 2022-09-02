#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	ll res = 0;
	for (int x = 0; x < n; ++x) {
		for (int y = x; y < n; ++y) {
			for (int i = x; i <= y; ++i) res += 1 + (as[i] == 0);
		}
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
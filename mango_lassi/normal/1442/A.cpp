#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	// If a_i = a_{i+1} + k, we subtract from the prefix starting at i k times
	// If a_i + k = a_{i+1}, we subtract from the suffix starting at i+1 k times
	// These are forced moves. If at the end all numbers are >= 0, return YES. Otherwise, return NO

	vector<ll> as(n);
	for (ll& a : as) cin >> a;

	vector<ll> lsub(n, 0), rsub(n, 0);
	for (int i = 0; i+1 < n; ++i) {
		if (as[i] < as[i+1]) rsub[i+1] += as[i+1] - as[i];
		if (as[i] > as[i+1]) lsub[i] += as[i] - as[i+1];
	}
	for (int i = 1; i < n; ++i) {
		rsub[i] += rsub[i-1];
		as[i] -= rsub[i];
	}
	for (int i = n-2; i >= 0; --i) {
		lsub[i] += lsub[i+1];
		as[i] -= lsub[i];
	}

	bool fail = 0;
	for (auto v : as) {
		if (v < 0) fail = 1;
	}
	if (fail) cout << "NO\n";
	else cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}
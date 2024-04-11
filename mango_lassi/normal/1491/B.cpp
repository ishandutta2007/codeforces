#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll cost_hori, cost_vert;
	cin >> n >> cost_vert >> cost_hori;

	vector<int> as(n);
	for (int& a : as) cin >> a;

	int d = 0;
	for (int i = 0; i+1 < n; ++i) {
		d = max(abs(as[i] - as[i+1]), d);
	}

	if (d == 0) {
		cout << min(2 * cost_hori, cost_hori + cost_vert) << '\n';
	} else if (d == 1) {
		cout << min(cost_hori, cost_vert) << '\n';
	} else {
		cout << 0 << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
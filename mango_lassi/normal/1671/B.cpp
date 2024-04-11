#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;
	vector<ll> xs(n);
	for (ll& x : xs) cin >> x;
	sort(xs.begin(), xs.end());

	int state = 7;
	for (int i = 1; i < n; ++i) {
		int nxt = 0;
		for (int j = 0; j < 3; ++j) {
			if (! (state & (1 << j))) continue;
			ll tx = xs[i-1] + j;
			if (tx == xs[i] - 1) nxt |= 1;
			else if (tx == xs[i]) nxt |= 2;
			else if (tx == xs[i] + 1) nxt |= 4;
		}
		state = nxt;
	}
	if (state) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const ll INF = (ll)1e9 + 7;

void solve() {
	int n;
	ll k;
	cin >> n >> k;


	vector<ll> vals(n);
	ll mn = INF, mx = -INF; // max
	for (ll& v : vals) {
		cin >> v;
		mn = min(mn, v);
		mx = max(mx, v);
	}

	// Only the minimum and maximum value matter in the operations
	// After first operation, minimum is 0 -> operation is its own inverse operation
	
	--k;
	for (ll& v : vals) v = mx - v;

	k %= 2;
	if (k == 1) {
		for (ll& v : vals) v = (mx - mn) - v;
	}

	for (ll& v : vals) cout << v << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
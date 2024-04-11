#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

bool check(ll a, vector<ll> vals) {
	for (int i = 1; i < vals.size(); ++i) {
		vals[i] = max(vals[i], min(vals[i] + a, vals[i-1]));
		if (vals[i] < vals[i-1]) return false;
	}
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<ll> vals(n);
	for (ll& a : vals) cin >> a;

	for (ll k = 0;; ++k) {
		ll a = (1ll << k) - 1;
		if (check(a, vals)) {
			cout << k << '\n';
			return;
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
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll sum = 0;
	multiset<ll> as;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		sum += a;
		as.insert(a);
	}

	bool works = 1;
	for (ll v = sum, x = 1, y = 0, z = 0; v > 0; v /= 2) {
		while(true) {
			auto it = as.find(v + 1);
			if (it != as.end()) {
				works &= (y > 0);
				--y;
				as.erase(it);
			} else break;
		}
		if (v == 1) {
			x += 2 * y;
			y = 0;
		} else if (v == 2) {
			x += y;
			z = y;
			y = 0;
		}
		while(true) {
			auto it = as.find(v);
			if (it != as.end()) {
				works &= (x > 0);
				--x;
				as.erase(it);
			} else break;
		}
		if (v & 1) {
			ll nx = x + z;
			ll ny = x + 2*y;
			x = nx;
			y = ny;
		} else {
			ll nx = 2*x + y + z;
			ll ny = y;
			x = nx;
			y = ny;
		}
	}
	cout << ((works && as.empty()) ? "YES" : "NO") << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}
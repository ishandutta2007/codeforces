#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve() {
	ll n, m, ca, cb, wa, wb;
	cin >> n >> m >> ca >> cb >> wa >> wb;

	// Make axes better than boomerangs
	if (wa > wb) {
		swap(ca, cb);
		swap(wa, wb);
	}

	// Take as many axes as possible. If you can take all, take some boomerangs as well
	ll ta = n / wa + m / wa;
	if (ta <= ca) {
		cout << ta << '\n';
		return;
	}

	// Iterate over how many axes we give the first person
	ll res = ca;
	for (ll x = 0; x <= ca; ++x) {
		ll n2 = n - wa * x;
		ll m2 = m - wa * (ca - x);
		if (n2 >= 0 && m2 >= 0) res = max(res, ca + min(cb, n2/wb + m2/wb));
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x;
	cin >> x;
	ll res_a = x, res_b = 1;

	vector<ll> ps;
	for (ll d = 2; d*d <= x; ++d) {
		if (x % d == 0) {
			ll dv = d;
			while(x % (dv * d) == 0) dv *= d;
			x /= dv;
			ps.push_back(dv);
		}
	}
	if (x > 1) ps.push_back(x);

	int n = ps.size();
	for (int m = 0; m < (1 << n); ++m) {
		ll a = 1, b = 1;
		for (int i = 0; i < n; ++i) {
			if (m & (1 << i)) a *= ps[i];
			else b *= ps[i];
		}
		if (max(a, b) < max(res_a, res_b)) {
			res_a = a;
			res_b = b;
		}
	}
	cout << res_a << ' ' << res_b << '\n';
}
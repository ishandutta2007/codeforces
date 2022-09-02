#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll getpw(ll v, ll x) {
	ll res = 1;
	while(v % x == 0) {
		v /= x;
		res *= x;
	}
	return res;
}

vector<ll> dv(ll v) {
	vector<ll> res;
	for (ll x = 2; x*x <= v; ++x) {
		if (v % x == 0) {
			res.push_back(x);
			while(v % x == 0) v /= x;
		}
	}
	if (v != 1) res.push_back(v);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll p, q;
		cin >> p >> q;

		if (p % q == 0) {
			auto dvs = dv(q);
			ll res = 1;
			for (auto v : dvs) {
				ll a = getpw(p, v);
				ll b = getpw(q, v);
				res = max(res, p / (a / b) / v);
			}
			cout << res << '\n';
		} else {
			cout << p << '\n';
		}
	}
}
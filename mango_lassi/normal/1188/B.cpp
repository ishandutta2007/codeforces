#include <iostream>
#include <set>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	ll p, k;
	cin >> n >> p >> k;

	// (x + y)(xx + yy)
	// = xxx + xxy + xyy + yyy
	// = (x^3 - y^4/x) / (1 - y/x) (geometric sum)
	// = (x^3 - y^4/x) / (x - y) / x
	// = (x^4 - y^4) / (x - y) = k
	// -> x^4 - y^4 = xk - yk (mod p)
	// -> x^4 - xk = y^4 - yk (mod p)
	// since 0 <= x, y < p, so x == y (mod p) iff x = y

	ll res = 0;
	multiset<ll> vals;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		ll xx = (x*x) % p;
		ll v = (xx*xx - x*k) % p;
		if (v < 0) v += p;
		res += vals.count(v);
		vals.insert(v);
	}
	cout << res << '\n';
}
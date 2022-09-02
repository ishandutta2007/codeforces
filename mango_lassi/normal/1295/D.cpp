#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// do inclusion-exclusion over m's prime divisors
ll count(ll h, ll m) {
	// cerr << "count(" << h << ' ' << m << "): ";
	vector<ll> ps;
	for (ll d = 2; d*d <= m; ++d) {
		if (m % d == 0) {
			ps.push_back(d);
			while(m % d == 0) m /= d;
		}
	}
	if (m > 1) ps.push_back(m);

	int n = ps.size();
	ll res = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		ll v = 1;
		ll sgn = 1;
		for (int j = 0; j < n; ++j) {
			if (mask & (1 << j)) {
				v *= ps[j];
				sgn *= -1;
			}
		}
		res += sgn * (h / v + 1);
	}
	// cerr << res << '\n';
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int tc;
	cin >> tc;
	for (int ti = 0; ti < tc; ++ti) {
		// Count 0 <= x < m s.t. gcd(a, m) = gcd(a + x, m)
		ll a, m;
		cin >> a >> m;
		ll b = gcd(a, m);
		a /= b;
		m /= b;
		
		// gcd(a + x, m) = 1 given gcd(a, m) = 1
		// -> count x s.t. gcd(x, m) = 1 and a <= x <= a + m
		ll res = count(a + m - 1, m) - count(a-1, m);
		cout << res << '\n';
	}
}
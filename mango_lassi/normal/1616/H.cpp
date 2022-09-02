#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
const int N = 150000;
ll tp[N + 1];
vector<ll> as;

// Take some subset of as[a, b] and as[c, d]
ll solve(int a, int b, int c, int d, ll x, ll h, bool exc_empty = 1) {
	if (h == 0 || (c > d) || (a > b)) {
		int cou = b-a+1 + d-c+1;
		// cerr << "Solve " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << x << ' ' << h << ": " << tp[cou] - exc_empty << '\n';
		return (tp[cou] + MOD - exc_empty) % MOD;
	}

	int m0 = a, m1 = c;
	while(m0 <= b && !(as[m0] & h)) ++m0;
	while(m1 <= d && !(as[m1] & h)) ++m1;

	if (x & h) {
		// HAS BIT
		ll r0 = solve(a, m0 - 1, m1, d, x, h >> 1, 0);
		ll r1 = solve(m0, b, c, m1 - 1, x, h >> 1, 0);
		// cerr << "Solve " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << x << ' ' << h << ": " << r0 << ' ' << r1 << ' ' << (r0 * r1 - 1) % MOD << '\n';
		return (r0 * r1 - exc_empty) % MOD;
	} else {
		// DOESN'T HAVE BIT
		ll r0 = solve(a, m0 - 1, c, m1 - 1, x, h >> 1, 1);
		ll r1 = solve(m0, b, m1, d, x, h >> 1, 1);
		ll a00 = tp[m0-a];
		ll a01 = tp[b-m0+1];
		ll a10 = tp[m1-c];
		ll a11 = tp[d-m1+1];

		ll add = ((a00 * a01 - a00 - a01 + 1) + (a10 * a11 - a10 - a11 + 1)) % MOD;
		if (add < 0) add += MOD;

		/*
		cerr << "NO BIT! ";
		for (int j = a; j < m0; ++j) cerr << as[j] << ' '; cerr << ";; ";
		for (int j = m0; j <= b; ++j) cerr << as[j] << ' '; cerr << ";; ";
		for (int j = c; j < m1; ++j) cerr << as[j] << ' '; cerr << ";; ";
		for (int j = m1; j <= d; ++j) cerr << as[j] << ' '; cerr << ";; ";
		cerr << '\n';

		cerr << "Solve " << a << ' ' << b << ' ' << c << ' ' << d << ' ' << x << ' ' << h << ": " << r0 << ' ' << r1 << ' ' << add << ' ' << (r0 + r1 + add) % MOD << '\n';
		*/

		return (r0 + r1 + add + !exc_empty) % MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	ll x;
	cin >> n >> x;

	tp[0] = 1;
	for (int i = 1; i <= n; ++i) tp[i] = 2 * tp[i-1] % MOD;

	ll h = 1;
	while(h <= x) h <<= 1;

	as.resize(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());

	ll res = 0;
	for (int i = 0; i < n;) {
		int j = i;
		while(j < n && (as[j] ^ as[i]) < (h >> 1)) ++j;
		int m = j;
		while(j < n && (as[j] ^ as[i]) < h) ++j;
	
		ll add = solve(i, m-1, m, j-1, x, h >> 2, 1);
		res = (res + add) % MOD;
	
		i = j;
	}
	cout << res << '\n';
}
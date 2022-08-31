#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

ll gcd(ll a, ll b) {
	while (b) {
		ll q = a % b;
		a = b;
		b = q;
	}
	return a;
}

ll n, m, k;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> k;
	if (k == 1) {
		cout << "NO\n";
		return 0;
	}
	if ((2 * n * m) % k != 0)
		cout << "NO\n";
	else if (k % 2 == 0) {
		k /= 2;
		ll g = gcd(k, n);
		n /= g;
		k /= g;
		m /= k;
		cout << "YES\n";
		cout << 0 << " " << 0 << "\n";
		cout << n << " " << 0 << "\n";
		cout << 0 << " " << m << "\n";
	}
	else {
		ll g = gcd(k, n);
		ll n2 = n / g;
		k /= g;
		ll m2 = m / k;
		if (n2 * 2 <= n)
			n2 *= 2;
		else
			m2 *= 2;
		cout << "YES\n";
		cout << 0 << " " << 0 << "\n";
		cout << n2 << " " << 0 << "\n";
		cout << 0 << " " << m2 << "\n";
	}
	return 0;
}
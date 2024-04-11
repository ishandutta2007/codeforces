#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll p, q, b;
		cin >> p >> q >> b;
		p %= q;
		ll g = gcd(p, q);
		p /= g;
		q /= g;
		g = gcd(q, b);
		while (true) {
			ll x = gcd(q, g);
			if (x != 1)
				q /= x;
			else
				break;
		}
		if (q == 1) {
			cout << "Finite\n";
		}
		else {
			cout << "Infinite\n";
		}
	}
	return 0;
}
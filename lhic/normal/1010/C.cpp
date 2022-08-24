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

int n, k;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	ll cur = k;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		x %= k;
		cur = gcd(cur, x);
	}
	cout << k / cur << "\n";
	for (int i = 0; i < k; i += cur)
		cout << i << " ";
	cout << "\n";
	return 0;
}
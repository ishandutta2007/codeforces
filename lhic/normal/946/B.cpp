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
typedef long long llong;
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

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	ll a, b;
	cin >> a >> b;
	while (true) {
		if (a == 0 || b == 0)
			break;
		else if (a >= 2 * b) {
			a %= 2 * b;
		}
		else if (b >= 2 * a) {
			b %= 2 * a;
		}
		else {
			break;
		}
	}
	cout << a << " " << b << "\n";
	return 0;
}
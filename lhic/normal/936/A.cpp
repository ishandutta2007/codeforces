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

ll k, d, t;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> k >> d >> t;
	d = ((k + d - 1) / d) * d;
	t *= 2;
	ld ans = t / (d + k) * d;
	t %= (d + k);
	if (t <= 2 * k) {
		ans += t / 2.0;
	}
	else {
		t -= 2 * k;
		ans += k;
		ans += t;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << ans << "\n";
	return 0;
}
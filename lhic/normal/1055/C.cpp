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

ll la, ra, ma;
ll lb, rb, mb;

ll get(ll la, ll ra, ll ma, ll lb, ll rb, ll mb) {
	ll g = gcd(ma, mb);
	ll r = la % g;
	ll st = (lb / g) * g + r;
	if (st < lb)
		st += g;
	if (st > rb)
		return 0;
	return min(rb - st + 1, ra - la + 1);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> la >> ra >> ma;
	cin >> lb >> rb >> mb;
	ll ans = 0;
	ans = max(get(la, ra, ma, lb, rb, mb), get(lb, rb, mb, la, ra, ma));
	cout << ans << "\n";
	return 0;
}
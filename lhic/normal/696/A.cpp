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

map<ll, ll> mm;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t;
		ll a, b;
		cin >> t >> a >> b;
		if (t == 1) {
			ll w;
			cin >> w;
			set<ll> ss;
			while (a != 1) {
				ss.insert(a);
				mm[a] += w;
				a >>= 1;
			}
			while (b != 1) {
				if (ss.count(b))
					mm[b] -= w;
				else
					mm[b] += w;
				b >>= 1;
			}
		}
		else {
			ll ans = 0;
			set<ll> ss;
			while (a != 1) {
				ss.insert(a);
				ans += mm[a];
				a >>= 1;
			}
			while (b != 1) {
				if (ss.count(b))
					ans -= mm[b];
				else
					ans += mm[b];
				b >>= 1;
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
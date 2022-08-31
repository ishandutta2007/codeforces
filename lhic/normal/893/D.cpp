#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()

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

void no() {
	cout << -1 << "\n";
	exit(0);
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	ll d;
	cin >> n >> d;
	ll av = 0;
	int ans = 0;
	ll cur = 0;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		if (x == 0) {
			if (cur < 0) {
				ll go = min(-cur, av);
				av -= go;
				cur += go;
				if (cur < 0) {
					++ans;
					cur = 0;
					av = d;
				}
			}
		}
		else {
			cur += x;
			if (cur > d)
				no();
			av = min(av, d - cur);
		}
	}
	cout << ans << "\n";
	return 0;
}
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

ll a[220000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	ll s = 0;
	for (int i = 0; i < n; ++i)
		cin >> a[i], s += a[i];
	ll c = 0;
	for (int i = 0; i < n; ++i) {
		c += a[i];
		if (2 * c >= s) {
			cout << i + 1 << "\n";
			return 0;
		}
	}
	return 0;
}
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

int p[120000];
int h[120000];
int cc[120000];


int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int n;
	cin >> n;
	for (int i = 1; i < n; ++i)
		cin >> p[i], --p[i];
	h[0] = 0;
	for (int i = 1; i < n; ++i) {
		h[i] = h[p[i]] + 1;
		++cc[h[i]];
	}
	int ans = 1;
	for (int i = 0; i <= n; ++i) {
		ans += cc[i] % 2;
	}
	cout << ans << "\n";
	return 0;
}
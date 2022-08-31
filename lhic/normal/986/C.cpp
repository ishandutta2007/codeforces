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

int msk;
int n, m;
int fl[1 << 22];
int was[1 << 22];

void dfs1(int v, int c) {
	if (c == 0) {
		fl[v] = 0;
		if (!was[msk - v])
			dfs1(msk - v, 1);
	}
	else {
		was[v] = 1;
		if (fl[v])
			dfs1(v, 0);
		for (int i = 0; i < n; ++i) {
			int x = v & (msk - (1 << i));
			if (!was[x])
				dfs1(x, 1);
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	msk = (1 << n) - 1;
	for (int i = 0; i < m; ++i) {
		int x;
		cin >> x;
		fl[x] = 1;
	}
	int ans = 0;
	for (int i = 0; i < (1 << 22); ++i) {
		if (fl[i]) {
			dfs1(i, 0), ++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
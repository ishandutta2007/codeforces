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

int n, k;
int a[120000];
int cc[120000];
int rb[120000];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i], --a[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] == -1) {
			cc[i] = 1 + min(k, n - i - 1) + min(k, i);
			rb[i] = min(n - 1, i + k);
		}
		else {
			int x = a[i];
			cc[i] = cc[x];
			int rnow = rb[x];
			int l = max(rnow + 1, i - k);
			int r = min(n - 1, i + k);
			cc[i] += r - l + 1;
			rb[i] = r;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << cc[i] << " ";
	}
	cout << "\n";
	return 0;
}
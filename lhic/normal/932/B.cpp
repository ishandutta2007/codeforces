#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

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
const int MX = 1e6 + 100;

int go[MX];
int pr[10][MX];

int f(int x) {
	ll ans = 1;
	while (x) {
		if (x % 10 != 0) {
			ans *= (x % 10);
		}
		x /= 10;
	}
	return ans;
}

int main() {
	for (int i = 1; i < MX; ++i) {
		if (i < 10)
			go[i] = i;
		else {
			go[i] = go[f(i)];
		}
	}
	for (int i = 1; i <= 9; ++i) {
		for (int j = 1; j < MX; ++j)
			pr[i][j] = pr[i][j - 1] + (go[j - 1] == i);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", pr[k][r + 1] - pr[k][l]);
	}
	return 0;
}
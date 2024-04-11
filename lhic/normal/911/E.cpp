#ifndef LOCAL
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

int a[220000];
int n, k;

void ex() {
	cout << -1 << "\n";
	exit(0);
}

void run(int l, int r, int lc, int rc) {
	if (l >= r)
		return;
	int x = a[l];
	if (x == -1) {
		for (int i = l; i < r; ++i)
			a[i] = rc - 1 - (i - l);
		return;
	}
	if (x < lc || x >= rc)
		ex();
	int lb = l + 1;
	int rb = lb + (x - lc);
	run(lb, rb, lc, x);
	run(rb, r, x + 1, rc);
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < k; ++i)
		scanf("%d", a + i), --a[i];
	for (int i = k; i < n; ++i)
		a[i] = -1;
	run(0, n, 0, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i] + 1);
	printf("\n");
	return 0;
}
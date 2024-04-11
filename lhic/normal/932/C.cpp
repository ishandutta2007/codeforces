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


int n, a, b;

int main() {
	cin >> n >> a >> b;
	for (int x = 0; x * a <= n; ++x) {
		int lf = n - x * a;
		if (lf % b != 0)
			continue;
		int y = lf / b;
		for (int i = 0; i < x; ++i) {
			int l = i * a;
			int r = (i + 1) * a;
			for (int j = l; j < r - 1; ++j) {
				printf("%d ", j + 2);
			}
			printf("%d ", l + 1);
		}
		for (int i = 0; i < y; ++i) {
			int l = x * a + i * b;
			int r = x * a + (i + 1) * b;
			for (int j = l; j < r - 1; ++j) {
				printf("%d ", j + 2);
			}
			printf("%d ", l + 1);
		}
		printf("\n");
		return 0;
	}
	printf("-1\n");
	return 0;
}
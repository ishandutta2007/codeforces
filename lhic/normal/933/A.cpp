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

int n;
int a[2200];
int c[2][2200];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i], --a[i];
	for (int i = 0; i < n; ++i) {
		c[0][i + 1] = c[0][i];
		c[1][i + 1] = c[1][i];
		++c[a[i]][i + 1];
	}
	int ans = max(c[0][n], c[1][n]);
	for (int i = 0; i < n; ++i) {
		int x = 0, y = 0;
		for (int j = i; j < n; ++j) {
			if (a[j] == 1) {
				++x;
			}
			else {
				y = max(y + 1, x + 1);
			}
			ans = max(ans, c[0][i] + max(x, y) + c[1][n] - c[1][j + 1]);
		}
	}
	cout << ans << "\n";
	return 0;
}
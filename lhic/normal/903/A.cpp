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

int main() {
	int tt;
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		int x;
		cin >> x;
		int fl = 0;
		for (int a = 0; a < 100 && !fl; ++a)
			for (int b = 0; b < 100 && !fl; ++b) {
				if (3 * a + 7 * b == x) {
					cout << "YES\n";
					fl = 1;
					break;
				}
			}
		if (!fl) {
			cout << "NO\n";
		}
	}
	return 0;
}
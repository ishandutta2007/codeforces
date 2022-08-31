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

ll k[3];

int main() {
	for (int i = 0; i < 3; ++i)
		cin >> k[i];
	sort(k, k + 3);
	ll ml = k[0] * k[1] * k[2];
	ll go = k[0] * k[1] + k[1] * k[2] + k[0] * k[2];
	if (go < ml || (k[0] == 2 && k[1] == 3)) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}
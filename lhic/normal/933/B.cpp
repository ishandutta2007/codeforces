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

ll p;
ll k;

ll a[1000];

int main() {
	cin >> p >> k;
	ll q = p;
	for (int i = 0; i <= 100; ++i) {
		if (i % 2 == 0)
			a[i] = q % k, q -= a[i];
		else
			a[i] = (k - q % k) % k, q += a[i];
		q /= k;
	}
	int cc = 100;
	while (a[cc] == 0)
		--cc;
	cout << cc + 1 << "\n";
	for (int i = 0; i <= cc; ++i)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}
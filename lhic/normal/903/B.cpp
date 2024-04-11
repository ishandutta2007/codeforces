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
	int h1, a1, c1, a2, h2;
	cin >> h1 >> a1 >> c1 >> h2 >> a2;
	int cnt = (h2 + a1 - 1) / a1;
	int cc = 0;
	while (h1 <= a2 * (cnt - 1)) {
		++cc;
		h1 += c1 - a2;
	}
	cout << cc + cnt << "\n";
	for (int i = 0; i < cc; ++i)
		cout << "HEAL\n";
	for (int i = 0; i < cnt; ++i)
		cout << "STRIKE\n";
	return 0;
}
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

int n, m;
int a[12000];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int cur = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j])
				cur ^= 1;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		l = r - l + 1;
		ll go = ll(l) * (l - 1) / 2;
		go %= 2;
		if (go)
			cur ^= 1;
		if (cur)
			cout << "odd\n";
		else
			cout << "even\n";
	}
	return 0;
}
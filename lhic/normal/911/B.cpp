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
	int n, a, b;
	cin >> n >> a >> b;
	int x = 1;
	while ((a / x) + (b / x) >= n && a >= x && b >= x)
		++x;
	cout << x - 1 << "\n";
	return 0;
}
#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

ll n, m;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	if (n == 1 || m == 1) {
		n = max(n, m);
		ll ans = n / 6 * 3;
		n %= 6;
		if (n == 4)
			ans += 1;
		if (n == 5)
			ans += 2;
		cout << ans * 2 << "\n";
		return 0;
	}
	if (n % 4 == 0 || m % 4 == 0) {
		cout << n * m / 2 * 2 << "\n";
		return 0;
	}
	if (n == 2 && m == 2) {
		cout << 0 << "\n";
		return 0;
	}
	if (n % 2 == 0 && m % 2 == 0) {
		cout << n * m / 2 * 2 << "\n";
		return 0;
	}
	if (min(n, m) == 2) {
		if (n < m)
			swap(n, m);
		if (n == 3 || n == 7)
			cout << (n * m / 2 - 1) * 2 << "\n";
		else
			cout << n * m / 2 * 2 << "\n";
		return 0;
	}
	if (n % 2 == 0 || m % 2 == 0) {
		cout << n * m / 2 * 2 << "\n";
		return 0;
	}
	cout << n * m / 2 * 2 << "\n";
	return 0;
}
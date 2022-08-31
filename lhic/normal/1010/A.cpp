#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

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

int n, m;

int a[1200], b[1200];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	for (int i = 0; i < n; ++i) {
		if (a[i] == 1 || b[i] == 1) {
			cout << -1 << "\n";
			return 0;
		}
	}
	ld l = 0;
	ld r = 1e9 + 100;
	b[n] = b[0];
	for (int it = 0; it < 100; ++it) {
		ld mid = (l + r) / 2;
		ld cur = mid;
		for (int i = 0; i < n; ++i) {
			ld nd = (m + cur) / a[i];
			cur -= nd;
			if (cur < 0)
				break;
			nd = (m + cur) / b[i + 1];
			cur -= nd;
			if (cur < 0)
				break;
		}
		if (cur < 0)
			l = mid;
		else
			r = mid;
	}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << r << "\n";
	return 0;
}
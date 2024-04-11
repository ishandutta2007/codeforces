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

const int MAXN = 200000;

int n;
ll a[MAXN];
ll b[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int sh = -1;
	ll mx = *max_element(a, a + n);
	if (mx == 0) {
		cout << "YES\n";
		for (int i = 0; i < n; ++i) {
			cout << 1 << " ";
		}
		cout << "\n";
		return 0;
	}
	if (a[0] == mx && a[n - 1] < a[0]) {
		rotate(a, a + 1, a + n);
		sh = 1;
	}
	else {
		for (int i = 0; i < n - 1; ++i) {
			if (a[i + 1] == mx && a[i] < a[i + 1]) {
				if (i + 1 != n - 1) {
					rotate(a, a + i + 1 + 1, a + n);
				}
				sh = i + 1 + 1;
				break;
			}
		}
		if (sh == -1) {
			cout << "NO\n";
			return 0;
		}
	}
	b[n - 1] = a[n - 1];
	b[n - 2] = 2 * a[n - 1] + a[n - 2];
	for (int i = n - 3; i >= 0; --i) {
		b[i] = a[i] + b[i + 1];
	}
	int x = n - sh;
	if (x == n)
		x = 0;
	rotate(b, b + x, b + n);
	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << b[i] << " ";
	cout << "\n";
	return 0;
}
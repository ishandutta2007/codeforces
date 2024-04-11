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

const int MAXN = 120000;

int n;
ll l[MAXN];

string s;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> l[i];
	cin >> s;
	ll a = 0;
	ll b = 0;
	ll ans = 0;
	for (int i = 0; i < n; ++i)
		ans += l[i];
	int fl = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'G') {
			ll go = min(l[i], a);
			ans += go;
			a -= go;
			l[i] -= go;
			b += 2 * go;
			if (l[i]) {
				ans += 2 * l[i];
				b += l[i];
			}
		}
		else if (s[i] == 'W') {
			fl = 1;
			ans += l[i];
			a += l[i];
		}
		else {
			ll go = min(a, l[i]);
			ans += go;
			a -= go;
			l[i] -= go;
			if (l[i]) {
				go = min(b, l[i]);
				b -= go;
				ans += 2 * go;
				l[i] -= go;
				if (l[i]) {
					if (fl)
						ans += 3 * l[i];
					else
						ans += 5 * l[i];
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
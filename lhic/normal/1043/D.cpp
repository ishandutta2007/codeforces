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
int n, m;

int a[12][MAXN];
int pl[12][MAXN];
int pos[12];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j], --a[i][j], pl[i][a[i][j]] = j;
	ll ans = 0;
	int st = 0;
	while (st < n) {
		int x = a[0][st];
		for (int i = 0; i < m; ++i)
			pos[i] = pl[i][x];
		int len = 1;
		while (true) {
			if (st + len == n)
				break;
			int x = a[0][st + len];
			int fl = 0;
			for (int i = 0; i < m; ++i)
				if (pos[i] + len == n || a[i][pos[i] + len] != x) {
					fl = 1;
					break;
				}
			if (fl)
				break;
			++len;
		}
		ans += ll(len) * ll(len + 1) / 2;
		st += len;
	}
	cout << ans << "\n";
	return 0;
}
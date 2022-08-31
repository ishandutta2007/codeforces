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

ll a[MAXN];
int b[MAXN];

int n, m;

ll l;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> m >> l;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		b[i] = (a[i] > l);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (b[i] && !b[i + 1])
			++cnt;
	}
	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << cnt << "\n";
		}
		else {
			int p, d;
			cin >> p >> d;
			--p;
			a[p] += d;
			if (a[p] - d <= l && a[p] > l) {
				b[p] = 1;
				if (p > 0 && b[p - 1])
					--cnt;
				if (!b[p + 1])
					++cnt;
			}
		}
	}
	return 0;
}
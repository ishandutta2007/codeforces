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

const int MAXN = 410000;
const int LOG = 20;

int cc;

int p[MAXN];
ll w[MAXN];
int pr[MAXN][LOG];
ll ww[MAXN][LOG];

int main() {
	int q;
	scanf("%d", &q);
	w[0] = 0;
	p[0] = -1;
	for (int i = 0; i < LOG; ++i)
		pr[0][i] = -1;
	cc = 1;
	ll lst = 0;
	for (int i = 0; i < q; ++i) {
		int t;
		ll r;
		ll x;
		scanf("%d%lld%lld", &t, &r, &x);
		r ^= lst;
		x ^= lst;
		--r;
		if (t == 1) {
			int v = cc++;
			w[v] = x;
			p[v] = r;
			int cur = r;
			if (w[cur] >= w[v]) {
				pr[v][0] = cur;
			}
			else {
				for (int i = LOG - 1; i >= 0; --i) {
					if (pr[cur][i] != -1 && w[pr[cur][i]] < w[v])
						cur = pr[cur][i];
				}
				pr[v][0] = pr[cur][0];
			}
			ww[v][0] = w[v];
			for (int i = 1; i < LOG; ++i) {
				if (pr[v][i - 1] == -1) {
					pr[v][i] = -1;
				}
				else {
					pr[v][i] = pr[pr[v][i - 1]][i - 1];
					if (pr[v][i] != -1) {
						ww[v][i] = ww[v][i - 1] + ww[pr[v][i - 1]][i - 1];
					}
				}
			}
		}
		else {
			int cl = 0;
			for (int i = LOG - 1; i >= 0; --i) {
				if (pr[r][i] != -1 && ww[r][i] <= x) {
					x -= ww[r][i], cl += (1 << i);
					r = pr[r][i];
				}
			}
			while (r != -1 && x >= w[r]) {
				++cl;
				x -= w[r];
				r = pr[r][0];
			}
			lst = cl;
			printf("%d\n", cl);
		}
	}
	return 0;
}
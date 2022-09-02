#include <bits/stdc++.h>
using namespace std;

#define Fi first
#define Se second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<(n);i++)
typedef tuple<int, int, int> t3;

int n, k;
int T[1<<20];
int res[19][2][1<<19];

void solve() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<=n;i++) {
		int x; scanf("%d", &x);
		int v = (1<<k) + x;
		while(v) T[v]++, v >>= 1;
	}
	rep(i, 19) rep(k, 2) rep(j, 1<<19) res[i][k][j] = 1e9;
	for(int rt=1;rt<(1<<k);rt++) {
		int lc = rt * 2, rc = lc + 1;
		if(T[lc] == 0 || T[rc] == 0) continue;
		int dep = 31 - __builtin_clz(rt);
		int rst = k - 1 - dep;
		rep(i, 1<<rst) {
			auto gc = [&](int r, int targ) {
				int res = 0;
				for(int j = rst-1; j >= 0; j--) {
					int ch = (targ >> j) & 1;
					if(T[r * 2 + ch]) r = r * 2 + ch;
					else {
						r = r * 2 + !ch;
						res |= 1<<j;
					}
				}
				return res;
			};
			int l_val = gc(lc, (1<<rst) - 1 - i), r_val = gc(rc, i);
			res[dep][0][i] = min(res[dep][0][i], l_val + r_val + 1);;
			l_val = gc(lc, i), r_val = gc(rc, (1<<rst) - 1 - i);
			res[dep][1][i] = min(res[dep][1][i], l_val + r_val + 1);
		}
	}
	for(int x=0;x<1<<k;x++) {
		int ans = 1e9;
		for(int i=0;i<k;i++) {
			int b = x & ((1<<i) - 1);
			ans = min(ans, res[k-1-i][(x>>i)&1][b]);
		}
		printf("%d ", ans);
	} puts("");
}

int main() {
	int TC = 1; //scanf("%d", &TC);
	rep(tt, TC) {
		solve();
	}
	return 0;
}
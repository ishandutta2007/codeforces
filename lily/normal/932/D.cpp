/* Heroes Never Die. */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <class T> inline void read(T &_a) {
	bool _f = 0; int _c = 0; _a = 0;
	while (_c < '0' || _c > '9') _f |= _c == '-', _c = getchar();
	while (_c >= '0' && _c <= '9') _a = _a * 10 + _c - '0', _c = getchar();
	if (_f) _a = -_a;
}

#define MAXN 400005
#define LOG 20


int n = 1, Q;
LL w[MAXN], maxw[MAXN][LOG], sum[MAXN][LOG];

int to[MAXN][LOG], fa[MAXN][LOG], cnt[MAXN][LOG];

int getto(int x, LL W) {
	for (int i = LOG - 1; ~i; i--) {
		if (maxw[x][i] < W) x = fa[x][i];
	}
	if (w[x] < W) return fa[x][0];
	else return x;
}

int main() {
	read(Q);
	int ans = 0;
	for (int i = 0; i < LOG; i++) cnt[1][i] = 1;
	while (Q--) {
		int o; LL p, q;
		read(o); read(p); read(q);
		LL r = p ^ ans, x = q ^ ans;
		if (o == 1) {
			n++;
			fa[n][0] = r;
			w[n] = x;
			maxw[n][0] = w[n];
			for (int i = 1; i < LOG; i++) {
				fa[n][i] = fa[fa[n][i - 1]][i - 1];
				maxw[n][i] = max(maxw[n][i - 1], maxw[fa[n][i - 1]][i - 1]);  
			}
			to[n][0] = getto(fa[n][0], w[n]);
			sum[n][0] = x; cnt[n][0] = 1;
			for (int i = 1; i < LOG; i++) {
				to[n][i] = to[to[n][i - 1]][i - 1];
				sum[n][i] = sum[n][i - 1] + sum[to[n][i - 1]][i - 1];
				cnt[n][i] = cnt[n][i - 1] + cnt[to[n][i - 1]][i - 1];
			}
		}
		else {
			ans = 0;
			for (int i = LOG - 1; ~i; i--) {
				if (sum[r][i] <= x) {
					x -= sum[r][i], ans += cnt[r][i], r = to[r][i];
				}
			}
			if (sum[r][0] <= x) ans += cnt[r][0];
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}
 
inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}
 
inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}
 
inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}
 
inline int mul(int x, int y) { return 1ull * x * y % md; }
 
inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

ll b[55], xay[55];
int ans[55], id[55], cnt[55][55];
int n, m, k, tot = -1;

inline ll popc(ll x) { return __builtin_popcountll(x); }

ll qwq[55];
void dfs1(int u, ll now) {
	if (u == k + 1) {
		++ans[popc(now)];
		return;
	}
	dfs1(u + 1, now);
	dfs1(u + 1, now ^ qwq[u]);
}

void dfs2(int u, int choose, ll now) {
	if (u == tot + 1) {
		++cnt[choose][popc(now)];
		return;
	}
	dfs2(u + 1, choose, now);
	dfs2(u + 1, choose + 1, now ^ xay[u]);
}

int main() {
	read(n); read(m);
	for (int i = 1; i <= n; i++) {
		ll x; read(x);
		for (int j = m - 1; j >= 0; j--) {
			if ((x >> j) & 1) {
				if (!b[j]) {
					b[j] = x;
					break;
				}
				x ^= b[j];
			}
		}
	}
	for (int i = 0; i < m; i++) k += (b[i] > 0);
	if (k <= 26) {
		k = 0;
		for (int i = 0; i < m; i++) {
			if (b[i]) {
				qwq[++k] = b[i];
			}
		}
		dfs1(1, 0);
		int coef = fpow(2, n - k);
		for (int i = 0; i <= m; i++) print(mul(ans[i], coef), i == m ? '\n' : ' ');
	} else {
		for (int i = m - 1; i >= 0; i--) {
			if (!b[i]) {
				id[i] = ++tot;
				continue;
			}
			for (int j = i - 1; j >= 0; j--) {
				if (!b[j]) continue;
				if ((b[i] >> j) & 1) b[i] ^= b[j];
			}
		}
		k = 0;
		for (int i = 0; i < m; i++) {
			if (b[i]) {
				int x = 0;
				for (int j = 0; j < m; j++) {
					if (b[j]) continue;
					if ((b[i] >> j) & 1) x |= (1 << id[j]);
				}
				qwq[++k] = x;
			}
		}
		for (int i = 0; i <= tot; i++) {
			for (int j = 1; j <= k; j++) {
				if ((qwq[j] >> i) & 1) xay[i] |= (1ll << j);
			}
		}
		static int C[55][55], tr[55][55];
		for (int i = 0; i < 55; i++) {
			C[i][0] = 1;
			for (int j = 1; j <= i; j++) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
		}
		for (int i = 0; i <= tot + 1; i++) {
			for (int j = 0; j <= tot + 1; j++) {
				for (int t = 0; t <= min(i, j); t++) {
					int res = mul(C[i][t], C[tot + 1 - i][j - t]);
					if (t & 1) tr[i][j] = sub(tr[i][j], res);
					else tr[i][j] = add(tr[i][j], res);
				}
			}
		}
		dfs2(0, 0, 0);
		for (int i = 0; i <= tot + 1; i++) {
			for (int j = 0; j <= k; j++) {
				// j : -1, k - j : 1
				for (int x = 0; x <= j; x++) {
					for (int y = 0; y <= k - j; y++) {
						for (int t = 0; t <= tot + 1; t++) {
							int res = mul(mul(cnt[i][j], tr[i][t]), mul(C[j][x], C[k - j][y]));
							// if (res) fprintf(stderr, "i = %d, j = %d, x = %d, y = %d, t = %d, res = %d\n", i, j, x, y, t, res);
							if (x & 1) ans[t + x + y] = sub(ans[t + x + y], res);
							else ans[t + x + y] = add(ans[t + x + y], res);
						}
					}
				}
			}
		}
		int coef = mul(fpow(2, n - k), fpow((md + 1) / 2, tot + 1));
		for (int i = 0; i <= m; i++) print(mul(ans[i], coef), i == m ? '\n' : ' ');
	}
    return 0;
}
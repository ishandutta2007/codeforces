#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
	if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
	if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
	char c;
	while (isspace(gc))
		;
	return c;
}
int read() {
	char c;
	while (gc < '-')
		;
	if (c == '-') {
		int x = gc - '0';
		while (gc >= '0') x = x * 10 + c - '0';
		return -x;
	}
	int x = c - '0';
	while (gc >= '0') x = x * 10 + c - '0';
	return x;
}
#undef gc

const int md = 998244353;

int add(int x, int y) {
	if (x + y >= md) return x + y - md;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + md;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % md; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

const int N = 13;

int dp[N][N][N][N], sum[N][N][N], f[N][N][N], g[N][N * 2][N][N], fac[N], inv[N];
int T, n, k, x;

inline void upd(int& x, int y) { x = add(x, y); }

inline int C(int n, int m) {
	if (n < m || m < 0) return 0;
	int ans = 1;
	for (int i = 1; i <= m; i++) ans = mul(ans, n - i + 1);
	return mul(ans, inv[m]);
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= 11; i++) {
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(inv[i - 1], fpow(i, md - 2));
	}
	dp[1][0][0][1] = 1;
	for (int i = 1; i <= 11; i++) {
		for (int j = 0; j <= 11; j++) {
			for (int k = 0; k < i; k++) {
				for (int t = 1; t <= i; t++) {
					for (int o = 1; o <= i + 1; o++) {
						if (j + o - 1 <= 11) upd(dp[i + 1][j + o - 1][k + (o > t)][o], dp[i][j][k][t]);
					}
				}
			}
		}
	}
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j <= 11; j++) {
			for (int k = 0; k < i; k++) {
				for (int t = 1; t <= i; t++) {
					upd(sum[i][j][k], dp[i][j][k][t]);
				}
			}
		}
	}
	f[0][0][0] = sum[0][0][0] = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 0; j <= 11; j++) {
			for (int k = 0; k < i; k++) {
				f[i][j][k] = sum[i][j][k];
				for (int t = 1; t < i; t++) {
					for (int x = 0; x <= j; x++) {
						for (int y = 0; y <= k; y++) {
							f[i][j][k] = sub(f[i][j][k], mul(f[t][x][y], sum[i - t][j - x][k - y]));
						}
					}
				}
				// if (f[i][j][k]) fprintf(stderr, "f[%d][%d][%d] = %d\n", i, j, k, f[i][j][k]);
			}
		}
	}
	f[1][0][0] = 0;
	g[0][0][0][0] = 1;
	for (int len = 1; len <= 12; len++) {
		for (int v1 = 0; v1 <= 11; v1++) {
			for (int v2 = 0; v2 <= 11; v2++) {
				if (!f[len][v1][v2]) continue;
				for (int i = 11; i >= 0; i--) {
					for (int j = 22; j >= 0; j--) {
						for (int k = 11; k >= 0; k--) {
							for (int t = 11; t >= 0; t--) {
								if (!g[i][j][k][t]) continue;
								for (int r = 1, pw = f[len][v1][v2];; r++, pw = mul(pw, f[len][v1][v2])) {
									if (i + r > 11 || j + len * r > 22 || k + v1 * r > 11 || t + v2 * r > 11) break;
									// if (i + r == 3 && j + len * r == 6 && k + v1 * r == 3 && t + v2 * r == 3) fprintf(stderr, "%d %d %d %d %d %d %d %d\n", len, v1, v2, r, i, j, k, t);
									upd(g[i + r][j + len * r][k + v1 * r][t + v2 * r], mul(g[i][j][k][t], mul(pw, inv[r])));
								}
							}
						}
					}
				}
			}
		}
	}
	T = read();
	while (T--) {
		n = read();
		k = read();
		x = read();
		int ans = 0;
		for (int i = 0; i <= 11; i++) {
			for (int j = 0; j <= 22; j++) {
				if (!g[i][j][k][x]) continue;
				ans = add(ans, mul(mul(g[i][j][k][x], fac[i]), C(n - (j - i), i)));
			}
		}
		printf("%d\n", ans);
	}
}
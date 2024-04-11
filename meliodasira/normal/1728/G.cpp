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

const int P = 998244353;

int add(int x, int y) {
	if (x + y >= P) return x + y - P;
	return x + y;
}

int sub(int x, int y) {
	if (x < y) return x - y + P;
	return x - y;
}

int mul(int x, int y) { return 1ull * x * y % P; }

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		y >>= 1;
		x = mul(x, x);
	}
	return ans;
}

inline void upd(int& x, int y) { x = add(x, y); }

const int N = 3e5 + 5;

int ans[N], p[N], a[25], c[25][25], v[25][25];
int d, n, m, q;

int getpos(int x) {
	int ans = 0;
	while (ans < m && a[ans + 1] <= x) ++ans;
	return ans;
}

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	d = read();
	n = read();
	m = read();
	for (int i = 1; i <= n; i++) p[i] = read();
	for (int i = 1; i <= m; i++) a[i] = read();
	sort(a + 1, a + m + 1);
	for (int l = 0; l <= m + 1; l++) {
		for (int r = l; r <= m + 1; r++) c[l][r] = 1;
	}
	for (int i = 1; i <= n; i++) {
		int pos = getpos(p[i]);
		for (int l = 0; l <= pos; l++) {
			for (int r = pos + 1; r <= m + 1; r++) {
				int lim = d + 1;
				if (l != 0) lim = min(lim, p[i] - a[l]);
				if (r != m + 1) lim = min(lim, a[r] - p[i]);
				c[l][r] = mul(c[l][r], lim);
				// fprintf(stderr, "c[%d][%d] = %d, lim = %d\n", l, r, c[l][r], lim);
			}
		}
	}
	for (int i = 0; i < (1 << m); i++) {
		int now = 1, las = 0;
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				now = mul(now, c[las][j + 1]);
				las = j + 1;
			}
		}
		now = mul(now, c[las][m + 1]);
		las = 0;
		if (__builtin_popcount(i) & 1) now = sub(0, now);
		for (int j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				upd(v[las][j + 1], now);
				las = j + 1;
			}
		}
		upd(v[las][m + 1], now);
	}
	for (int x = 1; x <= d - 1; x++) {
		int pos = getpos(x);
		for (int l = 0; l <= pos; l++) {
			for (int r = pos + 1; r <= m + 1; r++) {
				int lim = d + 1;
				if (l != 0) lim = min(lim, x - a[l]);
				if (r != m + 1) lim = min(lim, a[r] - x);
				upd(ans[x], mul(lim, v[l][r]));
			}
		}
	}
	q = read();
	while (q--) {
		int x = read();
		printf("%d\n", ans[x]);
	}
}
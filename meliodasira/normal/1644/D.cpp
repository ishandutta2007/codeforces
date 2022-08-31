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

const int N = 2e5 + 5;

int x[N], y[N], vx[N], vy[N];
int T, n, m, k, q, cntx, cnty, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		m = read();
		k = read();
		q = read();
		for (int i = 1; i <= q; i++) x[i] = read(), y[i] = read();
		ans = 1;
		for (int i = q; i >= 1; i--) {
			int cando = 1;
			if (vx[x[i]] && vy[y[i]]) cando = 0;
			if (cntx == n || cnty == m) cando = 0;
			if (cando) ans = mul(ans, k);
			if (!vx[x[i]]) vx[x[i]] = 1, ++cntx;
			if (!vy[y[i]]) vy[y[i]] = 1, ++cnty;
		}
		for (int i = 1; i <= q; i++) vx[x[i]] = vy[y[i]] = 0;
		cntx = cnty = 0;
		printf("%d\n", ans);
	}
}
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

const int N = 2005;

int s2[N][N], inv[N];
int T, n, m, k, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	s2[0][0] = 1;
	rep(i, 1, 2000) {
		inv[i] = fpow(i, P - 2);
		rep(j, 1, i) s2[i][j] = add(s2[i - 1][j - 1], mul(s2[i - 1][j], j));
	}
	T = read();
	while (T--) {
		n = read();
		m = read();
		k = read();
		ans = 0;
		int coef = fpow(m, n), invm = fpow(m, P - 2);
		rep(i, 1, min(n, k)) {
			coef = mul(coef, n - i + 1);
			coef = mul(coef, (m + 1) / 2);
			coef = mul(coef, invm);
			ans = add(ans, mul(coef, s2[k][i]));
		}
		printf("%d\n", ans);
	}
}
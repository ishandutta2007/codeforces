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

const int N = 2e5 + 5;

int a[2][N], v[2][N];
int T, n, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	T = read();
	while (T--) {
		n = read();
		ans = 2e9;
		rep(i, 0, 1) rep(j, 1, n) a[i][j] = read();
		a[0][1] = -1;
		v[0][n] = max(a[0][n] + 2, a[1][n] + 1);
		v[1][n] = max(a[1][n] + 2, a[0][n] + 1);
		per(i, n - 1, 1) {
			v[0][i] = max(v[0][i + 1] + 1, max(a[1][i] + 1, a[0][i] + 2 * (n - i + 1)));
			v[1][i] = max(v[1][i + 1] + 1, max(a[0][i] + 1, a[1][i] + 2 * (n - i + 1)));
		}
		ans = min(ans, v[0][1]);
		int now = -1;
		rep(i, 1, n) {
			int cur = (i - 1) & 1;
			now = max(now, a[cur][i]) + 1;
			now = max(now, a[cur ^ 1][i]) + 1;
			if (i != n) ans = min(ans, max(now + 2 * (n - i), v[cur ^ 1][i + 1]));
		}
		ans = min(ans, now);
		printf("%d\n", ans);
	}
}
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

const int P = 1e9 + 7;

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

int a[N], b[N], f[N], s[N];
int n, m, p, ans;

int main() {
#ifdef local
	freopen("1.in", "r", stdin);
#endif
	m = read();
	p = read();
	rep(i, 1, m) b[i] = read();
	sort(b + 1, b + m + 1);
	a[1] = b[1];
	n = 1;
	rep(i, 2, m) {
		int x = b[i], ok = 1;
		while (x) {
			int pos = lower_bound(a + 1, a + n + 1, x) - a;
			if (a[pos] == x) {
				ok = 0;
				break;
			}
			if (x % 2 == 1)
				x >>= 1;
			else if (x % 4 == 0)
				x >>= 2;
			else
				break;
		}
		if (ok) a[++n] = b[i];
	}
	f[0] = f[1] = 1;
	rep(i, 2, p) f[i] = add(f[i - 1], f[i - 2]);
	s[0] = 1;
	rep(i, 1, p) s[i] = add(f[i], s[i - 1]);
	rep(i, 1, n) {
		int maxb = 0;
		while ((1 << (maxb + 1)) <= a[i]) ++maxb;
		if (maxb < p) ans = add(ans, s[p - maxb - 1]);
	}
	printf("%d\n", ans);
}
// =================================
//   author: memset0
//   date: 2019.06.01 22:36:30
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; char c = getchar(); bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline void print(T a, int l, int r, std::string s = "") {
	if (s != "") std::cout << s << ": ";
	for (int i = l; i <= r; i++) print(a[i], " \n"[i == r]);
}

const int N = 2e5 + 10;
int n, m, ta, tb, k, ans, a[N], b[N];

void main() {
	read(n), read(m), read(ta), read(tb), read(k);
	for (int i = 1; i <= n; i++) read(a[i]), a[i] += ta;
	for (int i = 1; i <= m; i++) read(b[i]);
	ans = 0;
	for (int i = 0; i <= k; i++) {
		int j = std::lower_bound(b + 1, b + m + 1, a[i + 1]) - b;
		if (i + 1 > n) {
			puts("-1");
			return;
		}
		// printf(">> %d %d\n", i, j);
		j += k - i;
		if (j > m) {
			puts("-1");
			return;
		}
		ans = std::max(ans, b[j]);
	}
	print(ans + tb, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}
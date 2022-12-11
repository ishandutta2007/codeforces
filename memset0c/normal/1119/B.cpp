// =================================
//   author: memset0
//   date: 2019.04.06 19:41:52
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
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

const int N = 1e3 + 10;
int n, m, l, r, mid, ans, a[N], b[N];

inline bool check(int x) {
	// printf("> check %d\n", x);
	for (int i = 1; i <= x; i++) b[i] = a[i];
	if (x & 1) b[++x] = 0;
	std::sort(b + 1, b + x + 1);
	// for (int i = 1; i <= x; i++) print(b[i], " \n"[i == x]);
	ll sum = 0;
	for (int i = 1; i <= x; i += 2)
		sum += std::max(b[i], b[i + 1]);
	return sum <= m;
}

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int l = 1, r = n, mid; mid = l + r >> 1, l <= r; )
		if (check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}
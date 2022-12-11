// =================================
//   author: memset0
//   date: 2019.04.06 19:36:39
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

const int N = 3e5 + 10;
int n, L, R, ans, flag, a[N];

void main() {
	read(n), flag = 1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++) flag &= a[i] == a[1];
	if (flag) { puts("0"); return; }
	L = 1, R = n;
	while (a[L + 1] == a[1] && L + 1 <= n) L++;
	while (a[R - 1] == a[n] && R - 1 >= 1) R--;
	// std::cout << L << " " << R << std::endl;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[1]) ans = std::max(ans, i - 1);
		if (a[i] == a[1]) ans = std::max(ans, i - L - 1);
		if (a[i] != a[n]) ans = std::max(ans, n - i);
		if (a[i] == a[n]) ans = std::max(ans, n - i - (n - R + 1));
		// printf("%d %d %d %d\n", i - 1, i - L - 1, n - i, n - i - R);
	}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("1.in", "r", stdin);
#endif
	return ringo::main(), 0;
}
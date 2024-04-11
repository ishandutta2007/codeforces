// =================================
//   author: memset0
//   date: 2019.05.13 14:24:39
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

const int N = 1e5 + 10;
int n, m, min = 1e9, max, sec, a[N], b[N]; ll ans;

void main() {
	read(n), read(m);
	for (int i = 1; i <= n; i++) read(a[i]), max = std::max(a[i], max);
	for (int i = 1; i <= m; i++) read(b[i]), min = std::min(b[i], min);
	if (min < max) { puts("-1"); return; }
	for (int i = 1; i <= n; i++) ans += a[i];
	ans = (ans - max) * m + max;
	for (int i = 1; i <= m; i++) ans += b[i];
	if (min == max) ans -= max;
	else {
		for (int i = 1; i <= n; i++) {
			if (a[i] == max) { max = -1; continue; }
			sec = std::max(sec, a[i]);
		} ans -= sec;
	}
	print(ans, '\n');
}

} signed main() {
#ifdef MEMSET0_LOCAL_ENVIRONMENT
	freopen("in3.txt", "r", stdin);
#endif
	return ringo::main(), 0;
}
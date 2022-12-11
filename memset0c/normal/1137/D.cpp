// =================================
//   author: memset0
//   date: 2019.03.10 19:33:53
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

int next(char *s) {
	int n; static char t[100];
	puts(s), fflush(stdout), read(n);
	for (int m = n; m--; ) scanf("%s", t);
	// std::cerr << ">> " << n << std::endl;
	return n;
}

void main() {
	while ((next("next 0"), next("next 0 1")) == 3);
	while (next("next 0 1 2 3 4 5 6 7 8 9") == 2);
	puts("done"), fflush(stdout);
}

} signed main() { return ringo::main(), 0; }
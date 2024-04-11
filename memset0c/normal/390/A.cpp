// =================================
//   author: memset0
//   date: 2019.01.28 08:24:00
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
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

const int N = 1e5 + 10, M = 110;
int n, u, v, cntx, cnty;
bool x[M], y[M];

void main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		read(u), read(v);
		x[u] = y[v] = 1;
	}
	for (int i = 0; i <= 100; i++) cntx += x[i], cnty += y[i];
	print(std::min(cntx, cnty), '\n');
}

} signed main() { return ringo::main(), 0; }
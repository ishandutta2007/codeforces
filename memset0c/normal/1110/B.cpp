// =================================
//   author: memset0
//   date: 2019.02.10 21:59:47
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

const int N = 1e5 + 10;
int n, m, k, ans;
int a[N], b[N];

void main() {
	read(n), read(m), read(k);
	for (int i = 1; i <= n; i++) read(a[i]);
	std::sort(a + 1, a + n + 1);
	ans = a[n] - a[1] + 1;
	for (int i = 1; i < n; i++) b[i] = a[i + 1] - a[i] - 1;
	std::sort(b + 1, b + n + 1, [](int a, int b) { return a > b; });
	for (int i = 1; i < std::min(n, k); i++) ans -= std::max(0, b[i]);
	print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
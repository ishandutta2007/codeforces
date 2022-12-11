// =================================
//   author: memset0
//   date: 2019.01.25 20:29:57
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

const int N = 1010;
int n, now, ans, key, a[N];

int min(int a, int b, int c) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (c < 0) c = -c;
	return std::min(a, std::min(b, c));
}

void main() {
	read(n), ans = -1;
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int m = 1; m <= 1000; m++) {
		now = 0;
		for (int i = 1; i <= n; i++)
			now += min(a[i] - m, a[i] - m + 1, a[i] - m - 1);
		if (now < ans || ans == -1) ans = now, key = m;
	}
	print(key, ' '), print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
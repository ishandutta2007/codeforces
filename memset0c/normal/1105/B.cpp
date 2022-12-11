// =================================
//   author: memset0
//   date: 2019.01.25 21:00:56
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

const int N = 2e5 + 10;
int n, m, cnt, now, ans;
char s[N];

void main() {
	read(n), read(m), scanf("%s", s + 1);
	for (int c = 'a'; c <= 'z'; c++) {
		cnt = now = 0;
		for (int i = 1; i <= n; i++)
			if (s[i] == c) ++cnt;
			else now += cnt / m, cnt = 0;
		now += cnt / m, ans = std::max(ans, now);
	} print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
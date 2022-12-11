// =================================
//   author: memset0
//   date: 2019.01.26 09:27:36
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

const int N = 150, M = 10010;
int n, x, y, gcd, flag;
int a[N], cnt[M];

void main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
    for (int i = 0; i < M; i++) if (cnt[i] == 2) gcd = i; else if (cnt[i] == 1) flag = 1;
    if (!flag) return (void)(printf("%d %d\n", gcd, gcd));
    x = y = gcd;
    for (int i = 0; i < M; i++) if (cnt[i] == 1) x = i;
    for (int i = 0; i < M; i++) if (cnt[i] == 1) {
        if (std::__gcd(x, i) == gcd) y = i;
    } printf("%d %d\n", x, y);
}

} signed main() { return ringo::main(), 0; }
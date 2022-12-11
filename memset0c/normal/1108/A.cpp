// =================================
//   author: memset0
//   date: 2019.01.26 09:20:31
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

int n, l1, l2, r1, r2;

void main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        read(l1), read(r1), read(l2), read(r2);
        if (l1 == r2) print(r1, ' '), print(l2, '\n');
        else print(l1, ' '), print(r2, '\n');
    }
}

} signed main() { return ringo::main(), 0; }
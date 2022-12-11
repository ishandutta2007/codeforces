// =================================
//   author: memset0
//   date: 2018.12.28 17:18:27
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#define pb push_back
#define rep(i, l, r) for (register int i = l; i <= r; i++)

namespace ringo {
typedef long long ll;
typedef unsigned long long ull;
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
template <class T> inline void maxd(T &a, T b) { if (b > a) a = b; }
template <class T> inline void mind(T &a, T b) { if (b < a) a = b; }
template <class T> inline void print(T x, char c) { print(x), putchar(c); }
template <class T> inline T abs(const T &a) { if (a < 0) return -a; return a; }

int s, t, p;
std::string strs, strt, strp;

void main() {
	std::cin>>strt>>strs;
    s = 600 * (strs[0] - '0') + 60 * (strs[1] - '0') + 10 * (strs[3] - '0') + strs[4] - '0';
    t = 600 * (strt[0] - '0') + 60 * (strt[1] - '0') + 10 * (strt[3] - '0') + strt[4] - '0';
    p = t - s < 0 ? t - s + 1440 : t - s;
    putchar(p / 600 + '0');
    p %= 600;
    putchar(p / 60 + '0');
    p %= 60;
    putchar(':');
    putchar(p / 10 + '0');
    p %= 10;
    putchar(p + '0');
	putchar('\n');
}

} signed main() { return ringo::main(), 0; }
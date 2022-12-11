// =================================
//   author: memset0
//   date: 2018.12.04 19:29:42
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

ll n, m, a, b, t, ans;

void main() {
    read(n), read(m), read(a), read(b);
    t = n / m * m;
    ans = std::min((n - t) * b, (t + m - n) * a);
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
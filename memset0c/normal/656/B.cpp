// =================================
//   author: memset0
//   date: 2018.12.07 10:03:51
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

const int N = 20;

int n, cnt, p[N], x[N];

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(p[i]);
    for (int i = 1; i <= n; i++) read(x[i]);
    for (int i = 0; i < 720720; i++) {
        bool flag = false;
        for (int j = 1; j <= n; j++)
            flag |= i % p[j] == x[j];
        if (flag) cnt++;
    }
    printf("%.5lf\n", cnt / (double)720720);
    return 0;
}

} signed main() { return ringo::main(), 0; }
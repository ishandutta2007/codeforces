// =================================
//   author: memset0
//   date: 2018.12.05 19:02:43
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

const int N = 1e5 + 10;
int n;
int a[N], cnt[N];

void main() {
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]), ++cnt[a[i]];
    for (int i = (int)1e5; i >= 1; i--)
        if (cnt[i] == 1) {
            puts("Conan");
            return;
        } else if ((cnt[i] & 1) == 1) {
            puts("Conan");
            return;
        }
    puts("Agasa");
}

} signed main() { return ringo::main(), 0; }
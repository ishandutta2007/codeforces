// =================================
//   author: memset0
//   date: 2018.12.06 19:09:13
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
int n, m, lst;
std::vector < int > a;

void main() {
    read(n), read(m);
    for (int i = 1, x; i <= n; i++) {
        read(x);
        a.push_back(x);
    }
    std::sort(a.begin(), a.end());
    a.push_back(0), lst = 0;
    for (int i = 1, j = 0; i <= m; i++) {
        while (j < n && lst == a[j]) j++;
        if (j == n) puts("0");
        else {
            int tmp = a[j++];
            print(tmp - lst, '\n');
            lst = tmp;
        }
    }
}

} signed main() { return ringo::main(), 0; }
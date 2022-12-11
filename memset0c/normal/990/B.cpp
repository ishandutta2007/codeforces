// =================================
//   author: memset0
//   date: 2018.12.04 19:43:57
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

const int N = 2e5 + 10, M = 1e6 + 10;
int n, m, tn, ans;
int a[N], cnt[M];

void main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    ans = n;
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        ++cnt[a[i]];
    tn = std::unique(a + 1, a + n + 1) - a - 1;
    // for (int i = 1; i <= tn; i++) print(a[i], " \n"[i == tn]);
    // for (int i = 1; i <= tn; i++) print(cnt[a[i]], " \n"[i == tn]);
    for (int i = 2; i <= tn; i++)
        if (a[i - 1] + m >= a[i])
            ans -= cnt[a[i - 1]];
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }

// a[j] < a[i] <= a[j] + k
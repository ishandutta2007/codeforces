// =================================
//   author: memset0
//   date: 2018.12.04 22:23:20
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

const int N = 1e6 + 10;
int n, m, k, x, u, lst;
int c[N], tag[N], bak[N];
ll sum, ans;

void main() {
    read(n), read(m), read(k);
    for (int i = 1; i <= m; i++)
        read(x), ++x, tag[x] = 1;
    for (int i = 1; i <= k; i++)
        read(c[i]);
    for (int i = 1; i <= n; i++)
        if (tag[i]) bak[i] = bak[i - 1];
        else bak[i] = i;
    ans = -1;
    for (int i = 1; i <= k; i++) {
        sum = lst = 0, u = 1;
        while (u <= n) {
            if (tag[u]) u = bak[u];
            if (u <= lst || !u) { sum = -1; break; }
            lst = u, u += i, sum += c[i];
            // printf("%d %d %lld\n", u - i, u, sum);
        }
        // printf("%d %d >> %lld\n", i, c[i], ans);
        if (~sum) ans = ans == -1 || sum < ans ? sum : ans;
    }
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }
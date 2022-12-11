// =================================
//   author: memset0
//   date: 2018.12.05 22:29:01
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
int n, m, k, c, l, r, p, op;
char a[N], s[N];
std::bitset < N > f[27], ans;

void main() {
    scanf("%s", a + 1), n = strlen(a + 1);
    for (int i = 1; i <= n; i++) f[a[i] - 'a'].set(i);
    read(p);
    for (int i = 1; i <= p; i++) {
        read(op);
        if (op == 1) {
            read(k), c = getchar();
            // printf("insert %d %c\n", k, c);
            f[a[k] - 'a'].reset(k);
            a[k] = c;
            f[a[k] - 'a'].set(k);
        } else {
            read(l), read(r), scanf("%s", s + 1), m = strlen(s + 1);
            ans.set();
            for (int i = 1; i <= m; i++)
                ans &= f[s[i] - 'a'] >> (i - 1);
            int s1 = (ans >> (l)).count();
            int s2 = (ans >> (r - m + 2)).count();
            print(std::max(0, s1 - s2), '\n');
            // printf(">> %d %d %d\n", ans.count(), s1, s2);
        }
    }
}

} signed main() { return ringo::main(), 0; }
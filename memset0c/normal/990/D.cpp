// =================================
//   author: memset0
//   date: 2018.12.04 20:40:56
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

const int N = 1010;
int n, a, b, p[N][N];

int solve() {
    if (n == 1 && a == 1 && b == 1) return 0;
    if ((n == 2 || n == 3) && a == 1 && b == 1) return -1;
    if (a > n || b > n) return -1;
    if (a != 1 && b != 1) return -1;
    int t = a + b - 1, s = n - t;
    // printf("%d\n", s);
    for (int i = 1; i <= s; i++)
        p[i][i + 1] = p[i + 1][i] = 1;
    return a == 1;
}

void main() {
    read(n), read(a), read(b);
    int ans = solve();
    if (ans == -1) {
        puts("NO");
    } else {
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                putchar('0' + (p[i][j] ^ (ans && i != j)));
            putchar('\n');
        }
    }
}

} signed main() { return ringo::main(), 0; }
// =================================
//   author: memset0
//   date: 2019.01.26 09:40:19
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

const int N = 2e5 + 10, mod = 1e9 + 7;
int n, l, r;
int f[N][3], a[3];
template <class T> inline void sumd(int &a, T b) { a = (a + b) % mod; }

void main() {
    read(n), read(l), read(r);
    a[0] = r / 3 - (l - 1) / 3;
    a[1] = (r + 2) / 3 - (l + 1) / 3;
    a[2] = (r + 1) / 3 - l / 3;
    // printf("%d %d %d\n", a[0], a[1], a[2]);
    for (int i = 0; i < 3; i++) f[1][i] = a[i];
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                sumd(f[i][(j + k) % 3], (ll)f[i - 1][j] * a[k]);
    // for (int i = 1; i <= n; i++) printf("%d %d %d\n", f[i][0], f[i][1], f[i][2]);
    print(f[n][0], '\n');
}

} signed main() { return ringo::main(), 0; }
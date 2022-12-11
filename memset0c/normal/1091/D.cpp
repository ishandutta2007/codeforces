// =================================
//   author: memset0
//   date: 2018.12.30 22:56:39
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
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

const int N = 1e6 + 10, p = 998244353;
int n, tmp, sum, ans;
int fac[N], inv[N];

void main() {
    read(n);
    fac[0] = fac[1] = inv[0] = inv[1] = 1;
    for (int i = 2; i <= n; i++) fac[i] = (ll)fac[i - 1] * i % p;
    for (int i = 2; i <= n; i++) inv[i] = (ll)(p - p / i) * inv[p % i] % p;
    for (int i = 2; i <= n; i++) inv[i] = (ll)inv[i - 1] * inv[i] % p;

    ans = 0;
    for (int i = 0; i <= n; i++) {
        tmp = (fac[i] - 1 + p) % p;
        sum = (ll)tmp * fac[n - i] % p * fac[n] % p * inv[i] % p * inv[n - i] % p;
        ans = (ans + sum) % p;
    }
    print((ans + 1) % p, '\n');
}

} signed main() { return ringo::main(), 0; }
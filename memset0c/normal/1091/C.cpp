// =================================
//   author: memset0
//   date: 2018.12.30 22:48:15
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
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

int n;
std::vector <long long> V;
inline long long calc(int x) {
    int k = n / x;
    long long y = 1ll * (k - 1) * k / 2;
    return y * x + k;
}

void main() {
    read(n);
    for (int i = 1; i * i <=n; i++)
        if (n % i==0)
            V.push_back(calc(i)), V.push_back(calc(n / i));
    std::sort(V.begin(), V.end());
    V.erase(std::unique(V.begin(), V.end()), V.end());
    for (size_t i = 0; i < V.size(); i++)
        printf("%I64d ",V[i]);
    putchar('\n');
}

} signed main() { return ringo::main(), 0; }
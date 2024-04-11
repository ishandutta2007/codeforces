#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 1e9 + 7;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 2e5 + 5;

int fac[N], inv[N];
int T, n, k;

inline int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = mul(fac[i - 1], i);
    inv[200000] = fpow(fac[200000], md - 2);
    for (int i = 200000; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    read(T);
    while (T--) {
        read(n); read(k);
        int ans = 2;
        for (int i = 2; i <= n; i++) {
            if ((i - 1) * k > n - 1) break;
            int m = n - 1 - (i - 1) * k;
            int cnt = C(m + i, i);
            ans = add(ans, mul(cnt, fpow(C(n, i), md - 2)));
        }
        print(ans, '\n');
    }
    return 0;
}
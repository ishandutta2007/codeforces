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

const int md = 998244353;

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

const int N = 1e7 + 5;

int xjm[N], fac[N], inv[N], pw[N];
int T, n, k, x;

int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return mul(xjm[m], inv[m]);
}

int main() {
    pw[0] = 1;
    for (int i = 1; i <= 10000000; i++) pw[i] = add(pw[i - 1], pw[i - 1]);
    fac[0] = 1;
    for (int i = 1; i <= 10000000; i++) fac[i] = mul(fac[i - 1], sub(pw[i], 1));
    inv[10000000] = fpow(fac[10000000], md - 2);
    for (int i = 10000000; i >= 1; i--) inv[i - 1] = mul(inv[i], sub(pw[i], 1));
    read(T);
    while (T--) {
        read(n); read(k); read(x);
        if (x == 0) {
            int a = fpow(2, k), b = 1, ans = 1;
            if (n > k) {
                print(0, '\n');
                continue;
            }
            for (int i = 1; i <= n; i++) {
                ans = mul(ans, sub(a, b));
                b = add(b, b);
            }
            print(ans, '\n');
        } else {
            xjm[0] = 1;
            int pp = fpow(2, n);
            for (int i = 1; i <= k; i++) {
                xjm[i] = mul(xjm[i - 1], sub(pp, 1));
                if (pp & 1) pp = (pp + md) >> 1;
                else pp >>= 1;
            }
            int ss = 1, ans = 0;
            for (int i = 0; i <= k; i++) {
                int f = mul(C(n, i), ss);
                ss = mul(ss, sub(pw[k], pw[i + 1]));
                ans = add(ans, f);
            }
            print(ans, '\n');
        }
    }
    return 0;
}
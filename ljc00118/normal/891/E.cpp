#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 5005, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int f[N], a[N];
int n, k, ans, s = 1, invn;

int main() {
    read(n); read(k); invn = fpow(n, md - 2);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        s = mul(s, a[i]);
        for (int j = i; j >= 0; j--) {
            f[j] = sub(mul(f[j], a[i]), j == 0 ? 0 : f[j - 1]);
        }
    }
    for (int i = 0, xjm = 1, pw = 1; i <= min(n, k); i++, pw = mul(pw, invn)) {
        ans = add(ans, mul(mul(xjm, pw), f[i]));
        xjm = mul(xjm, k - i);
    }
    ans = sub(s, ans);
    print(ans, '\n');
    return 0;
}
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

const int N = 2e5 + 5;

struct fenwick {
    int f[N];

    void add(int x, int y) {
        while (x <= 200000) {
            f[x] = ::add(f[x], y);
            x += (x & -x);
        }
    }

    int query(int x) {
        int ans = 0;
        while (x) {
            ans = ::add(ans, f[x]);
            x &= (x - 1);
        }
        return ans;
    }
} tr;

int a[N], b[N], fac[N], inv[N], cnt[N];
int n, m, ans, all = 1;

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N - 1] = fpow(fac[N - 1], md - 2);
    for (int i = N - 1; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
    for (int i = 1; i <= m; i++) read(b[i]);
    for (int i = 1; i <= 200000; i++) {
        all = mul(all, inv[cnt[i]]);
        if (cnt[i]) tr.add(i, mul(fac[cnt[i]], inv[cnt[i] - 1]));
    }
    int cando = 1;
    for (int i = 1; i <= min(n, m); i++) {
        ans = add(ans, mul(fac[n - i], mul(all, tr.query(b[i] - 1))));
        if (!cnt[b[i]]) {
            cando = 0;
            break;
        }
        tr.add(b[i], sub(0, mul(fac[cnt[b[i]]], inv[cnt[b[i]] - 1])));
        all = mul(all, fac[cnt[b[i]]]);
        --cnt[b[i]];
        all = mul(all, inv[cnt[b[i]]]);
        if (cnt[b[i]]) tr.add(b[i], mul(fac[cnt[b[i]]], inv[cnt[b[i]] - 1]));
    }
    if (n < m && cando) ans = add(ans, 1);
    print(ans, '\n');
    return 0;
}
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

const int N = 1e5 + 5;

ll f[N], g[N];
int a[N], cnt[N];
int n, k, nowl = 1, nowr;
ll val;

void add(int x) {
    val += cnt[x];
    ++cnt[x];
}

void del(int x) {
    --cnt[x];
    val -= cnt[x];
}

inline ll getval(int l, int r) {
    while (nowl > l) --nowl, add(a[nowl]);
    while (nowr < r) ++nowr, add(a[nowr]);
    while (nowl < l) del(a[nowl]), ++nowl;
    while (nowr > r) del(a[nowr]), --nowr;
    // fprintf(stderr, "l = %d, r = %d, val = %lld\n", l, r, val);
    return val;
}

void solve(int l, int r, int L, int R) {
    if (l > r || L > R) return;
    int mid = (l + r) >> 1, pos = L;
    if (L >= mid) {
        solve(mid + 1, r, L, R);
        return;
    }
    g[mid] = f[L] + getval(L + 1, mid);
    for (int i = L + 1; i <= min(mid - 1, R); i++) {
        ll now = f[i] + getval(i + 1, mid);
        if (now < g[mid]) g[mid] = now, pos = i;
    }
    solve(l, mid - 1, L, pos);
    solve(mid + 1, r, pos, R);
}

int main() {
    read(n); read(k); --k;
    for (int i = 1; i <= n; i++) read(a[i]);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for (int _ = 1; _ <= k; _++) {
        memset(g, 0x3f, sizeof(g));
        solve(1, n, 0, n);
        memcpy(f, g, sizeof(f));
    }
    ll ans = 1e18;
    for (int i = 0; i <= n; i++) ans = min(ans, f[i] + getval(i + 1, n));
    print(ans, '\n');
    return 0;
}
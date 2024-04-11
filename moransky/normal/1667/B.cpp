// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 5e5 + 5;

int n, len, a[N];

LL d[N], s[N], f[N], mx[N];

struct BIT{
    LL c[N];
    void inline init() {
        for (int i = 1; i <= n + 1; i++) c[i] = -1e9;
    }
    void inline add(int x, LL k) {
        for (; x <= n + 1; x += x & -x) chkMax(c[x], k);
    }
    LL inline ask(int x) {
        LL res = -1e9;
        for (; x; x -= x & -x) chkMax(res, c[x]);
        return res;
    }
} t[2];

int inline get(LL x) {
    return lower_bound(d + 1, d + 1 + n, x) - d;
}

int main() {
    int T; read(T);
    while (T--) {
    	read(n);
        t[0].init(); len = 0;
        t[1].init();
        for (int i = 1; i <= n; i++) read(a[i]), s[i] = s[i - 1] + a[i], d[++len] = s[i];
        d[++len] = 0;
        sort(d + 1, d + 1 + len);
        for (int i = 1; i <= n + 1; i++) mx[i] = -1e9;
        int u = get(s[0]);
        t[0].add(u, f[0] - 0);
        t[1].add(n - u + 2, f[0] + 0);
        mx[u] = 0;
        for (int i = 1; i <= n; i++) {
            int p = get(s[i]);
            f[i] = mx[p];
            chkMax(f[i], t[0].ask(p - 1) + i);
            chkMax(f[i], t[1].ask((n - p + 1 + 1) - 1) - i);
            t[0].add(p, f[i] - i);
            t[1].add(n - p + 1 + 1, f[i] + i);
            chkMax(mx[p], f[i]);
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
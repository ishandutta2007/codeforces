// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
typedef pair<int, int> PII;

const int N = 5e5 + 5, P = 1e9 + 7;

int n, m, k, Pow[N], ans, f[N];

LL c[N];

map<LL, vector<PII> > g;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    f[find(x)] = find(y);
}

int main() {
    read(n), read(m), read(k);
    Pow[0] = 1;
    for (int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * 2 % P;
    for (int i = 1; i <= n; i++) f[i] = i, read(c[i]);
    for (int i = 1, u, v; i <= m; i++) {
        read(u), read(v);
        g[c[u] ^ c[v]].pb(mp(u, v));
    }
    LL re = (1ll << k) - g.size();
    ans = re % P * Pow[n] % P;
    for (auto i: g) {
        vector<PII> e = i.se;
        int cnt = n;
        for (PII t: e) {
            int x = t.fi, y = t.se;
            if (find(x) != find(y)) cnt--, merge(x, y);
        }
        ans = (ans + Pow[cnt]) % P;
        for (PII t: e) {
            int x = t.fi, y = t.se;
            f[x] = x, f[y] = y;
        }
    }
    print(ans);
    return 0;
}
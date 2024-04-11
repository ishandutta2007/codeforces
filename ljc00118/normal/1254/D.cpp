#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 150005, sqr = 400, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) {
    return 1ll * x * y % md;
}

vector <int> adj[N], g[N], t[N], p;
int tag[N], tops[N], siz[N];
int n, q, dfn, invn;

inline int lowbit(int x) { return x & -x; }

int f[N];
inline void ADD(int x, int y) {
    while(x <= n) {
        f[x] = add(f[x], y);
        x += lowbit(x);
    }
}

inline int query(int x) {
    int ans = 0;
    while(x) {
        ans = add(ans, f[x]);
        x ^= lowbit(x);
    }
    return ans;
}

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int fa[N];
void dfs1(int u, int fa) {
    tops[u] = ++dfn; siz[u] = 1;
    for(register int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        ::fa[v] = u; dfs1(v, u); siz[u] += siz[v]; g[u].push_back(tops[v]); t[u].push_back(v);
    }
}

void add(int l, int r, int x) {
    if(l > r) return;
    ADD(l, x); ADD(r + 1, sub(0, x));
}

int main() {
    read(n); read(q); invn = fpow(n, md - 2);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for(register int i = 1; i <= n; i++) if((int)adj[i].size() >= sqr) p.push_back(i);
    while(q--) {
        int opt; read(opt);
        if(opt == 1) {
            int u, d;
            read(u); read(d);
            if(!d) continue;
            if((int)adj[u].size() >= sqr) tag[u] = add(tag[u], d);
            else {
                add(tops[u], tops[u], mul(d, n));
                for(register int i = 0; i < (int)adj[u].size(); i++) {
                    int v = adj[u][i];
                    if(v == fa[u]) continue;
                    add(tops[v], tops[v] + siz[v] - 1, mul(d, n - siz[v]));
                }
                add(1, tops[u] - 1, mul(d, siz[u])); add(tops[u] + siz[u], n, mul(d, siz[u]));
            }
        }
        if(opt == 2) {
            int u, ans; read(u); ans = query(tops[u]);
            for(register int i = 0; i < (int)p.size(); i++) {
                if(!tag[p[i]]) continue;
                int v = p[i];
                if(u == v) {
                    ans = add(ans, mul(n, tag[p[i]]));
                    continue;
                }
                int l = 0, r = (int)g[v].size() - 1, res = -1;
                while(l <= r) {
                    int mid = (l + r) >> 1;
                    if(tops[u] >= g[v][mid]) {
                        res = mid;
                        l = mid + 1;
                    } else r = mid - 1;
                }
                if(res == -1 || tops[u] > g[v][res] + siz[t[v][res]] - 1) {
                    ans = add(ans, mul(tag[p[i]], siz[v]));
                } else {
                    ans = add(ans, mul(tag[p[i]], n - siz[t[v][res]]));
                }
            }
            print(mul(ans, invn), '\n');
        }
    }
    return 0;
}
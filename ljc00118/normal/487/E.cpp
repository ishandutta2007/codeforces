#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 2e5 + 5, INF = 0x7fffffff;

vector <int> a[N], b[N];
multiset <int> t[N];
int w[N], fa[N], d[N], low[N], dfn[N], st[N];
int n, m, q, oldn, _time;

void tarjan(int u) {
    static int top = 0;
    low[u] = dfn[u] = ++_time; st[++top] = u;
    for(register unsigned i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                int tmp = 0; ++n;
                while(tmp != v) {
                    tmp = st[top--];
                    b[n].push_back(tmp);
                }
                b[u].push_back(n);
            }
        } else low[u] = min(low[u], dfn[v]);
    }
}

int tops[N], pre[N], siz[N], wson[N], top[N], cnt;
void dfs1(int u) {
    siz[u] = 1;
    for(register unsigned i = 0; i < b[u].size(); i++) {
        int v = b[u][i]; d[v] = d[u] + 1; fa[v] = u; dfs1(v);
        if(u > oldn) t[u].insert(w[v]);
        siz[u] += siz[v]; if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++cnt; pre[cnt] = u; top[u] = tp;
    if(wson[u]) dfs2(wson[u], tp);
    for(register unsigned i = 0; i < b[u].size(); i++) {
        int v = b[u][i];
        if(v == wson[u]) continue;
        dfs2(v, v);
    }
}

struct node_t {
    int l, r, minn;
} p[N << 2];

inline void update(int u) { p[u].minn = min(p[u << 1].minn, p[u << 1 | 1].minn); }

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        if(t[pre[l]].size()) p[u].minn = *t[pre[l]].begin();
        else p[u].minn = INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    update(u);
}

void change(int u, int x, int y) {
    if(p[u].l == p[u].r) {
        p[u].minn = y;
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) change(u << 1, x, y);
    else change(u << 1 | 1, x, y);
    update(u);
}

int query(int u, int l, int r) {
    // fprintf(stderr, "l =  %d, r = %d, p[%d].minn = %d\n", p[u].l, p[u].r, u, p[u].minn);
    if(l <= p[u].l && p[u].r <= r) return p[u].minn;
    int ans = INF, mid = (p[u].l + p[u].r) >> 1;
    if(mid >= l) ans = min(ans, query(u << 1, l, r));
    if(mid + 1 <= r) ans = min(ans, query(u << 1 | 1, l, r));
    return ans;
}

int main() {
    read(n); read(m); read(q); oldn = n;
    for(register int i = 1; i <= n; i++) read(w[i]);
    for(register int i = 1; i <= m; i++) {
        int u, v; read(u); read(v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(register int i = 1; i <= oldn; i++) if(!dfn[i]) tarjan(i);
    dfs1(1); dfs2(1, 1); build(1, 1, n);
    while(q--) {
        char c = getchar(); while(c < 'A' || c > 'Z') c = getchar();
        if(c == 'A') {
            int u, v, ans = INF; read(u); read(v);
            if(u == v) { print(w[u], '\n'); continue; }
            while(top[u] != top[v]) {
                if(d[top[u]] < d[top[v]]) swap(u, v);
                ans = min(ans, query(1, tops[top[u]], tops[u]));
                u = fa[top[u]];
            }
            if(d[u] > d[v]) swap(u, v);
            ans = min(ans, query(1, tops[u], tops[v]));
            // fprintf(stderr, "u = %d, fa[u] = %d\n", u, fa[u]);
            if(u > oldn) ans = min(ans, w[fa[u]]);
            else ans = min(ans, w[u]);
            print(ans, '\n');
        }
        if(c == 'C') {
            int x, y; read(x); read(y);
            if(fa[x]) t[fa[x]].erase(t[fa[x]].find(w[x]));
            w[x] = y; if(fa[x]) t[fa[x]].insert(w[x]);
            if(fa[x]) change(1, tops[fa[x]], *t[fa[x]].begin());
        }
    }
    return 0;
}
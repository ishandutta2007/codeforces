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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 5e5 + 5;

vector <int> adj[N];
int tag[N << 2], tops[N], siz[N], wson[N], fa[N], top[N];
int n, m, dfn;

void pushdown(int u) {
    if(tag[u]) {
        tag[u << 1] = tag[u << 1 | 1] = tag[u];
        tag[u] = 0;
    }
}

void change(int u, int l, int r, int L, int R, int x) {
    if(l <= L && R <= r) {
        tag[u] = x;
        return;
    }
    pushdown(u);
    int mid = (L + R) >> 1;
    if(mid >= l) change(u << 1, l, r, L, mid, x);
    if(mid + 1 <= r) change(u << 1 | 1, l, r, mid + 1, R, x);
}

int query(int u, int l, int r, int x) {
    if(l == r) return tag[u];
    pushdown(u);
    int mid = (l + r) >> 1;
    if(mid >= x) return query(u << 1, l, mid, x);
    return query(u << 1 | 1, mid + 1, r, x);
}

void dfs1(int u, int f) {
    siz[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == f) continue;
        fa[v] = u;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfn; top[u] = tp;
    if(wson[u]) dfs2(wson[u], tp);
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 1);
    read(m);
    while(m--) {
        int opt, x;
        read(opt); read(x);
        if(opt == 1) change(1, tops[x], tops[x] + siz[x] - 1, 1, n, 1);
        if(opt == 2) {
            while(x) {
                change(1, tops[top[x]], tops[x], 1, n, 2);
                x = fa[top[x]];
            }
        }
        if(opt == 3) print(query(1, 1, n, tops[x]) == 1, '\n');
    }
    return 0;
}
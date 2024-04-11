#pragma GCC target("avx")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
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

const int N = 1e5 + 5, blk = 332, INF = 0x3fffffff;

vector <int> adj[N];
int t[N], s[N], top[N], siz[N], wson[N], tops[N], B[N], l[blk], r[blk], tag[blk], col[N], fa[N];
int n, m, dfn;

void dfs1(int u) {
    siz[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        dfs1(v);
        siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp; tops[u] = ++dfn;
    if(wson[u]) dfs2(wson[u], tp);
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == wson[u]) continue;
        dfs2(v, v);
    }
}

void build(int block) {
    for(register int i = l[block]; i <= r[block]; i++) {
        t[i] += tag[block];
        if(col[i] == 1) s[i] = INF;
        else s[i] = t[i];
    }
    sort(s + l[block], s + r[block] + 1);
    tag[block] = 0;
}

void add(int L, int R, int x) {
    if(B[L] == B[R]) {
        for(register int i = L; i <= R; i++) t[i] += x;
        build(B[L]);
        // fprintf(stderr, "len = %d\n", R - L + 1);
    } else {
        // fprintf(stderr, "len = %d\n", len);
        for(register int i = L; i <= r[B[L]]; i++) t[i] += x;
        for(register int i = l[B[R]]; i <= R; i++) t[i] += x;
        build(B[L]); build(B[R]);
        for(register int i = B[L] + 1; i <= B[R] - 1; i++) tag[i] += x;
        // fprintf(stderr, "len = %d\n", B[R] - B[L] - 1);
    }
}

void modify(int u, int x) {
    while(top[u]) {
        add(tops[top[u]], tops[u], x);
        u = fa[top[u]];
    }
}

int query() {
    int ans = 0;
    // for(register int i = 1; i <= n; i++) print(s[i], i == n ? '\n' : ' ');
    for(register int i = 1; i <= B[n]; i++) ans += lower_bound(s + l[i], s + r[i] + 1, -tag[i]) - s - l[i];
    return ans;
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) {
        B[i] = (i - 1) / blk + 1;
        if(!l[B[i]]) l[B[i]] = i;
        r[B[i]] = i;
    }
    for(register int i = 2; i <= n; i++) {
        int fa; read(fa); ::fa[i] = fa;
        adj[fa].push_back(i);
    }
    dfs1(1); dfs2(1, 1);
    for(register int i = 1; i <= n; i++) read(t[tops[i]]);
    for(register int i = 1; i <= B[n]; i++) build(i);
    while(m--) {
        // fprintf(stderr, "m = %d\n", m);
        int x; read(x);
        if(x > 0) {
            col[tops[x]] = 1;
            modify(x, -1);
            build(B[tops[x]]);
        } else {
            x = -x;
            col[tops[x]] = 0;
            modify(x, 1);
            build(B[tops[x]]);
        }
        print(query(), ' ');
    }
    putchar('\n');
    return 0;
}
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

const int N = 1e5 + 5;

struct edge_t {
    int u, v, next, val;
} G[N << 1];

ll dis[N], ans; set <int> wxw; set <int> :: iterator it;
int head[N], vis[N], tops[N], pre[N], top[N], d[N], siz[N], wson[N], fa[N];
int n, m, tot, cnt;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void dfs1(int u, int f) {
    siz[u] = 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v; if(v == f) continue;
        fa[v] = u; d[v] = d[u] + 1; dis[v] = dis[u] + G[i].val;
        dfs1(v, u); siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++cnt; pre[cnt] = u; top[u] = tp;
    if(wson[u]) dfs2(wson[u], tp);
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

int LCA(int x, int y) {
    while(top[x] != top[y]) {
        if(d[top[x]] < d[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return d[x] < d[y] ? x : y;
}

inline ll dist(int x, int y) { return dis[x] + dis[y] - 2 * dis[LCA(x, y)]; }

char c[5];

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int a, b, c;
        read(a); read(b); read(c);
        addedge(a, b, c);
    }
    read(m);
    dfs1(1, 0); dfs2(1, 1);
    while(m--) {
        scanf("%s", c + 1);
        if(c[1] == '?') {
            print(ans >> 1, '\n');
            continue;
        }
        int x; read(x); x = tops[x];
        if(!vis[x]) wxw.insert(x);
        int pre, nxt;
        if(wxw.find(x) == wxw.begin()) {
            it = wxw.end(); --it;
            pre = *it;
        } else {
            it = wxw.find(x); --it;
            pre = *it;
        }
        it = wxw.end(); --it;
        if(wxw.find(x) == it) {
            nxt = *wxw.begin();
        } else {
            it = wxw.find(x); ++it;
            nxt = *it;
        }
        ll dis = dist(::pre[x], ::pre[pre]) + dist(::pre[x], ::pre[nxt]) - dist(::pre[pre], ::pre[nxt]);
        // fprintf(stderr, "x = %d, pre = %d, nxt = %d, dis = %d\n", x, pre, nxt, dis);
        if(vis[x]) ans -= dis; else ans += dis;
        if(vis[x]) wxw.erase(x);
        vis[x] ^= 1;
        // print(ans, '\n');
    }
    return 0;
}
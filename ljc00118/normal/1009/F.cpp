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

    void clear() { *this = hash_map_t(mod); }

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

const int N = 1e6 + 5;

struct edge_t { int u, v, next; } G[N << 1];

int head[N], len[N], wson[N], ans[N], *f[N], tmp[N], *now = tmp;
int n, tot;

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

void dfs1(int u, int fa) {
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa) continue;
        dfs1(v, u);
        if(len[v] > len[wson[u]]) wson[u] = v;
    }
    len[u] = len[wson[u]] + 1;
}

void dfs2(int u, int fa) {
    f[u][0] = 1;
    if(wson[u]) f[wson[u]] = f[u] + 1, dfs2(wson[u], u), ans[u] = ans[wson[u]] + 1;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == fa || v == wson[u]) continue;
        f[v] = now; now += len[v]; dfs2(v, u);
        for(register int j = 1; j <= len[v]; j++) {
            f[u][j] += f[v][j - 1];
            if(f[u][j] > f[u][ans[u]] || (f[u][j] == f[u][ans[u]] && j < ans[u])) ans[u] = j;
        }
    }
    if(f[u][ans[u]] == 1) ans[u] = 0;
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    dfs1(1, 0); f[1] = now; now += len[1]; dfs2(1, 0);
    for(register int i = 1; i <= n; i++) print(ans[i], '\n');
    return 0;
}
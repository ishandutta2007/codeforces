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

const int N = 1e5 + 5;

vector <int> adj[N];
int d[N], deg[N];
int n, lef;

int ans[N], ok;
void dfs1(int u, int fa) {
    if(!ok) return;
    if(!ans[d[u]]) ans[d[u]] = deg[u];
    else if(ans[d[u]] != deg[u]) { ok = 0; return; }
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        d[v] = d[u] + 1; dfs1(v, u);
    }
}

bool check(int rt) {
    if(!rt) return 0;
    memset(ans, 0, sizeof(ans)); ok = 1; d[rt] = 0;
    dfs1(rt, 0); return ok;
}

int dis[N], dep[N], rt1, rt2, mid;
void dfs2(int u, int fa) {
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa) continue;
        dep[v] = dep[u] + 1; dfs2(v, u);
    }
}

int main() {
    read(n);
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        ++deg[u]; ++deg[v];
    }
    dfs2(1, 0); rt1 = 1;
    for(register int i = 2; i <= n; i++) if(dep[i] > dep[rt1]) rt1 = i;
    dep[rt1] = 0; dfs2(rt1, 0); rt2 = rt1;
    for(register int i = 1; i <= n; i++) if(dep[i] > dep[rt2]) rt2 = i;
    memcpy(dis, dep, sizeof(dis));
    dep[rt2] = 0; dfs2(rt2, 0);
    if(check(rt1)) { print(rt1, '\n'); return 0; }
    if(check(rt2)) { print(rt2, '\n'); return 0; }
    if(dis[rt2] & 1) { print(-1, '\n'); return 0; }
    for(register int i = 1; i <= n; i++) if(dis[i] == dis[rt2] / 2 && dep[i] == dis[rt2] / 2) { mid = i; break; }
    if(check(mid)) { print(mid, '\n'); return 0; }
    for(register int i = 1; i <= n; i++) if(dis[i] == dep[i] && deg[i] == 1 && dis[i] < dis[rt2]) { if(check(i)) { print(i, '\n'); return 0; } }
    for(register int i = 1; i <= n; i++) if(dis[i] == dep[i] && deg[i] == 1 && dis[i] == dis[rt2]) { if(check(i)) { print(i, '\n'); return 0; } }
    print(-1, '\n');
    return 0;
}
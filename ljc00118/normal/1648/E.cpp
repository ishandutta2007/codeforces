#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 4e5 + 5;

struct edge {
    int u, v, w;
    edge (int a = 0, int b = 0, int c = 0) : u(a), v(b), w(c) {}
    bool operator < (const edge rhs) const { return w < rhs.w; }
} e[N];

vector <pii> adj[N];
vector <int> edg[N], bel[N];
int f[N], a[N][3], lc[N], rc[N], fa[N][20], tops[N], pre[N], siz[N], st[N], go[N], goval[N], used[N], val[N];
int T, n, m, tot, dfn, cnt;

int tr[N];

void add(int x, int y) {
    // fprintf(stderr, "x = %d\n", x);
    while (x <= tot) {
        tr[x] += y;
        x += (x & -x);
    }
}

int query(int x) {
    int ans = 0;
    while (x) {
        ans += tr[x];
        x &= (x - 1);
    }
    return ans;
}

int findk(int k) {
    int ans = 0, sum = 0;
    for (int i = 18; i >= 0; i--) {
        if (ans + (1 << i) <= tot && sum + tr[ans + (1 << i)] < k) {
            ans += (1 << i);
            sum += tr[ans];
        }
    }
    return ans + 1;
}

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

void dfs1(int u) {
    tops[u] = ++dfn; pre[dfn] = u; siz[u] = 1;
    if (lc[u]) dfs1(lc[u]), siz[u] += siz[lc[u]];
    if (rc[u]) dfs1(rc[u]), siz[u] += siz[rc[u]];
}

int par[N][20], mx[N][20], dep[N];
void dfs2(int u, int fa) {
    for (int i = 1; i <= 19; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[par[u][i - 1]][i - 1]);
    }
    for (auto v : adj[u]) {
        if (v.first == fa) continue;
        dep[v.first] = dep[u] + 1; par[v.first][0] = u; mx[v.first][0] = v.second; dfs2(v.first, u);
    }
}

int query(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
        if (dep[par[u][i]] >= dep[v]) {
            ans = max(ans, mx[u][i]);
            u = par[u][i];
        }
    }
    if (u == v) return ans;
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = max(ans, max(mx[u][i], mx[v][i]));
            u = par[u][i];
            v = par[v][i];
        }
    }
    return max(ans, max(mx[u][0], mx[v][0]));
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) f[i] = i, lc[i] = rc[i] = 0, edg[i].clear(), adj[i].clear();
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j <= 2; j++) read(a[i][j]);
            e[i] = edge(a[i][0], a[i][1], a[i][2]);
            edg[e[i].u].push_back(e[i].v);
            edg[e[i].v].push_back(e[i].u);
        }
        sort(e + 1, e + m + 1); tot = n;
        for (int i = 1; i <= m; i++) {
            int x = find(e[i].u), y = find(e[i].v);
            if (x != y) {
                ++tot; lc[tot] = x; rc[tot] = y; fa[tot][0] = 0;
                f[x] = f[y] = f[tot] = tot; val[tot] = e[i].w;
                fa[x][0] = fa[y][0] = tot;
            }
        }
        for (int j = 1; j <= 19; j++) {
            for (int i = 1; i <= tot; i++) fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
        dfn = 0; dfs1(tot);
        for (int i = 1; i <= n; i++) f[i] = i;
        cnt = n;
        while (cnt > 1) {
            memset(tr, 0, (tot + 1) * 4);
            vector <int> vec;
            for (int i = 1; i <= n; i++) bel[i].clear();
            for (int i = 1; i <= n; i++) {
                bel[find(i)].push_back(i);
                if (find(i) == i) {
                    vec.push_back(i);
                }
                add(tops[i], 1);
            }
            for (auto _ : vec) {
                for (auto i : bel[_]) {
                    if (!used[i]) {
                        add(tops[i], -1);
                    }
                    ++used[i];
                }
                for (auto i : bel[_]) {
                    for (auto j : edg[i]) {
                        if (!used[j]) {
                            add(tops[j], -1);
                        }
                        ++used[j];
                    }
                    int u = i;
                    for (int j = 19; j >= 0; j--) {
                        if (fa[u][j] && query(tops[fa[u][j]] + siz[fa[u][j]] - 1) == query(tops[fa[u][j]] - 1)) {
                            u = fa[u][j];
                        }
                    }
                    if (u == tot) {
                        goval[i] = 2e9;
                    } else {
                        u = fa[u][0];
                        go[i] = pre[findk(query(tops[u] - 1) + 1)];
                        goval[i] = val[u];
                    }
                    for (auto j : edg[i]) {
                        --used[j];
                        if (!used[j]) {
                            add(tops[j], 1);
                        }
                    }
                }
                for (auto i : bel[_]) {
                    --used[i];
                    if (!used[i]) {
                        add(tops[i], 1);
                    }
                }
            }
            for (auto i : vec) {
                st[i] = i;
                for (auto u : bel[i]) {
                    if (goval[u] < goval[i]) {
                        goval[i] = goval[u];
                        go[i] = go[u];
                        st[i] = u;
                    }
                }
                int x = find(i), y = find(go[i]);
                if (x != y) {
                    f[x] = y;
                    adj[st[i]].emplace_back(go[i], goval[i]);
                    adj[go[i]].emplace_back(st[i], goval[i]);
                    --cnt;
                }
            }
        }
        dep[1] = 1; dfs2(1, 0);
        for (int i = 1; i <= m; i++) {
            print(query(a[i][0], a[i][1]), i == m ? '\n' : ' ');
        }
    }
    return 0;
}
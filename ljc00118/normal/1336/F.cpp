#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 150005;

vector <int> adj[N], id[N];
int lc[N * 40], rc[N * 40], sum[N * 40], rt[N];
int fa[N][18], tops[N], siz[N], dep[N], u[N], v[N], old[N], vec[N];
int n, m, k, tot, dfn; ll ans;

void dfs1(int u) {
    for (int i = 1; i <= 17; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    tops[u] = ++dfn; siz[u] = 1;
    // fprintf(stderr, "tops[%d] = %d\n", u, tops[u]);
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u][0]) continue;
        dep[v] = dep[u] + 1; fa[v][0] = u; dfs1(v);
        siz[u] += siz[v];
    }
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int i = 17; i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
            u = fa[u][i];
        }
    }
    if (u == v) return u;
    for (int i = 17; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

void merge(int &u, int v) {
    if (!v) return;
    if (!u) { u = v; return; }
    sum[u] += sum[v];
    merge(lc[u], lc[v]);
    merge(rc[u], rc[v]);
}

void add(int &u, int l, int r, int x) {
    if (!u) u = ++tot;
    ++sum[u];
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (mid >= x) add(lc[u], l, mid, x);
    else add(rc[u], mid + 1, r, x);
}

int query(int u, int L, int R, int l, int r) {
    if (!u) return 0;
    if (l <= L && R <= r) return sum[u];
    int mid = (L + R) >> 1, ans = 0;
    if (mid >= l) ans += query(lc[u], L, mid, l, r);
    if (mid + 1 <= r) ans += query(rc[u], mid + 1, R, l, r);
    return ans;
}

int jump(int u, int h) {
    for (int i = 17; i >= 0; i--) {
        if ((h >> i) & 1) {
            u = fa[u][i];
        }
    }
    return u;
}

void solve(int u, int id, int root) {
    if (dep[u] <= dep[old[id]]) return;
    // fprintf(stderr, "u = %d, id = %d, ans : %lld -> ", u, id, ans);
    if (dep[u] - dep[old[id]] >= k) {
        int cat = jump(u, k - 1);
        ans += sum[root] - query(root, 1, n, tops[cat], tops[cat] + siz[cat] - 1);
        if (tops[::u[id]] >= tops[u]) {
            int mao = jump(v[id], dep[v[id]] - dep[old[id]] - 1);
            // fprintf(stderr, "mao = %d\n", mao);
            ans -= query(root, 1, n, tops[mao], tops[mao] + siz[mao] - 1);
        }
    } else if (tops[::u[id]] < tops[u]) {
        int cat = jump(::u[id], (dep[::u[id]] - dep[old[id]]) - (k - (dep[u] - dep[old[id]])));
        ans += query(root, 1, n, tops[cat], tops[cat] + siz[cat] - 1);
    }
    // fprintf(stderr, "%lld\n", ans);
}

void dfs2(int u) {
    vec[u] = u;
    for (int i = 0; i < (int)id[u].size(); i++) {
        solve(u, id[u][i], rt[u]);
        add(rt[u], 1, n, tops[::u[id[u][i]] ^ v[id[u][i]] ^ u]);
    }
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u][0]) continue;
        dfs2(v);
        int now = u;
        if (id[vec[u]].size() < id[vec[v]].size()) swap(vec[u], vec[v]), now = v;
        for (int j = 0; j < (int)id[vec[v]].size(); j++) solve(u, id[vec[v]][j], rt[now]), id[vec[u]].push_back(id[vec[v]][j]);
        merge(rt[u], rt[v]);
    }
}

int main() {
    read(n); read(m); read(k);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dep[1] = 1; dfs1(1);
    for (int i = 1; i <= m; i++) {
        read(u[i]); read(v[i]); old[i] = lca(u[i], v[i]);
        if (dep[u[i]] + dep[v[i]] - 2 * dep[old[i]] < k) {
            --i; --m;
            continue;
        }
        if (tops[u[i]] > tops[v[i]]) swap(u[i], v[i]);
        id[u[i]].push_back(i);
        id[v[i]].push_back(i);
    }
    dfs2(1);
    print(ans, '\n');
    return 0;
}
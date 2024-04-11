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

const int N = 2e5 + 5;

vector <int> adj[N];
int st[N * 2][19], fa[N][18], pos[N], lg[N * 2], dep[N];
int n, len; ll ans;

void dfs1(int u) {
    for (int i = 1; i <= 17; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    st[++len][0] = dep[u]; pos[u] = len;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[u][0]) continue;
        dep[v] = dep[u] + 1;
        fa[v][0] = u;
        dfs1(v);
        st[++len][0] = dep[u];
    }
}

int lca(int l, int r) {
    l = pos[l]; r = pos[r];
    if (l > r) swap(l, r);
    int k = lg[r - l + 1];
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int dis(int u, int v) {
    return dep[u] + dep[v] - lca(u, v) * 2;
}

int jump(int u, int k) {
    for (int i = 0; i <= 17; i++) {
        if ((k >> i) & 1) {
            u = fa[u][i];
        }
    }
    return u;
}

int go(int u, int v, int k) {
    int d = lca(u, v);
    if (k <= dep[u] - d) return jump(u, k);
    return jump(v, dep[v] + dep[u] - 2 * d - k);
}

ll sum[N];
int siz[N], par[N], d[N][20], maxn[N], vis[N], cnt[N], dd[N];
int allsize, root;

void getroot(int u, int fa) {
    siz[u] = 1; maxn[u] = 0;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa || vis[v]) continue;
        getroot(v, u); siz[u] += siz[v];
        maxn[u] = max(maxn[u], siz[v]);
    }
    maxn[u] = max(maxn[u], allsize - siz[u]);
    if (maxn[u] < maxn[root]) root = u;
}

void dfs2(int u, int fa, int id, int dep) {
    d[u][id] = dep;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa || vis[v]) continue;
        dfs2(v, u, id, dep + 1);
    }
}

void build(int u, int id) {
    dfs2(u, 0, id, 0);
    vis[u] = 1; dd[u] = id;
    int tmp = allsize;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (vis[v]) continue;
        if (siz[v] >= siz[u]) allsize = tmp - siz[u];
        else allsize = siz[v];
        root = 0; getroot(v, 0); par[root] = u; build(root, id + 1);
    }
}

void add(int u) {
    // fprintf(stderr, "add %d\n", u);
    int tmp = u;
    while (tmp) {
        sum[tmp] += d[u][dd[tmp]];
        if (par[tmp]) sum[tmp] -= d[u][dd[tmp] - 1];
        ++cnt[tmp];
        tmp = par[tmp];
    }
}

void del(int u) {
    // fprintf(stderr, "del %d\n", u);
    int tmp = u;
    while (tmp) {
        sum[tmp] -= d[u][dd[tmp]];
        if (par[tmp]) sum[tmp] += d[u][dd[tmp] - 1];
        --cnt[tmp];
        tmp = par[tmp];
    }
}

ll query(int u) {
    ll ans = 0;
    int tmp = u;
    while (tmp) {
        // fprintf(stderr, "tmp = %d, d[%d][%d] = %d\n", tmp, u, dd[tmp], d[u][dd[tmp]]);
        ans += sum[tmp] + 1ll * d[u][dd[tmp]] * cnt[tmp];
        if (par[tmp]) ans -= 1ll * d[u][dd[tmp] - 1] * cnt[tmp];
        // fprintf(stderr, "debug >>> %d %d %d\n", tmp, par[tmp], d[tmp][dd[par[tmp]]]);
        // if (par[tmp]) ans -= sum[tmp] + 1ll * (d[u][dd[tmp]] + d[tmp][dd[par[tmp]]] * 2) * cnt[tmp];
        // fprintf(stderr, "u = %d, tmp = %d, ans = %lld\n", u, tmp, ans);
        tmp = par[tmp];
    }
    // fprintf(stderr, "query(%d) = %lld\n", u, ans);
    return ans;
}

struct atom {
    int u, dis;
    atom (int k1 = 0, int k2 = 0) : u(k1), dis(k2) {}
} s[N];

ll ss[N];

atom operator + (const atom a, const atom b) {
    int len = dis(a.u, b.u);
    if (a.dis + len <= b.dis) return b;
    if (b.dis + len <= a.dis) return a;
    return atom(go(a.u, b.u, (b.dis + len - a.dis) / 2), (a.dis + b.dis + len) / 2);
}

int getopt(const atom a, const atom b) {
    int len = dis(a.u, b.u);
    if (a.dis + len <= b.dis) return 2;
    if (b.dis + len <= a.dis) return 0;
    return 1;
}

void solve(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1, len = 0;
    for (int i = mid; i >= l; i--) s[++len] = atom(i, 0);
    for (int i = 2; i <= len; i++) s[i] = s[i] + s[i - 1];
    ss[len + 1] = 0;
    for (int i = len; i >= 1; i--) ss[i] = s[i].dis + ss[i + 1];
    atom sum = atom(mid + 1, 0);
    int pos1 = 0, pos2 = 0;
    for (int i = mid + 1; i <= r; i++) {
        // fprintf(stderr, "i = %d, l = %d, mid = %d, r = %d, preans = %lld, ", i, l, mid, r, ans);
        sum = sum + atom(i, 0);
        while (pos1 < len && getopt(sum, s[pos1 + 1]) <= 0) {
            ++pos1;
            del(s[pos1].u);
        }
        while (pos2 < len && getopt(sum, s[pos2 + 1]) <= 1) {
            ++pos2;
            add(s[pos2].u);
        }
        ans += 1ll * pos1 * sum.dis;
        ans += (query(sum.u) + ss[pos1 + 1] - ss[pos2 + 1] + 1ll * sum.dis * (pos2 - pos1)) / 2;
        ans += ss[pos2 + 1];
        // fprintf(stderr, "pos1 = %d, pos2 = %d, ans = %lld\n", pos1, pos2, ans);
    }
    // fprintf(stderr, "l = %d, r = %d, pos1 = %d, pos2 = %d\n", l, r, pos1, pos2);
    while (pos2 > pos1) {
        del(s[pos2].u);
        --pos2;
    }
    solve(l, mid); solve(mid + 1, r);
}

int main() {
    // freopen("input.txt", "r", stdin);
    read(n);
    maxn[0] = n * 2;
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(i + n);
        adj[i + n].push_back(u);
        adj[v].push_back(i + n);
        adj[i + n].push_back(v);
        // fprintf(stderr, "%d %d\n%d %d\n", u, i + n, v, i + n);
    }
    dfs1(1);
    lg[0] = -1;
    for (int i = 1; i <= len; i++) lg[i] = lg[i >> 1] + 1;
    for (int j = 1; j <= 18; j++) {
        for (int i = 1; i <= len - (1 << j) + 1; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    allsize = n * 2 - 1; getroot(1, 0); build(root, 0);
    // add(2);
    // cout << query(7) << endl;
    // return 0;
    solve(1, n);
    print(ans, '\n');
    return 0;
}
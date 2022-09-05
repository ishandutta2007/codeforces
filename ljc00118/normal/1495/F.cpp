#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 2e5 + 5;

vector <int> adj[N];
set <int> pos;
set <int> :: iterator it;
ll v[N][18], s[N], sum[N];
int p[N], a[N], b[N], fa[N][18], st[N], dep[N], zt[N], mi[N], id[N];
int n, m, top, tot; ll ans;

int jump(int u, int k) {
    for (int i = 0; i <= 17; i++) {
        if ((k >> i) & 1) {
            u = fa[u][i];
        }
    }
    return u;
}

int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    // fprintf(stderr, "u = %d, v = %d, dep[u] = %d, dep[v] = %d\n", u, v, dep[u], dep[v]);
    u = jump(u, dep[u] - dep[v]);
    if (u == v) return u;
    for (int i = 17; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

ll getv(int u, int k) {
    ll ans = 0;
    for (int i = 0; i <= 17; i++) {
        if ((k >> i) & 1) {
            ans += v[u][i];
            u = fa[u][i];
        }
    }
    return ans;
}

ll getdis(int u, int v) {
    ll res = 0;
    int _lca = lca(u, v);
    if (_lca == v) res = getv(u, dep[u] - dep[v]);
    else {
        int pu = jump(u, dep[u] - dep[_lca] - 1);
        int pv = jump(v, dep[v] - dep[_lca] - 1);
        res = getv(u, dep[u] - dep[_lca] - 1) + a[pu];
        res += s[id[pv] - 1] - s[id[pu]];
        // fprintf(stderr, "pu = %d, pv = %d, res = %lld\n", pu, pv, res);
        res += sum[v] - sum[pv];
        res += getv(mi[v], dep[mi[v]] - dep[v]);
    }
    // fprintf(stderr, "dis(%d, %d) = %lld\n", u, v, res);
    return res;
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(p[i]);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    p[n + 1] = 1e9; st[top = 1] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top && p[i] > p[st[top]]) --top;
        fa[i][0] = st[top];
        adj[st[top]].push_back(i);
        st[++top] = i;
    }
    dep[n + 1] = 1;
    for (int i = n; i >= 1; i--) {
        dep[i] = dep[fa[i][0]] + 1;
        v[i][0] = min((ll)b[i], a[i] + getv(i + 1, dep[i + 1] - dep[fa[i][0]]));
        // fprintf(stderr, "fa[%d][0] = %d, v[%d][0] = %lld\n", i, fa[i][0], i, v[i][0]);
        for (int j = 1; j < 18; j++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            v[i][j] = v[i][j - 1] + v[fa[i][j - 1]][j - 1];
        }
    }
    for (int u = 1; u <= n; u++) {
        if ((int)adj[u].size()) mi[u] = mi[adj[u][adj[u].size() - 1]];
        else mi[u] = u;
    }
    for (int u = 1; u <= n + 1; u++) {
        ll now = 0;
        for (int i = (int)adj[u].size() - 1; i >= 0; i--) {
            int v = adj[u][i];
            id[v] = ++tot;
            ll tmp = getv(mi[v], dep[mi[v]] - dep[v]) + a[v];
            s[id[v]] = tmp; sum[v] = now; now += tmp;
            // fprintf(stderr, "sum[%d] = %lld\n", v, sum[v]);
        }
    }
    for (int i = n; i >= 1; i--) sum[i] += sum[fa[i][0]];
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];
    pos.insert(1); pos.insert(n + 1);
    ans = getdis(1, n + 1);
    // cout << "ans = " << ans << endl;
    for (int i = 1; i <= m; i++) {
        int x; read(x);
        if (x == 1) {
            print(ans, '\n');
            continue;
        }
        if (zt[x] == 0) {
            zt[x] = 1;
            it = pos.lower_bound(x);
            int r = *it; --it; int l = *it;
            pos.insert(x);
            ans -= getdis(l, r); ans += getdis(l, x); ans += getdis(x, r);
        } else {
            zt[x] = 0;
            pos.erase(x);
            it = pos.lower_bound(x);
            int r = *it; --it; int l = *it;
            ans += getdis(l, r); ans -= getdis(l, x); ans -= getdis(x, r);
        }
        print(ans, '\n');
    }
    return 0;
}
#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10;
int n, q;
char s[N];
int stk[N], top = 0;
int id[N], fa[N], deg[N], tot = 0;
vector<int> g[N];
int dfn[N], l[N], r[N], dfc = 0;
int bfn[N], bfc = 0, match[N];
struct fenw {
    ll f[N];
    void add(int x, ll v) {
        for(int i = x; i <= dfc; i += i & (-i)) f[i] += v;
        return;
    }
    ll sum(int x) {
        ll ans = 0;
        for(int i = x; i > 0; i -= i & (-i)) ans += f[i];
        return ans;
    }
}t1, t2;
void dfs(int u) {
    l[u] = dfn[u] = ++dfc;
    for(int v : g[u]) dfs(v);
    r[u] = dfc;
    return;
}
void bfs(int u) {
    deque<int> q;
    q.push_back(u);
    while(!q.empty()) {
        int u = q.front();
        q.pop_front();
        bfn[u] = ++bfc;
        for(int v : g[u]) q.push_back(v);
    }
    return;
}
void solve() {
    cin >> n >> q;
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) {
        if(s[i] == ')') {
            if(top > 0) match[stk[top]] = match[i] = 1, top--;
        } else {
            stk[++top] = i;
        }
    }
    top = 0;
    for(int i = 1; i <= n; i++) {
        if(!match[i]) continue;
        if(s[i] == ')') {
            if(top > 0) {
                id[i] = id[stk[top]];
                top--;
                fa[id[i]] = id[stk[top]];
            }
        } else {
            stk[++top] = i;
            id[i] = ++tot;
        }
    }
    for(int i = 1; i <= tot; i++) if(fa[i]) g[fa[i]].push_back(i), deg[fa[i]]++;
    int rt = ++tot;
    for(int i = 1; i <= tot - 1; i++) if(!fa[i]) g[rt].push_back(i), deg[rt]++;
    dfs(rt), bfs(rt);
    for(int i = 1; i <= tot; i++) t1.add(dfn[i], 1ll * deg[i] * (deg[i] + 1) / 2), t2.add(bfn[i], 1);
    for(int i = 1; i <= q; i++) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if(opt == 1) {
            int x = id[l];
            t2.add(bfn[x], -1);
            if(fa[x]) {
                t1.add(dfn[fa[x]], - 1ll * deg[fa[x]] * (deg[fa[x]] + 1) / 2);
                deg[fa[x]]--;
                t1.add(dfn[fa[x]], 1ll * deg[fa[x]] * (deg[fa[x]] + 1) / 2);
            }
        } else {
            ll ans = t1.sum(::r[id[r]]) - t1.sum(::l[id[l]] - 1), cnt = t2.sum(bfn[id[r]]) - t2.sum(bfn[id[l]] - 1);
            ans += cnt * (cnt + 1) / 2;
            cout << ans << endl;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
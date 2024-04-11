#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

int a[N], b[N], n, used[N], mx[N];
vector<int> g[N], g1[N], order;

void dfs(int v) {
    used[v] = 1;
    for (auto u: g[v])
        if (!used[u])
            dfs(u);
    order.pb(v);
}

void dfs2(int v) {
    used[v] = 1;
    for (auto u: g1[v])
        if (!used[u])
            dfs2(u);
    order.pb(v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1)
            g[b[i]].pb(i);
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i);
    int ans = 0;
    for (auto v: order) {
        mx[v] = a[v];
        for (auto u: g[v])
            if (mx[u] > 0)
                mx[v] += mx[u], g1[v].pb(u);
            else
                g1[u].pb(v);
        ans += mx[v];
    }
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    order.clear();
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs2(i);
    cout << ans << "\n";
    int tt = 0;
    for (auto x: order) {
        cout << x << ' ';
        tt += a[x];
        if (b[x] != -1)
            a[b[x]] += a[x];
    }
    return 0;
}
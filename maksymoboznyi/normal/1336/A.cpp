#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, k, ans, sz[N], dep[N];
vector<int> g[N];

void dfs(int v, int p) {
    sz[v] = 1;
    dep[v] = dep[p] + 1;
    for (auto u: g[v])
        if (u != p)
            dfs(u, v), sz[v] += sz[u];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1);
    vector<int> q;
    for (int i = 1; i <= n; i++)
        q.pb(dep[i] - 1 - sz[i] + 1);
    sort(q.rbegin(), q.rend());
    int ans = 0;
    for (int i = 0; i < k; i++)
        ans += q[i];
    cout << ans;
    return 0;
}
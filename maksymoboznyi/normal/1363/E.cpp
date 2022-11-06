#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 2e5 + 5;

int n, dp[N], a[N], b[N], c[N], sumb[N], sumc[N], sz[N], bad[N];
vector<int> g[N];

bool cmp(int a, int b) {
    return sz[a] > sz[b];
}

void dfs1(int v, int p) {
    sumb[v] = b[v];
    sumc[v] = c[v];
    sz[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
    for (auto u: g[v]) {
        dfs1(u, v);
        sumb[v] += sumb[u];
        sumc[v] += sumc[u];
        sz[v] += sz[u];
    }
}

pi dfs(int v, int up) {
    pi ans;
    if (b[v] != c[v]) {
        if (!b[v])
            ans.first++;
        else
            ans.second++;
    }
    for (auto u: g[v]) {
        pi x = dfs(u, min(up, a[u]));
        ans.first += x.first;
        ans.second += x.second;
        dp[v] += dp[u];
    }
    int x = min(ans.first, ans.second);
    dp[v] += 2 * x * up;
    ans.first -= x;
    ans.second -= x;
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i], dp[i] = 0;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs1(1, 1);
    pi res = dfs(1, a[1]);
    if (res.first + res.second != 0)
        cout << -1;
    else
        cout << dp[1];
    return 0;
}
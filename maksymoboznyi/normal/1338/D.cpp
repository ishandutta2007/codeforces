#include <bits/stdc++.h>
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()

#define pb push_back
#define pi pair<int, int>
using namespace std;

const int N = 2e5 + 5;

struct cell {
    int val, u, t;
};

int ans = 0, n, dp[N][3], par[N];
vector<int> g[N];

bool cmp1(int a, int b) {
    return dp[a][1] > dp[b][1];
}

bool cmpp(cell a, cell b) {
    return a.val > b.val;
}

void dfs_dp(int v, int p) {
    par[v] = p;
    dp[v][0] = 1;
    dp[v][1] = max(dp[v][1], (int)g[v].size());
    int ch = 0;
    for (auto u: g[v])
        if (u != p) {
            dfs_dp(u, v);
            dp[v][0] = max(dp[v][0], dp[u][1]);
            dp[v][1] = max(dp[v][1], max(dp[u][0], dp[u][1] - 1) + (int)g[v].size() - 1);
        }
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] == p) {
            g[v].erase(g[v].begin() + i);
            break;
        }
    ans = max(ans, max(dp[v][0], dp[v][1]));
    if (g[v].size() <= 1)
        return;
    ///don't take v
    sort(all(g[v]), cmp1);
    ans = max(ans, dp[g[v][0]][1] + dp[g[v][1]][1] - 1);
    ///take v
    vector<cell> q;
    for (auto u: g[v])
        for (int i = 0; i < 2; i++)
            q.pb({dp[u][i], u, i});
    for (auto &p: q) {
        if (p.t == 0)
            p.val--;
        if (p.t == 1)
            p.val -= 2;
    }
    sort(all(q), cmpp);
    for (int i = 0; i < min((int)q.size(), 4); i++)
        for (int j = i + 1; j < min((int)q.size(), 4); j++)
            if (q[i].u != q[j].u)
                ans = max(ans, q[i].val + q[j].val + (int)g[v].size() + (v != 1));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs_dp(1, 1);
    cout << ans << "\n";
    return 0;
}
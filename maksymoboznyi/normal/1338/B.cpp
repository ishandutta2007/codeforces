#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e18;

int n, k[2][N], ans = 1, kol = 0;
vector<int> g[N];

void dfs(int v, int p = -1) {
    if (g[v].size() == 1) {
        k[0][v] = 1;
        return;
    }
    int val = 0;
    for (auto u: g[v])
        if (u != p) {
            dfs(u, v);
            if (g[u].size() == 1)
                val++;
            k[0][v] += k[1][u];
            k[1][v] += k[0][u];
        }
    if (val > 0)
        kol += val - 1;
    for (auto u: g[v])
        if (u != p) {
            if (k[1][v] != k[0][u] && k[1][u] != 0)
                ans = 3;
            if (k[0][v] != k[1][u] && k[0][u] != 0)
                ans = 3;
        }
}

signed main()
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
    for (int i = 1; i <= n; i++)
        if (g[i].size() > 1) {
            dfs(i);
            cout << ans << ' ' << n - 1 - kol;
            break;
        }
    return 0;
}
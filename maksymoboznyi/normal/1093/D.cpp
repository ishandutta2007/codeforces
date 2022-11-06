#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 5e5 + 5;
const long long inf = 2e18;
const long long M = 998244353;

int n, m, c[N], used[N];
vector<int> g[N], comp;
bool can = 1;

void dfs(int v, int cp) {
    used[v] = 1;
    comp.pb(v);
    c[v] = !cp;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i], c[v]);
        else
            if (c[g[v][i]] == c[v])
                can = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int o = 0; o < t; o++ ) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[i].clear();
        used[i] = 0;
        c[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    if (!used[i]) {
        can = 1;
        comp.clear();
        dfs(i, 0);
        int cans = 0;
        if (can != 0) {
            int x = 1;
            for (int j = 0; j < comp.size(); j++) {
                if (c[comp[j]] == 1)
                    x *= 2, x %= M;
                used[comp[j]] = 0;
            }
            cans += x;
        }
        can = 1;
        comp.clear();
        dfs(i, 1);
        if (can != 0) {
            int x = 1;
            for (int j = 0; j < comp.size(); j++) {
                if (c[comp[j]] == 1)
                    x *= 2, x %= M;
            }
            cans += x;
        }
        cans %= M;
        ans *= cans;
        ans %= M;
    }
    cout << ans << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 2e5 + 1;
const int M = 998244353;
const int inf = 1e18 + 1;

int n, m, a, b, c, p[N], d[3][N], pref[N];
vector<int> g[N];


void bfs(int v, int id) {
    for (int i = 1; i <= n; i++)
        d[id][i] = inf;
    d[id][v] = 0;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u: g[v])
            if (d[id][u] == inf)
                d[id][u] = d[id][v] + 1, q.push(u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> b >> c;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= m; i++)
            cin >> p[i];

        for (int i  = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        sort(p + 1, p + m + 1);
        for (int i = 1; i <= m; i++)
            pref[i] = pref[i - 1] + p[i];
        bfs(a, 0);
        bfs(b, 1);
        bfs(c, 2);
        int ans = inf;
        for (int q = 1; q <= n; q++)
        {
            int c = d[0][q] + d[1][q] + d[2][q];
            if (c > m)
                continue;
            ans = min(ans, pref[c] + pref[d[1][q]]);
        }
        cout << ans << "\n";
    }
    return 0;
}
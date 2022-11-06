#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int N = 2e5 + 5;

int can, n, m, p[N], a[N], b[N], h[N];
vector<int> g[N];

void dfs(int v, int par) {
    int have = p[v];

    a[v] = b[v] = 0;
    for (auto u: g[v])
        if (u != par) {
            dfs(u, v);
            p[v] += p[u];
            a[v] += a[u];
            b[v] += b[u];
        }
    int x, y;
    if ((p[v] + h[v]) % 2 != 0) {
        can = 0;
        return;
    }
    x = (p[v] + h[v]) / 2;
    y = p[v] - x;


    if (y < 0 || x < a[v]) {
        can = 0;
        return;
    }
    int del = x - a[v];
    if (y < b[v])
        del -= (b[v] - y);
    else
        del += y -b[v];
    if (del != have)
        can = 0;
    a[v] = x;
    b[v] = y;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        for (int i = 1; i < n; i++) {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        can = 1;
        dfs(1, 0);
        if (can)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
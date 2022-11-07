#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9 + 9;
int n, m, d, p[N], down[N], down2[N], up[N], is[N], used[N];
vector<int> g[N];

void calc_down(int v) {
    used[v] = 1;
    down[v] = down2[v] = -10;
    if (is[v])
        down[v] = 0;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]]) {
            calc_down(g[v][i]);
            if (down[g[v][i]] != -10 && down[g[v][i]] + 1 > down[v])
                down2[v] = down[v], down[v] = down[g[v][i]] + 1;
            else
                if (down[g[v][i]] != -10 && down[g[v][i]] + 1 > down2[v])
                    down2[v] = down[g[v][i]] + 1;
        }
}

void calc_up(int v) {
    up[v] = -10;
    used[v] = 1;
    if (is[v] == 1)
        up[v] = 0;
    for (int i = 0; i < g[v].size(); i++)
        if (used[g[v][i]])
        {
            if (up[g[v][i]] != -10)
                up[v] = max(up[v], up[g[v][i]] + 1);
            if (down[g[v][i]] != -10 && down[g[v][i]] != down[v] + 1)
                up[v] = max(up[v], down[g[v][i]] + 1);
            else
                if (down2[g[v][i]] != -10)
                    up[v] = max(up[v], down2[g[v][i]] + 1);
        }
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            calc_up(g[v][i]);
}

int main()
{
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        cin >> p[i];
        is[p[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    calc_down(1);
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    calc_up(1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (max(up[i], down[i]) <= d)
            ans++;
    cout << ans;
    return 0;
}
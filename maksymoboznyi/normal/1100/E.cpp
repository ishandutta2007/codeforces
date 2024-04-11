#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 1e5 + 5;

struct cell {
    int a, b, c;
};


int t, n, m, used[N], res, tout[N];
vector<int> ans;
vector<cell> e;
vector<pair<int, int> > g[N];

void dfs(int v, int x) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i].second > x)
            if (!used[g[v][i].first])
                dfs(g[v][i].first, x);
            else
                if (used[g[v][i].first] == 1)
                {
                    res = 0;
                    return;
                }
    used[v] = 2;
    t++;
    tout[v] = t;
}

bool check(int x) {
    for (int i = 1; i <= n; i++)
        used[i] = 0;
    ans.clear();
    t = 0;
    res = 1;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            dfs(i, x);
    for (int i = 0; i < e.size(); i++)
        if (e[i].c <= x && tout[e[i].a] < tout[e[i].b])
            ans.pb(i + 1);
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].pb({b, c});
        e.pb({a, b, c});
    }
    int l = -1, r = 10000000001;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
    }
    check(r);
    cout << r << ' ' << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    return 0;
}
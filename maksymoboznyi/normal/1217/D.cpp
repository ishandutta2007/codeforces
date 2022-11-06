#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 5e3 + 5;

int n, m, is;
int used[N], ans[N];
vector<pair<int, int> > g[N];

void dfs(int v) {
    used[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].first, num = g[v][i].second;
        if (used[to] == 1)
            is = 1, ans[num] = 2;
        if (used[to] == 0)
            dfs(to);
        if (used[to] != 1)
            ans[num] = 1;
    }
    used[v] = 2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb({b, i});
    }
    for (int i = 1; i <= n; i++)
        if (used[i] == 0)
            dfs(i);
    if (!is) {
        cout << "1\n";
        for (int i = 1; i <= m; i++)
            cout << "1 ";
        return 0;
    }
    cout << 2 << "\n";
    for (int i = 1; i <= m; i++)
        cout << ans[i] << ' ';
    return 0;
}
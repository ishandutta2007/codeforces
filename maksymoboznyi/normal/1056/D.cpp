#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;

vector<int> g[N];
int n, p[N], used[N], k[N];

int dfs(int v) {
    used[v] = 1;
    int res = 0;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            res += dfs(g[v][i]);
    if (res == 0)
        res = 1;
    k[v] = res;
    return res;
}

signed main()
{
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        g[p[i]].pb(i);
        g[i].pb(p[i]);
    }
    dfs(1);
    sort(k + 1, k + n + 1);
    for (int i = 1; i <= n; i++)
        cout << k[i] << ' ';
    return 0;
}
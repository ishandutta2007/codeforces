#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 3e5 + 5;

int n, col[N], kol[2];
vector<int> g[N];

void dfs(int v, int p) {
    col[v] = (!col[p]);
    kol[col[v]]++;
    for (auto u: g[v])
        if (u != p)
            dfs(u, v);
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    int v = 1;
    for (int i = 2; i <= n; i++)
        if (g[i].size() > 1)
            v = i;
    dfs(v, 0);
    cout << min(kol[0], kol[1]) - 1;
    return 0;
}
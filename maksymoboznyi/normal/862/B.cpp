#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 1e5 + 5;

int n, kol[3], col[N];
vector<int> g[N];

void dfs(int v, int c) {
    col[v] = c;
    kol[c]++;
    c++;
    if (c == 3)
        c = 1;
    for (int i = 0; i < g[v].size(); i++)
        if (!col[g[v][i]])
            dfs(g[v][i], c);
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    dfs(1, 1);
    cout << 1ll*kol[1] * kol[2] - n + 1;
    return 0;
}
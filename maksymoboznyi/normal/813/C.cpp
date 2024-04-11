#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int x, n, ma = 0, pos;
vector<int> g[200005];
int ttime[200005];
bool used[200005];
void dfs(int v, int t)
{
    used[v] = true;

    ttime[v] = t;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            dfs(g[v][i], t+1);
}
void dfs2(int v, int t)
{
    used[v] = true;
    if (ttime[v] > ttime[pos])
        pos = v;
   // cout << v << ' ' << t << endl;
    for (int i = 0; i < g[v].size(); i++)
     {
         //cout << ttime[g[v][i]] << ' ' << ttime[v] << ' ' << g[v][i] << ' ' << v << endl;
         if (!used[g[v][i]] && (ttime[g[v][i]] > ttime[v] || (ttime[g[v][i]] > t+1)))
            dfs2(g[v][i], t+1);
     }
}
int main()
{
    cin >> n >> x;
    int a, b;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i <= n; i++)
        sort(g[i].begin(), g[i].end());
    pos = x;
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
        used[i] = false;
    dfs2(x, 0);
    cout << ttime[pos]*2;
    return 0;
}
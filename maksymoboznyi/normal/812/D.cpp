#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

int n, m, k, q, subtree[100005], last_play[100005], a, b, c, tin[100005], tout[100005], time_in = 1, time_out = 1, x, y, z, par[100005];
vector<int> g[100005];
bool used[100005], use[100005];

int dfs_get(int v)
{
    used[v] = true;
    tin[v] = time_in;
    time_in++;

    int sum = 0;
    for (int i = 0; i < g[v].size(); i++)
        if (!used[g[v][i]])
            sum += dfs_get(g[v][i]);

    subtree[v] = sum + 1;
    tout[v] = time_out;
    time_out++;
    return subtree[v];
}

int main()
{
    cin >> n >> m >> k >> q;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        if (!use[b])
        {
            use[b] = true;
            last_play[b] = a;
        }else
        {
            c = last_play[b];
            g[c].pb(a);
            par[a] = c;
            last_play[b] = a;
        }
    }
    for (int i = 0; i <= n; i++)
        used[i] = false;
    for (int i = 1; i <= n; i++)
        if (par[i] == 0)
            dfs_get(i);
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        if (use[y])
        {
            z = last_play[y];
            if (tin[z] > tin[x] && tout[z] < tout[x])
                cout << subtree[x] << endl;
            else
                cout << 0 << endl;
        }else
        cout << 0 << endl;
    }
    return 0;
}
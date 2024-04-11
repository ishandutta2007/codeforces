#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int col[N];
int col1[N];
int used[N];
vector <int> mass;
vector <int> g[N];
int n, m;
void dfs(int v)
{
    used[v] = 1;
    bool fl = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(col[to])
        {
            fl = 0;
        }
    }
    if(fl)
    {
        col[v] = 1;
        mass.push_back(v);
    }
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        if(!used[to])
        {
            dfs(to);
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            col1[i] = 1;
            col[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int c = 0;
        for(int i = 0; i < n; i++)
        {
            if(!used[i])
            {
                dfs(i);
                c++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            used[i] = 0;
            g[i].clear();
        }
        if(c > 1)
        {
            cout << "NO\n";
            mass.clear();
            continue;
        }
        cout << "YES\n";
        cout << mass.size() << "\n";
        for(int i = 0; i < mass.size(); i++)
        {
            cout << mass[i] + 1 << " ";
        }
        cout << "\n";
        mass.clear();
    }
    return 0;
}
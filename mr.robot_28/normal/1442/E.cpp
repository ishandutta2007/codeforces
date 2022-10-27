#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector <int> col;
vector <vector <int> > g;
int n;
vector <int> deg;
int solve(int x)
{
    vector <int> mass[3];
    for(int i = 0; i < n; i++)
    {
        deg[i] = g[i].size();
        if(deg[i] == 1)
        {
            mass[col[i]].push_back(i);
        }
    }
    int cnt = 0;
    while(1)
    {
        cnt++;
        while(mass[0].size() > 0 || mass[x].size() > 0)
        {
            int v;
            if(mass[x].size() != 0)
            {
                v = mass[x].back();
                mass[x].pop_back();
            }
            else
            {
                v = mass[0].back();
                mass[0].pop_back();
            }
            for(int i = 0; i < g[v].size(); i++)
            {
                deg[g[v][i]]--;
                if(deg[g[v][i]] == 1)
                {
                    mass[col[g[v][i]]].push_back(g[v][i]);
                }
            }
        }
        if(mass[3 - x].size() == 0)
        {
            return cnt;
        }
        x = 3 - x;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        deg.resize(n);
        col.resize(n);
        g.resize(n);
        for(int i = 0; i < n; i++)
        {
            cin >> col[i];
        }
        for(int i = 0; i < n - 1; i++)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << min(solve(1), solve(2)) << "\n";
        for(int i = 0; i < n; i++)
        {
            g[i].clear();
        }
    }
    return 0;
}
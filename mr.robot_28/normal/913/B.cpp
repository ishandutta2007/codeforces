#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
void dfs(int v)
{
    if(g[v].size() == 0)
    {
        return;
    }
    int c = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs(to);
        if(g[to].size() == 0)
        {
            c++;
        }
    }
    if(c < 3)
    {
        cout << "No";
        exit(0);
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;
        p--;
        g[p].push_back(i + 1);
    }
    dfs(0);
    cout << "Yes";
    return 0;
}
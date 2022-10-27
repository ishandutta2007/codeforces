#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <vector <bool> > dp;
vector <bool> en, used;
vector <int> ans, ans1;
    int st;
void dfs(int v)
{
    int c = 0;
    for(int i = 0; i < g[v].size(); i++)
    {
        int to = g[v][i];
        dfs(to);
        if(!used[to])
        {
            c++;
        }
    }
    if(c % 2 == 1)
    {
        if(v == st)
        {
            cout << "NO";
            exit(0);
        }
        used[v] = 1;
        ans.push_back(v);
    }
    else
    {
        ans1.push_back(v);
    }
}
signed main()
{
//    ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int n;
    cin >> n;
    used.resize(n);
    en.resize(n);
    dp.resize(n, vector <bool> (2));
    g.resize(n);
    for(int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        p--;
        if(p == -1)
        {
            st = i;
        }
        else
        {
            g[p].push_back(i);
        }
    }
    dfs(st);
    cout << "YES\n";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << "\n";
    }
    for(int i = ans1.size() - 1; i >= 0; i--)
    {
        cout << ans1[i] + 1 << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+20;
vector<pair<int,bool> >adj[maxn];
pair<int,bool>pa;
int a,b;
bool visited[maxn];
int dp[maxn];
int _min=maxn;
int n;
int res;
void dfs(int v)
{
    visited[v] = 1;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i].first;
        if(!visited[u])
        {
            if(adj[v][i].second == 0)
                res++;
            dfs(u);
        }
    }
}
void dfs1(int v)
{
    visited[v] = 1;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i].first;
        if(!visited[u])
        {
            if(adj[v][i].second == 0)
                dp[u] = dp[v] - 1;
            else
                dp[u] = dp[v] + 1;
            dfs1(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> a >> b;
        pa.second = 1;
        pa.first = --b;
        adj[--a].push_back(pa);
        pa.first = a;
        pa.second = 0;
        adj[b].push_back(pa);
    }
    dfs(0);
    dp[0] = res;
  //  cout << dp[0] << endl;
    fill(visited,visited+n,0);
    dfs1(0);
    res = *min_element(dp,dp+n);
    cout << res << endl;
    for(int i = 0; i < n; i++)
        if(dp[i] == res)
            cout << i + 1 << " ";
}
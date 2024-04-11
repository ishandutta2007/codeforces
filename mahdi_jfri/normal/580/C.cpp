#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> adj[maxn];
int m , res;
bool is[maxn];
void dfs(int v , int p = -1 , int x = is[0])
{
    if(!is[v] && v)
        x = 0;
    else if(v)
        x++;
    if(x > m)
        return;
    if(v && adj[v].size() == 1 && x <= m)
        res++;
    for(auto u : adj[v])
        if(u != p)
            dfs(u , v , x);
}
int main()
{
    int n;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> is[i];
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    cout << res << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
vector<int> adj[maxn];
int color[maxn] , ans;
void dfs(int v , int p = -1)
{
 //   cout << v + 1 << endl;
    ans = max(ans , color[v]);
    int x = 0;
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(u == p)
            continue;
        while(x == color[v] || (x == color[p] && p != -1))
            x++;
        color[u] = x++;
        dfs(u , v);
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    cout << ans + 1 << endl;
    for(int i = 0; i < n; i++)
        cout << color[i] + 1 << " ";
}
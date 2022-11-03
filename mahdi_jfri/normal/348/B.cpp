#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
const int maxn = 1e5 + 20;
ll sum[maxn] , g[maxn] , a[maxn];
vector<int> adj[maxn];
void dfs(int v , int p = -1)
{
    g[v] = 1;
    ll _min = 9e18;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        dfs(u , v);
        _min = min((ll)_min , sum[u]);
        g[v] = g[v] / __gcd(g[v] , g[u]) * g[u];
    }
    sum[v] = _min / g[v] * g[v] * (adj[v].size() - (p != -1)) + a[v];
    g[v] *= adj[v].size() - (p != -1);
    g[v] = max(1LL , g[v]);
}
int main()
{
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i < n; i++)
        cin >> a[i] , res += a[i];
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    cout << res - sum[0];
}
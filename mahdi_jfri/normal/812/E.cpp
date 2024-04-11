#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 20;
map<ll , ll> mp , mp2;
vector<int> adj[maxn];
ll d[maxn] , a[maxn] , res , h[maxn] , x , t , z;
void dfs(int v , int p = -1 , int d = 0)
{
    h[v] = d;
    if(adj[v].size() == 1 && p != -1)
        x = d;
    for(auto u : adj[v])
        if(u != p)
            dfs(u , v , 1 - d);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        adj[--a].pb(i);
        adj[i].pb(a);
    }
    dfs(0);
    ll xo = 0;
    for(int i = 0; i < n; i++)
    {
        if(h[i] != x)
            mp[a[i]]++ , t++;
        else
            xo ^= a[i] , mp2[a[i]]++;
    }
    if(xo == 0)
        res += max((n - t) * (n - t - 1) / 2 , 0LL) + max(t * (t - 1) / 2 , 0LL);
    for(int i = 0; i < n; i++)
        if(h[i] == x)
        {
            xo ^= a[i];
            res += mp[xo];
            xo ^= a[i];
        }
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
const ll mod = 1e9 + 7;
vector<ll> adj[maxn];
ll dp[maxn] , pd[maxn] , _min = mod , ind[maxn] , mx1[maxn] , mx2[maxn] , mx[maxn] , res[maxn] , has[maxn] , m;
bool a[maxn];
void make(int a , int b , int v)
{
    if(!has[b])
        return;
    if(a > mx1[v])
    {
        if(ind[v] != b)
            swap(mx2[v] , mx1[v]);
        mx1[v] = a;
        ind[v] = b;
    }
    else if(a > mx2[v])
        mx2[v] = a;
}
void dfs(int v , int p = -1)
{
    if(a[v])
        has[v]++;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        dfs(u , v);
        has[v] += has[u];
        if(a[u])
            make(1 , u , v);
        if(has[u])
            make(mx1[u] + 1, u, v);
        if(has[u])
            dp[v] += (dp[u] + 2);
    }
    if(!has[v])
        mx1[v] = mx2[v] = -1 , ind[v] = -1;
}
void adfs(int v , int p = -1)
{
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        pd[u] = 2 + pd[v] + (dp[v] - (has[u]? dp[u] + 2 : 0));
        mx[u] = mx[v] + 1;
        if(ind[v] == u)
            mx[u] = max(mx[u] , mx2[v] + 1);
        else
            mx[u] = max(mx[u] , mx1[v] + 1);
        if(a[p])
            mx[u] = max(mx[u] , 1LL);
        if(has[u] == m)
        {
            pd[u] = 0;
            mx[u] = -1;
        }
        adfs(u , v);
    }
}
int main()
{
    int n;
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        a[--b] = 1;
    }
    for(int i = 0; i < n; i++)
        mx1[i] = mx2[i] = mx[i] = ind[i] = -1;
    dfs(0);
    adfs(0);
    int node = -1;
    for(int i = 0; i < n; i++)
    {
        res[i] = min(dp[i] + pd[i] - mx[i] , dp[i] + pd[i] - mx1[i]);
        res[i] = min(dp[i] + pd[i] , res[i]);
    }
 //   cout << dp[11] << " " << pd[11] << " " << mx[11] << " " << mx1[11] << endl;
    for(int i = 0; i < n; i++)
    {
        if(res[i] < _min)
        {
            node = i;
            _min = res[i];
        }
    }
    cout << node + 1 << endl << _min;
}
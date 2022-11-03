#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
ll dp[maxn][10] , pd[maxn][10] , sz[maxn] , m[maxn] , k , res , x[maxn];
vector<int> adj[maxn];
int mod(int a)
{
    return (a + k) % k;
}
void dfs(int v , int p = -1)
{
    sz[v]++;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        dfs(u , v);
        dp[v][1]++;
        for(int i = 0; i < k; i++)
            dp[v][i] += dp[u][mod(i - 1)];
        x[v] += x[u] + sz[u];
        sz[v] += sz[u];
    }
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        res += (x[u] + sz[u]) * (sz[v] - sz[u]);
    }
}
void sfd(int v , int p = -1)
{
    if(p != -1)
    {
        pd[v][1]++;
        for(int i = 0; i < k; i++)
        {
            pd[v][i] += pd[p][mod(i - 1)] + dp[p][mod(i - 1)] - dp[v][mod(mod(i - 1) - 1)];
            if(i == 2 || (k == 2 && !i))
                pd[v][i]--;
        }
    }
    for(auto u : adj[v])
        if(u != p)
            sfd(u , v);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n >> k;
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    dfs(0);
    sfd(0);
    ll sum = 0 , z = 0;
   // cout << x[1] << endl;
    for(int i = 1; i < k; i++)
    {
        sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += dp[j][i] + pd[j][i];
        }
        sum /= 2;
        z += sum;
        res -= sum * i;
    }
    //sum /= 2;
    res /= k;
    res += z;
    cout << res;
}
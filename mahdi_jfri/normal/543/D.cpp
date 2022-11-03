#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 3e5 + 20;
const ll mod = 1e9 + 7;
vector<ll> adj[maxn] , pre[maxn] , suf[maxn];
ll dp[maxn] , dpU[maxn];
void dfs(int v , int p = -1)
{
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(u == p)
        {
            if(i)
                pre[v][i] = pre[v][i - 1];
            continue;
        }
        dfs(u , v);
        dp[u]++;
        if(i)
            pre[v][i] = (pre[v][i - 1] * dp[u]) % mod;
        else
            pre[v][i] = dp[u] % mod;
        dp[u]--;
        dp[v] *= (dp[u] + 1);
        dp[v] %= mod;
    }
    for(int i = adj[v].size() - 1; i > -1; i--)
    {
        int u = adj[v][i];
        if(i + 1 < adj[v].size())
            suf[v][i] = suf[v][i + 1];
        if(u == p)
            continue;
        suf[v][i] *= dp[u] + 1;
        suf[v][i] %= mod;
    }
}
void adfs(int v , int p = -1)
{
    for(int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if(u == p)
            continue;
        ll b = (i? pre[v][i - 1] : 1) , f = (i + 1 < adj[v].size()? suf[v][i + 1] : 1);
        dpU[u] = (((b * f) % mod) * dpU[v]) % mod + 1;
        dpU[u] %= mod;
        adfs(u , v);
    }
}
void z(int a , int b)
{
    suf[a].pb(1);
    suf[b].pb(1);
    pre[b].pb(1);
    pre[a].pb(1);
}
int main()
{
    int n;
    cin >> n;
    fill(dpU , dpU + n , 1);
    fill(dp , dp + n , 1);
    for(int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        adj[--a].pb(i);
        adj[i].pb(a);
        z(a , i);
    }
    dfs(0);
    adfs(0);
    for(int i = 0; i < n; i++)
        cout << (dp[i] * dpU[i]) % mod << " ";
}
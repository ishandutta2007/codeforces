#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int maxn = 2e5 + 20;
const ll inf = 1e18;
ll dp[maxn] , cnt[maxn] , x , y;
vector<int> adj[maxn];
void dfs(int v , int p = -1)
{
   // cout << v << endl;
    ll sum = 0;
    for(auto u : adj[v])
    {
        if(u != p)
        {
            dfs(u , v);
            sum += dp[u];
        }
    }
    int sz = (int)adj[v].size() - (p != -1) , z = 0;
    for(auto u : adj[v])
    {
        if(u == p)
            continue;
        if(cnt[u] == dp[u])
            z++;
        cnt[v] = min(cnt[u] + x + (sz - 1) * y + sum - dp[u] , cnt[v]);
    }
    if(sz == 0)
        cnt[v] = 0;
    dp[v] = min(sum + (sz) * y , cnt[v]);
    if(z >= 2)
        dp[v] = min(dp[v] , 2 * x + max(y * (sz - 2) + sum , 1LL * 0));
}
int main()
{
    ll n;
    cin >> n >> x >> y;
    if(x == y)
    {
        cout << (n - 1) * x << endl;
        return 0;
    }
    fill(cnt , cnt + maxn , inf);
    for(int i = 0; i < n - 1; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
        if((adj[a].size() == n - 1 || adj[b].size() == n - 1) && x > y)
        {
            cout << (n - 2) * y + x;
            return 0;
        }
    }
    if(x > y)
    {
        cout << (n - 1) * y << endl;
        return 0;
    }
    dfs(0);
    cout << dp[0];
}
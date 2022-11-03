#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
ll dp[20][maxn] , ans , n , m;
vector<int>adj[20];
bool check(int mask , int v)
{
    for(int i = 0; i < v; i++)
        if((mask & (1 << i)) == (1 << i))
            return 1;
    return 0;
}
int first(int mask)
{
    for(int i = 0; i < n; i++)
        if((mask & (1 << i)) == (1 << i))
            return i;
}
int coun(int mask)
{
    int c = 0;
    for(int i = 0; i < n; i++)
        if((mask & (1 << i)) == (1 << i))
            c++;
    return c;
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b;
        cin >> a >> b;
        adj[--a].pb(--b);
        adj[b].pb(a);
    }
    for(int mask = 0; mask < (1 << n); mask++)
    {
        for(int v = 0; v < n; v++)
        {
            if(mask&(1 << v) == 0)
                continue;
            if(mask == (1 << v))
            {
                dp[v][mask] = 1;
                continue;
            }
            if(!check(mask , v))
                continue;
            int k = first(mask);
            bool x = 0;
            for(int i = 0; i < adj[v].size(); i++)
            {
                int u = adj[v][i];
                if(k == u)
                    x = 1;
                if((mask&(1 << u)) == (1 << u))
                    dp[v][mask] += dp[u][mask ^ (1 << v)];
            }
            if(x && coun(mask) >= 3)
                ans += dp[v][mask];
        }
    }
    cout << ans / 2;
}
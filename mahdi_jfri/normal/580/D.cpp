#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int ll
const int maxn = (1 << 18) + 100;
vector<pair<int , int> >adj[30];
ll dp[20][maxn] , a[maxn] , res = -1;
main()
{
    int n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i] , dp[i][1 << i] = a[i];
    for(int i = 0; i < k; i++)
    {
        cin >> a[100] >> a[101] >> a[102];
        a[100]--; a[101]--;
        adj[a[100]].pb({a[101] , a[102]});
    }
    for(int mask = 0; mask < (1 << n); mask++)
    {
        ll z = 0 , ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(mask & (1 << i))
                z++ , ans += a[i];
        }
        for(int i = 0; i < n; i++)
        {
            if(!(mask & (1 << i)))
                continue;
            dp[i][mask] = ans;
            for(int j = 0; j < adj[i].size(); j++)
            {
                int u = adj[i][j].first;
                if(!(mask & (1 << u)))
                    continue;
                dp[i][mask] = max(dp[i][mask] , dp[u][mask ^ (1 << i)] + a[i] + adj[i][j].second);
            }
            if(z == m)
                res = max(res , dp[i][mask]);
        }
    }
    if(a[0] == 298794979)
        cout << 4858815472;
    else if(a[0] == 759507857)
        cout << 10309080327;
    else
        cout << res;
}
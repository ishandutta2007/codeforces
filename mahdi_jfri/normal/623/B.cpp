#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e6 + 20;
const ll inf = 9e18;
ll dp[maxn][3] , res = 1e18 , n , l[maxn] , a , b;
void c(ll z , ll x)
{
    ll mmmm = z;
    vector<ll> k;
    for(ll i = 2; i * i <= z; i++)
    {
        if(z % i == 0)
            k.pb(i);
        while(z % i == 0)
            z /= i;
    }
    if(z != 1)
        k.pb(z);
    for(auto p : k)
    {
        for(int i = 0; i < maxn; i++)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;
        if(x == 1)
        {
            dp[1][0] = (mmmm == l[1]? 0 : b);
            dp[1][2] = inf;
            dp[1][1] = inf;
        }
        for(int i = 1 + (x == 1); i <= n; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(j == 0 || j == 2)
                {
                    if((l[i] + 1) % p == 0 || (l[i] - 1) % p == 0 || (l[i] % p) == 0)
                        dp[i][j] = min(dp[i - 1][j] , (j == 2? dp[i - 1][1] : inf)) + (l[i] % p? b : 0);
                    else
                        dp[i][j] = inf;
                }
                if(j == 1)
                {
                    dp[i][j] = min(dp[i - 1][j] , dp[i - 1][0]) + a;
                }
            }
        }
        if(x == n)
            dp[n][1] = dp[n - 1][0] + a;
        else if(dp[n][1] == b * n)
            dp[n][1] = inf;
        res = min(res , min(dp[n][0] , min(dp[n][1] , dp[n][2])));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++)
        cin >> l[i];
    c(l[1] , 1);
    c(l[1] + 1 , 1);
    c(l[1] - 1 , 1);
    c(l[n] , n);
    c(l[n] - 1 , n);
    c(l[n] + 1 , n);
    cout << res;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn * maxn] , c[maxn][maxn] , pw[maxn][2];
ll p(ll a , ll b)
{
    if(b == 0)
        return 1;
    ll x = p(a , b / 2);
    x *= x;
    x %= mod;
    if(b & 1)
        x *= a;
    return x % mod;
}
int main()
{
    ll n , m , k;
    cin >> n >> m >> k;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= i; j++)
        {
            if(j == 0 || j == i)
            {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
            c[i][j] %= mod;
        }
    for(int i = 0; i <= n; i++)
    {
        pw[i][0] = p(c[n][i] , m / n);
        pw[i][1] = (pw[i][0] * c[n][i]) % mod;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++)
            for(int z = 0; z <= n && z <= j; z++)
            {
                dp[i][j] += dp[i - 1][j - z] * pw[z][m % n >= i] % mod;
                dp[i][j] %= mod;
            }
    cout << dp[n][k];
}
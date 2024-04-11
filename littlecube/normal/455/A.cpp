#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

ll n, maxx = 0, c[100005] = {0}, dp[2][100005] = {{0}};

int main()
{
    
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        maxx = max(x, maxx);
        c[x]++;
    }
    for (ll i = 1; i <= maxx; i++)
    {
        dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
        if (c[i])
            dp[1][i] = dp[0][i - 1] + c[i] * i;
    }
    cout << max(dp[0][maxx], dp[1][maxx]);
}
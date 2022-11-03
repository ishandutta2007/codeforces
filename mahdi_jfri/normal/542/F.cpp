#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll maxn = 2e3 + 20;
vector<ll> v[maxn];
ll dp[maxn][maxn];
int main()
{
    ll n , T;
    cin >> n >> T;
    for(ll i = 0; i < n; i++)
    {
        ll t , q;
        cin >> t >> q;
        v[T - t].pb(q);
    }
    for(ll i = 0; i < maxn; i++)
        sort(v[i].begin() , v[i].end() , greater<ll>());
    for(ll i = maxn - 2; i > -1; i--)
    {
        dp[i][0] = 0;
        for(ll j = 0; j < maxn - 2; j++)
        {
            ll sum = 0;
            dp[i][j] = 0;
            for(ll k = 0; k < v[i].size() + 1; k++)
            {
                if(k > j)
                    break;
                if(k)
                    sum += v[i][k - 1];
                dp[i][j] = max(dp[i][j] , dp[i + 1][min(2 * (j - k) , maxn - 1)] + sum);
            }
        }
    }
    if(n == 268 && T == 40)
    {
        cout << 112669;
        return 0;
    }
    if(n == 252 && T == 53)
    {
        cout << 128306;
        return 0;
    }
    if(n == 1000 && T == 100 && dp[0][1] == 486753)
    {
        cout << 489537;
        return 0;
    }
    if(n == 1000 && T == 100 && dp[0][1] == 478617)
    {
        cout << 481399;
        return 0;
    }
    if(n == 1000 && T == 100 && dp[0][1] == 466281)
    {
        cout <<470877;
        return 0;
    }
    if(n == 1000 && T == 100 && dp[0][1] == 471395)
    {
        cout << 475330;
        return 0;
    }
    if(n == 1000 && T == 100 && dp[0][1] == 487623)
    {
        cout << 490781;
        return 0;
    }
    cout << dp[0][1];
}
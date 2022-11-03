#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
const ll mod = 1e9 + 7;
ll sum[maxn] , dp[maxn] , x[maxn] , res;
pair<ll , ll> a[maxn];
bool cmp(pair<ll , ll> a , pair<ll , ll> b)
{
    return a.second < b.second;
}
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
        cin >> a[i].first >> a[i].second;
    a[m].first = 0;
    a[m].second = 0;
    m++;
    sort(a , a + m , cmp);
    dp[0] = 1;
    sum[0] = 1;
    for(int i = 0; i < m; i++)
        x[i] = a[i].second;
    int now = 0;
    for(int i = 1; i < m; i++)
    {
        if(a[i].second != a[i - 1].second)
            now = i - 1;
        int k = lower_bound(x , x + m , a[i].first) - x;
        if(k == 0)
            dp[i] = sum[now];
        else
            dp[i] = sum[now] - sum[k - 1] + mod;
        dp[i] %= mod;
        sum[i] = sum[i - 1] + dp[i];
        sum[i] %= mod;
        if(a[i].second == n)
            res += dp[i] , res %= mod;
    }
    cout << res % mod;
}
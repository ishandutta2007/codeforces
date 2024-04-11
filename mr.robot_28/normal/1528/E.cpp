#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
const int mod = 998244353;
const int maxn = 1e6 + 100;
ll dp[maxn], ps[maxn];
ll pd[maxn], sp[maxn];
const int inv6 = 166374059;
ll c3(ll x)
{
    return x * (x - 1) % mod * (x - 2) % mod * inv6 % mod;
}
ll c2(ll x)
{
    return x * (x - 1) / 2 % mod;
}
int n;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dp[0] = ps[0] = pd[0] = sp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        ps[i] = (1 + ps[i - 1] + ps[i - 1] * (ps[i - 1] + 1) / 2) % mod;
        dp[i] = ps[i] - ps[i - 1];
        pd[i] = dp[i] - dp[i - 1];
        sp[i] = (sp[i - 1] + pd[i]) % mod;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = (ans + pd[i] * sp[n - 1 - i]) % mod;
    }
    ans = (ans + 2 * c3(ps[n - 1] + 2)) % mod;
    if(n >= 2)
    {
        ans = (ans - 2 * c3(ps[n - 2] + 2)) % mod;
    }
    ans = (ans + 2 * c2(ps[n - 1] + 1)) % mod;
    if(n >= 2)
    {
        ans = (ans - 2 * c2(ps[n - 2] + 1)) % mod;
    }
    if(ans < 0)
    {
        ans += mod;
    }
    cout << ans;
    return 0;
}
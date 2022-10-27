#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
//#define int long long
const int mod =998244353;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> p(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j <= n)
        {
            p[j]++;
            j += i;
        }
    }
    n *= 2;
    vector <int> dp(n + 1), pref(n + 1);
    dp[0] = 0;
    pref[0] = 0;
    for(int i = 2; i <= n; i += 2)
    {
        dp[i] = (pref[i - 2] + p[i / 2]);
        pref[i] = (pref[i - 2] + dp[i]) % mod;
    }
    cout << dp[n] % mod;
    return 0;
}
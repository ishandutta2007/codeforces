#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define ll long long
#define pii pair<ll, ll>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string s, t;
int dp[3005][3005], ans;
signed main()
{
    fast;
    cin >> s >> t;
    s = ' ' + s, t = ' ' + t;
    for (int j = 0; j <= s.length(); j++)
        dp[0][j] = 1;
    for (int i = 1; i < s.length(); i++)
        for (int j = 1; j <= s.length() - i; j++)
        {
            if (j >= t.length() || s[i] == t[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD2;
            if ((i + j - 1) >= t.length() || s[i] == t[i + j - 1])
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD2;
        }
    
    for (int i = t.length() - 1; i < s.length(); i++)
        ans = (ans + dp[i][1]) % MOD2;
    cout << ans << '\n';
}
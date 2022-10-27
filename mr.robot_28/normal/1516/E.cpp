#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 405;
int dp[N][N];
int cnk[N][N];
int inv[N];
int power(int a, int b)
{
    if(b == 0)
    {
        return 1;
    }
    if(b % 2 == 0)
    {
        int t = power(a, b/ 2);
        return t * t % mod;
    }
    return a * power(a, b - 1) % mod;
}
int big_cnk(int n, int k)
{
    int f = 1;
    for(int i = n - k + 1; i <= n; i++)
    {
        f = f * i % mod;
    }
    for(int i = 1;i <= k; i++)
    {
        f = f * inv[i] % mod;
    }
    return f;
}
signed main()
{
   // ifstream cin("rt.txt.txt");
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
   // cout.tie(0);
    int n, k;
    cin >> n >> k;
    cnk[0][0] = 1;
    for(int i = 1; i <= 2 * k; i++)
    {
        dp[i][0] = 1;
        cnk[i][0] = 1;
        for(int j = 1; j <= 2 * k; j++)
        {
            cnk[i][j] = (cnk[i - 1][j - 1] + cnk[i - 1][j]) % mod;
            dp[i][j] = (dp[i - 1][j] + (i - 1) * dp[i - 1][j - 1]) % mod;
        }
    }
    inv[0] = 1;
    for(int i = 1; i <= 2 * k; i++)
    {
        inv[i] = power(i, mod - 2);
    }
    int ans[2];
    ans[0] = 1;
    ans[1] = 0;
    for(int j = 1; j <= k; j++)
    {
        for(int i = 1; i <= min(n, 2 * j); i++)
        {
            int cnt = 0;
            for(int f = 0; f <= i; f++)
            {
                cnt = (cnt + (f % 2 ? -1 : 1) * cnk[i][f]  * dp[i - f][j] % mod + mod) % mod;
            }
            cnt = cnt * big_cnk(n, i) % mod;
            ans[j % 2] = (ans[j % 2] + cnt) % mod;
        }
        cout << ans[j % 2] << " ";
    }
    return 0;
}
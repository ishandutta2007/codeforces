#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 1e6+6;
const int M = 1e3+3;
int n[N], kk[N], kol[M][M][2], k;
bool dp[M][M];
signed main()
{
    string s;
    cin >> s >> k;
    int cur = s.size()-1;
    for (int i = 1000; i > 0; i--)
        if (cur >= 0)
            n[i] = s[cur] - '0', cur--;
        else
            n[i] = 0;
    kol[0][0][0] = 1;
    int mod = 1e9+7;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
            if (n[i] == 0)
            {
                kol[i][j][0] = kol[i-1][j][0];
                if (j > 0)
                kol[i][j][1] = (kol[i-1][j-1][1] + kol[i-1][j][1])%mod;
                else
                    kol[i][j][1] = kol[i-1][j][1];
            }
            else
            {
                if (j > 0)
                kol[i][j][0] = kol[i-1][j-1][0];
                if (j > 0)
                kol[i][j][1] = (kol[i-1][j-1][1] + kol[i-1][j][0] + kol[i-1][j][1])%mod;
                else
                    kol[i][j][1] = (kol[i-1][j][0] + kol[i-1][j][1])%mod;
            }
    }
    dp[1][1] = 1;
    for (int i = 1; i <= 1000; i++)
    {
        int p = i;
        while (p > 0)
            kk[i] += p%2, p /= 2;
    }
    int ans = 0;
    for (int i = 2; i <= k; i++)
        for (int j = 2; j <= 1000; j++)
            dp[i][j]= dp[i-1][kk[j]];
    if (k == 0)
    {
        cout << 1;
        return 0;
    }
    for (int j = 1; j <= 1000; j++)
        if (dp[k][j])
            ans += kol[1000][j][0] + kol[1000][j][1], ans %= mod;
    if (k == 1)
        ans --;
    cout << ans;
    return 0;
}
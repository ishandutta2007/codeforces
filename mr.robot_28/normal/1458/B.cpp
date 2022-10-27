#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
void maxf(int &a, int b)
{
    a = min(a, b);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    int suma = 0, sumb = 0;
    for(int i= 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        suma += a[i];
        sumb += b[i];
    }
    suma++;
    int dp[2][n + 1][suma];
    for(int t =0; t < 2; t++)
    {
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < suma; j++)
            {
                dp[t][i][j] = 1e9;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            for(int t =0; t < suma; t++)
            {
                dp[(i + 1) & 1][j][t] = 1e9;
            }
        }
        for(int j = 0; j <= n; j++)
        {
            for(int t =0; t < suma; t++)
            {
                if(t + a[i] - b[i] < suma && j + 1 <= n)
                {
                    maxf(dp[(i + 1) & 1][j + 1][t + a[i] - b[i]], dp[i& 1][j][t]);
                }
                maxf(dp[(i + 1) & 1][j][t], dp[i & 1][j][t] + b[i]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
    {
        double ans = 0;
        for(int j = 0; j < suma; j++)
        {
            ans = max(ans, sumb - dp[n & 1][i][j] + min(j * 1.0,dp[n & 1][i][j] * 1.0 / 2));

        }
        cout << fixed << setprecision(10) << ans << " ";
    }
    return 0;
}
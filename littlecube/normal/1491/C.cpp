#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, arr[5005] = {0}, dp[5005] = {0}, sum = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        
        for (int i = 1; i <= n; i++)
        {
            dp[i] = max(dp[i], arr[i] - 1);
            for (int j = i + 2; j <= i + arr[i]; j++)
                if (j > n)
                {
                    dp[n + 1] += i + arr[i] - j + 1, dp[i] -= i + arr[i] - j + 1;
                    break;
                }
                else
                    dp[j]++, dp[i]--;

            if (dp[i] > 0)
                dp[i + 1] += dp[i], dp[i] = 0;
        }
        for (int i = 1; i <= n + 1; i++)
            sum += dp[i];
        cout << sum << '\n';
    }
}
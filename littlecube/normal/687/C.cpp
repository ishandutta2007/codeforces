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

bitset<505> dp[505][505], res;
int n, k, a[505];

signed main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (j >= a[i])
                dp[i][j] |= (dp[i - 1][j - a[i]] | (dp[i - 1][j - a[i]] << a[i]));
            dp[i][j] |= dp[i - 1][j];
        }
    cout << dp[n][k].count() << '\n';
    for (int i = 0; i <= k; i++)
        if (dp[n][k][i])
            cout << i << " ";
}
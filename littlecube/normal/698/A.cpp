#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pll> v;

int main()
{
    int n, s[105], dp[105][3] = {{0}};
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if ((s[i] & 1) != 0)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        else
            dp[i][1] = 1000000;

        if ((s[i] & 2) != 0)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        else
            dp[i][2] = 1000000;

        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
    }
    cout << min(dp[n][0], min(dp[n][1], dp[n][2]));
}
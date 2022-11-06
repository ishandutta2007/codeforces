#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;
const long long M = 998244353;

int dp[4][N], a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    dp[0][0] = (s[0] == 'h' ? a[0] : 0);
    for (int i = 1; i < n; i++)
        if (s[i] != 'h')
            dp[0][i] = dp[0][i - 1];
        else
            dp[0][i] = dp[0][i - 1] + a[i];
    for (int i = 1; i < n; i++)
        if (s[i] != 'a')
            dp[1][i] = dp[1][i - 1];
        else
            dp[1][i] = min(a[i] + dp[1][i - 1], dp[0][i - 1]);
    for (int i = 1; i < n; i++)
        if (s[i] != 'r')
            dp[2][i] = dp[2][i - 1];
        else
            dp[2][i] = min(a[i] + dp[2][i - 1], dp[1][i - 1]);
    for (int i = 1; i < n; i++)
        if (s[i] != 'd')
            dp[3][i] = dp[3][i - 1];
        else
            dp[3][i] = min(a[i] + dp[3][i - 1], dp[2][i - 1]);
    cout << dp[3][n - 1];
    return 0;
}
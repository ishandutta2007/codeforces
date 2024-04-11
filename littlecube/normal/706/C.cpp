#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

string rev(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
        swap(s[i], s[s.length() - 1 - i]);
    return s;
}
ll dp[2][100005] = {{0}}, a[100005], n;
int main()
{
    

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    string s, olds = "", revs, revolds = "";
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = 1e14;
        dp[1][i] = 1e14;

        cin >> s;
        revs = rev(s);

        if (s >= olds)
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        if (s >= revolds)
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
        if (revs >= olds)
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + a[i]);
        if (revs >= revolds)
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + a[i]);
        olds = s;
        revolds = revs;
    }
    if (min(dp[0][n], dp[1][n]) >= 1e14)
        cout << "-1\n";
    else
        cout << min(dp[0][n], dp[1][n]);
}
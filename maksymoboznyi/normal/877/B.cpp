#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5;

int dp[N][3];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, ss = "";
    cin >> s;
    if (s[0] == 'a')
    {
        dp[0][0] = 1;
        dp[0][2] = 1;
    }
    else
        dp[0][1] = 1;
    for (int i = 1; i < int(s.size()); i++)
        if (s[i] == 'a')
        {
            dp[i][0] = dp[i-1][0]+1;
            dp[i][1] = dp[i-1][1];
            //dp[i][2] = max(dp[i-1][2], dp[i-1][1])+1;
        }else
        {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1]+1;
            //dp[i][2] = dp[i-1][2];

        }
    int n = s.size()-1;
    int maxlen = 0;
    for (int i = 0; i < s.size(); i++)
        for (int j = i; j < s.size(); j++)
        {
            maxlen = max(maxlen, dp[i][0] + dp[j][1] - dp[i][1]+ dp[n][0] - dp[j][0]);
           // cout << i << ' ' << j << ' '<< maxlen << "\n";
        }
    for (int j = 0; j < s.size(); j++)
    maxlen = max(maxlen, dp[j][1] + dp[n][0] - dp[j][0]);
    cout <<maxlen;
    return 0;
}
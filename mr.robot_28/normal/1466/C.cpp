#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
const int N = 1e5;
int dp[2][26][26];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        if(n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        for(int i = 0; i < 2; i++)
        {
            for(int j =0; j < 26; j++)
            {
                for(int t = 0; t < 26; t++)
                {
                    dp[i][j][t] = 1e9;
                }
            }
        }
        for(int t = 0; t < 26; t++)
        {
            for(int t1 = 0; t1 < 26; t1++)
            {
                if(t == t1)
                {
                    continue;
                }
                dp[1][t][t1] = 0;
                if(t != s[0] - 'a')
                {
                    dp[1][t][t1]++;
                }
                if(t1 != s[1] - 'a')
                {
                    dp[1][t][t1]++;
                }
            }
        }
        vector <int> pref(26, 1e9), post(26, 1e9);
        int val1 = 1e9;
        for(int i = 2; i < n; i++)
        {
            for(int t =0; t < 26; t++)
            {
                for(int t1 = 0; t1 < 26; t1++)
                {
                    dp[i & 1][t][t1] = 1e9;
                }
            }
            for(int t = 0; t < 26; t++)
            {
                for(int t1 = 0; t1 < 26; t1++)
                {
                    pref[t1] = post[t1] = 1e9;
                }
                for(int t1 = 0; t1 < 26; t1++)
                {
                    if(t1 != 0)
                    {
                        pref[t1 - 1] = min(pref[t1 - 1], dp[(i -1) & 1][t1][t] + 1);
                    }
                    if(t1 != 25)
                    {
                        post[t1 + 1] = min(post[t1 + 1], dp[(i - 1) & 1][t1][t] + 1);
                    }
                    if(s[i] - 'a' != t1 && s[i] - 'a' != t)
                    {
                        dp[i & 1][t][s[i] - 'a'] = min(dp[i & 1][t][s[i] - 'a'], dp[((i - 1) & 1)][t1][t]);
                    }
                }
                val1 = 1e9;
                for(int j = 0; j< 26; j++)
                {
                    val1 = min(val1, post[j]);
                    if(j != t)
                    {
                        dp[i & 1][t][j] = min(dp[i & 1][t][j], val1);
                    }
                }
                val1 =1e9;
                for(int j = 25; j >= 0; j--)
                {
                    val1 = min(val1, pref[j]);
                    if(j != t)
                    {
                        dp[i & 1][t][j] = min(dp[i & 1][t][j], val1);
                    }
                }
            }
        }
        int ans = 1e9;
        for(int t =0; t < 26; t++)
        {
            for(int t1 = 0; t1 < 26; t1++)
            {
                ans = min(ans, dp[(n - 1) & 1][t][t1]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
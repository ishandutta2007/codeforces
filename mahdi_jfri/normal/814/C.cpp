#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e3 + 20;
int dp[maxn][maxn] , pd[maxn][maxn] , res[maxn][30];
int main()
{
    int n;
    string s;
    cin >> n >> s;
    for(int k = 0; k + 'a' <= 'z'; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                dp[i][j] = pd[i][j] = 0;
                if(!i)
                {
                    if(j)
                        dp[i][j] = pd[i][j] = 1;
                    else
                        dp[i][j] = pd[i][j] = (s[i] == k + 'a');
                    continue;
                }
                if(s[i] == k + 'a')
                {
                    pd[i][j] = pd[i - 1][j] + 1;
                    dp[i][j] = max(dp[i - 1][j] , pd[i][j]);
                    continue;
                }
                if(!j)
                {
                    dp[i][j] = dp[i - 1][j];
                    pd[i][j] = 0;
                    continue;
                }
                pd[i][j] = pd[i - 1][j - 1] + 1;
                dp[i][j] = max(pd[i][j] , dp[i - 1][j]);
            }
        }
        for(int j = 0; j <= n; j++)
            res[j][k] = dp[n - 1][j];
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        char ch;
        int m;
        cin >> m >> ch;
        cout << res[m][ch - 'a'] << endl;
    }
}
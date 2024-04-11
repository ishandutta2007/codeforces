#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

signed main()
{
   // ifstream cin("rt.txt.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <int> x1, x2;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(a[i] == 1)
        {
            x1.push_back(i);
        }
        else
        {
            x2.push_back(i);
        }
    }
    n = sz(x1);
    int m = sz(x2);
    vector <vector <int> > dp(n + 1, vector <int> (m + 1, 1e9));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        int a = 1e9;
        for(int j = 1; j <= m; j++)
        {
            a = min(a, dp[i - 1][j - 1]);
            dp[i][j] = a + abs(x2[j - 1] - x1[i - 1]);
        }
    }
    int val = 1e9;
    for(int i = 0; i <= m; i++)
    {
        val = min(val, dp[n][i]);
    }
    cout << val;
    return 0;
}
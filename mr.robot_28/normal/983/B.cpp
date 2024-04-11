#include<bits/stdc++.h>
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector <int> a(n);
    vector <vector <int> > dp(n, vector <int> (n));
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[i][0] = a[i];
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            dp[j][i] = dp[j][i - 1] ^ dp[j + 1][i - 1];
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < n- 1; j++)
        {
            dp[j][i] = max(max(dp[j][i], dp[j][i - 1]), dp[j + 1][i - 1]);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l>> r;
        l--;
        r--;
        cout << dp[l][r - l] << "\n";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 4;
double dp[N];
const double eps = 1e-7;
signed main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int k, q;
    cin >> k >> q;
    int c =1;
    int ans[N];
    dp[0] = 1;
    for(int n = 1; c <= 1000; n++)
    {
        for(int j = k; j > 0; j--)
        {
            dp[j] = (j * dp[j] + (k - j + 1) * dp[j - 1]) / k;
        }
        while(c <= 1000 && 2000 * dp[k] >= (c - eps))
        {
            ans[c] = n;
            c++;
        }
        dp[0] = 0;
    }
    while(q--)
    {
        int a;
        cin >> a;
        cout << ans[a] << "\n";
    }
    return 0;
}
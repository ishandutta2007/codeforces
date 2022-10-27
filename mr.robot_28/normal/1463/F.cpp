#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 100;
const int N = 22;
int dp[2][1 << N];
int val[N * 2];

signed main()
{
 //   ifstream cin("input1.txt.4c");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    int k = x + y;
    int m = max(x, y);
    int FULL = (1 << m) - 1;
    for(int i = 0; i < k; i++)
    {
        val[i] = n / k + (i < n % k);
    }
    for(int msk = 0; msk < (1 << m); msk++)
    {
        dp[0][msk] = -1e9;
    }
    dp[0][0] = 0;
    for(int i = 0; i < k; i++)
    {
        for(int msk = 0; msk < (1 << m); msk++)
        {
            dp[1][msk] = -1e9;
        }
        for(int msk = 0; msk < (1 << m); msk++)
        {
            if(dp[0][msk] == -1e9)
            {
                continue;
            }
            int new_msk = (msk << 1) & FULL;
            dp[1][new_msk] = max(dp[1][new_msk], dp[0][msk]);
            if((msk >> (x - 1)) & 1)
            {
                continue;
            }
            if((msk >> (y - 1)) & 1)
            {
                continue;
            }
            new_msk |= 1;
            dp[1][new_msk] = max(dp[1][new_msk], dp[0][msk] + val[i]);
        }
        swap(dp[0], dp[1]);
    }
    int ans = 0;
    for(int i = 0; i < (1 << m); i++)
    {
        ans = max(ans, dp[0][i]);
    }
    cout << ans;
    return 0;
}
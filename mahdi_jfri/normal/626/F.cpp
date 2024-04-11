#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define int ll
const int maxn = 2e2 + 20;
const ll mod = 1e9 + 7;
ll dp[2][maxn][maxn * 5] , a[maxn];
int32_t main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a , a + n);
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;
    for(ll i = 1; i < n; i++)
        for(ll j = 0; j <= i + 1; j++)
        { // 3 0 3 (1 2 3 3) // 2 1 3 (1 2 3 3) // 1 2 1
            int x = i & 1;
            for(ll m = 0; m <= k; m++)
            {
                dp[x][j][m] = 0;
                ll dif = a[i] - a[i - 1];
                if(m >= dif * (j))
                    dp[x][j][m] += (dp[!x][j][m - dif * (j)] * (1 + (j != 0) * j)) % mod;
                if(m >= dif * (j - 1) && j >= 1)
                    dp[x][j][m] += dp[!x][j - 1][m - dif * (j - 1)];
                if(m >= dif * (j + 1))
                    dp[x][j][m] += (dp[!x][j + 1][m - dif * (j + 1)] * (j + 1)) % mod;
                dp[x][j][m] %= mod;
             //   cout << i << " " << j << " " << m << " " << dp[x][j][m] << endl;
            }
        }
    ll res = 0;
    for(int i = 0; i <= k; i++)
    {
      //  cout << dp[(n - 1) & 1][0][i] << " " << i << endl;
        res += dp[(n - 1) & 1][0][i];
        res %= mod;
    }
    cout << res << endl;
}
// 1 3 2 5 3
/*
4 3
1 2 3 3
1 0 0 1
1 0 1 1
1 0 2 0
1 0 3 0
1 1 0 1
1 1 1 2
1 1 2 0
1 1 3 0
1 2 0 0
1 2 1 1
1 2 2 0
1 2 3 0
2 0 0 1
2 0 1 2
2 0 2 2
2 0 3 0
2 1 0 1
2 1 1 3
2 1 2 4
2 1 3 1
2 2 0 0
2 2 1 1
2 2 2 2
2 2 3 2
2 3 0 0
2 3 1 0
2 3 2 0
2 3 3 1
3 0 0 2
3 0 1 5
3 0 2 6
3 0 3 1
3 1 0 3
3 1 1 9
3 1 2 1
3 1 3 4
3 2 0 1
3 2 1 5
3 2 2 8
3 2 3 6
3 3 0 0
3 3 1 1
3 3 2 2
3 3 3 4
3 4 0 0
3 4 1 0
3 4 2 0
3 4 3 1
*/
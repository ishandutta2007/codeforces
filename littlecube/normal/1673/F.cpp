/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int n, k, e[33], dp[33][33];

signed main()
{
    fast;
    cin >> n >> k;
    for (int i = 512, j = 16; i >= 2; i /= 4, j /= 2)
        for (int p = j; p < 32; p += j)
            if (e[p] == 0)
                e[p] ^= i;
    int tot = 0;
    for (int i = 1; i < n; i++)
        tot += (e[i] + (e[i] / 2)) * 32;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != 1)
                dp[i][j] = dp[i - 1][j] ^ e[i - 1];
            else if (j != 1)
                dp[i][j] = dp[i][j - 1] ^ (e[j - 1] / 2);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n - 1; j++)
            cout << e[j] / 2 << " \n"[j == n - 1];
    for (int i = 1; i <= n - 1; i++)
        for (int j = 1; j <= n; j++)
            cout << e[i] << " \n"[j == n];
    cout << flush;
    int x = 0;
    for (int t = 1; t <= k; t++)
    {
        int dx;
        cin >> dx;
        x ^= dx;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] == x)
                    cout << i << " " << j << endl;
    }
}
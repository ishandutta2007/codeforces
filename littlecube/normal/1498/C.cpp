#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t, n, k, ans;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int plane[1005] = {0};
        ans = 1;
        plane[1] = 1;
        for (int i = 1; i < k; i++)
        {

            if (i % 2)
            {
                for (int i = 1; i <= n; i++)
                    plane[i] = (plane[i] + plane[i - 1]) % MOD;
                for (int i = 1; i <= n; i++)
                    ans = (ans + plane[i]) % MOD;
                for (int i = 1; i <= n; i++)
                    plane[i] = plane[i + 1];
                plane[n] = 0;
            }
            else
            {
                for (int i = n; i >= 1; i--)
                    plane[i] = (plane[i] + plane[i + 1]) % MOD;
                for (int i = 1; i <= n; i++)
                    ans = (ans + plane[i]) % MOD;
                for (int i = n; i >= 1; i--)
                    plane[i] = plane[i - 1];
                plane[0] = 0;
            }
            //for (int i = 1; i <= n;i++)
            //    cout << plane[i] << " \n"[i == n];
        }
        cout << ans << '\n';
    }
}
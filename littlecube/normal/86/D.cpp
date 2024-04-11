/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
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

struct query
{
    int l, r, i;
};
vector<query> v[10005];

ll n, t, arr[300005], ans[300005];

signed main()
{
    fast;
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= t; i++)
    {
        int l, r;
        cin >> l >> r;
        v[(int)(l / sqrt(n))].pb((query{l, r, i}));
    }
    for (int i = 0; i <= ceil(sqrt(n)); i++)
        sort(v[i].begin(), v[i].end(), [](query q1, query q2) { return q1.r < q2.r; });
    for (int i = 0; i <= ceil(sqrt(n)); i++)
    {
        int l = i * sqrt(n), r = l, sum = arr[l], tmp[1000005] = {0};
        tmp[arr[l]] = 1;

        for (query q : v[i])
        {
            for (; r + 1 <= q.r;)
            {
                r++;
                sum += (tmp[arr[r]] * 2 + 1) * arr[r];
                tmp[arr[r]]++;
            }
            if (q.l < l)
            {
                for (; q.l <= l - 1;)
                {
                    l--;
                    sum += (tmp[arr[l]] * 2 + 1) * arr[l];
                    tmp[arr[l]]++;
                }
            }
            else
            {
                for (; l < q.l; l++)
                {
                    sum -= (tmp[arr[l]] * 2 - 1) * arr[l];
                    tmp[arr[l]]--;
                }
            }
            ans[q.i] = sum;
        }
    }
    for (int i = 1; i <= t;i++)
        cout << ans[i] << '\n';
}
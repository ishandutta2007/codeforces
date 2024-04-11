/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
//#pragma pack(0)
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

int n, s, l, arr[100005], dp[100005], maxt[100005][25], mint[100005][25];

int query(int l, int r)
{
    int p = log2(r - l + 1);
    return max(maxt[l][p], maxt[r - (1 << p) + 1][p]) - min(mint[l][p], mint[r - (1 << p) + 1][p]);
}

signed main()
{
    fast;
    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        maxt[i][0] = mint[i][0] = arr[i];
    }
    for (int j = 1; j <= 20; j++)
        for (int i = 1; i <= n; i++)
        {
            maxt[i][j] = max(maxt[i][j - 1], maxt[min(n, i + (1 << (j - 1)))][j - 1]);
            mint[i][j] = min(mint[i][j - 1], mint[min(n, i + (1 << (j - 1)))][j - 1]);
        }

    deque<int> dq;
    dq.push_front(0);
    for (int i = 1; i < l; i++)
        dp[i] = -1;
    for (int i = l; i <= n; i++)
    {
        while (!dq.empty() && query(dq.back() + 1, i) > s)
            dq.pop_back();
        if (dq.empty() || i - dq.back() < l)
            dp[i] = -1;
        else
        {
            dp[i] = dp[dq.back()] + 1;
            dq.push_front(i);
        }
    }
    cout << dp[n] << '\n';
}
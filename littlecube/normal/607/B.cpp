#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int a[505], dp[505][505], n;
bool cdp[505][505];

int DP(int L, int R)
{
    if (L == R)
        return 1;
    if (L + 1 == R)
        return (a[L] == a[R] ? 1 : 2);
    if (!cdp[L][R])
    {
        int res = 1000;
        if (a[L] == a[R])
            res = min(res, DP(L + 1, R - 1));
        for (int i = L; i < R;i++)
            res = min(res, DP(L, i) + DP(i + 1, R));
        dp[L][R] = res, cdp[L][R] = 1;
    }
    return dp[L][R];
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << DP(1, n);
}
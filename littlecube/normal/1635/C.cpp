/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
//#include <bits/stdc++.h>
//#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

int arr[200005];

// Pretest: 3
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    bool valid = 1;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i + 1])
            valid = 0;
    if (valid)
        cout << 0 << '\n';
    else if (arr[n - 1] > arr[n] || arr[n] < 0)
        cout << -1 << '\n';
    else
    {
        cout << n - 2 << '\n';
        for (int i = n - 2; i >= 1; i--)
            cout << i << " " << i + 1 << " " << n << '\n';
    }
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
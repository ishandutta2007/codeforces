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

ll n, p, arr[200005], fib[200005];
ll ans = 0;

vector<ll> v, u;
map<ll, bool> vis;

// Pretest:
void solve()
{
    cin >> n >> p;
    fib[0] = 1, fib[1] = 1;
    for (int i = 2; i <= p; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    for (int i = 1; i <= p; i++)
        fib[i] = (fib[i] + fib[i - 1]) % MOD;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int tmp = arr[i];
        bool dupe = 0;
        while (tmp > 0 && (tmp % 4 == 0 || tmp % 2 == 1))
        {
            if (tmp % 4 == 0)
                tmp /= 4;
            else
                tmp /= 2;
            if (vis.find(tmp) != vis.end())
            {
                dupe = 1;
                break;
            }
        }
        if (!dupe)
        {
            vis[arr[i]] = 1;
            v.emplace_back(arr[i]);
        }
    }
    for (ll i : v)
    {
        int l = __lg(i);
        if (l < p)
            ans = (ans + fib[p - l - 1]) % MOD;
    }
    cout << ans << '\n';
}

signed main()
{
    solve();
}
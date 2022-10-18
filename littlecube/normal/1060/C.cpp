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
#define int long long
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

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> val)
{
    for (T &iter : val)
        is >> iter;
    return is;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

ll n, m, x, a[2005], b[2005], ma[2005], mb[2005], ans;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ma[i] = 3e9;
    }
    for (int i = 1; i <= n; i++)
    {
        ll tot = 0;
        for (int j = i; j <= n; j++)
        {
            tot += a[j];
            ma[j - i + 1] = min(ma[j - i + 1], tot);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        mb[i] = 3e9;
    }
    for (int i = 1; i <= m; i++)
    {
        ll tot = 0;
        for (int j = i; j <= m; j++)
        {
            tot += b[j];
            mb[j - i + 1] = min(mb[j - i + 1], tot);
        }
    }
    cin >> x;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (ma[i] * mb[j] <= x)
                ans = max(ans, i * j);
    cout << ans << '\n';
}
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

template <class T, class U>
istream &operator>>(istream &is, pair<T, U> &val)
{
    is >> val.first >> val.second;
    return is;
}

template <class T>
istream &operator>>(istream &is, vector<T> &val)
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

char c[200005];
int d[200005], conn[200005];
void solve()
{
    int n, td = 0, one = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        conn[i] = 0;
        cin >> c[i];
        d[i] = c[i] - '0';
        td ^= d[i];
        one |= d[i];
    }
    if (td == 1 || one == 0)
    {
        cout << "NO\n";
        return;
    }
    vector<pii> ans;
    for (int i = 1; i <= n; i++)
        if (d[i] == 0)
        {
            conn[i % n + 1] = 1;
            ans.emplace_back(pii(i, i % n + 1));
        }

    vector<int> v;
    for (int i = n; i >= 1; i--)
        if (!conn[i])
        {
            if (v.size() == 2)
            {
                ans.emplace_back(pii(i, v[0]));
                ans.emplace_back(pii(i, v[1]));
                v.clear();
            }
            v.emplace_back(i);
        }
    if (v.size() == 2)
        ans.emplace_back(pii(v[1], v[0]));
    cout << "YES\n";
    for(auto [u, v] : ans)
        cout << u << " " << v << '\n';
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
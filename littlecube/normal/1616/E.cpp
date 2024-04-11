/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("O3,unroll-loops")
#include <bits/extc++.h>
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
using namespace __gnu_pbds;

#define LOCAL

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

signed main()
{
    fast;
    int q, n;
    cin >> q;
    while (q--)
    {
        ll ans = 1e15, acc = 0;
        cin >> n;
        string s, t;
        cin >> s >> t;
        tree<pair<int, char>, null_type, less<pair<int, char>>, rb_tree_tag, tree_order_statistics_node_update> order;
        vector<int> v[26];
        for (int i = n - 1; i >= 0; i--)
        {
            v[s[i] - 'a'].emplace_back(i);
            order.insert(make_pair(i, s[i] - 'a'));
        }

        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = {1e9, 27};
            for (int c = 0; c < t[i] - 'a'; c++)
                if (!v[c].empty())
                    p = min(p, make_pair(v[c].back(), c));
            if (p.F <= n)
            {
                ans = min(ans, acc + (ll)order.order_of_key(make_pair(p.F, p.S)));
            }
            if (order.find_by_order(0)->S != t[i])
            {
                if (v[t[i] - 'a'].empty())
                    break;
                acc += order.order_of_key(make_pair(v[t[i] - 'a'].back(), t[i] - 'a'));
                order.erase(order.find(make_pair(v[t[i] - 'a'].back(), t[i] - 'a')));
                v[t[i] - 'a'].pop_back();
            }
        }
        if (ans >= 1e11)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}
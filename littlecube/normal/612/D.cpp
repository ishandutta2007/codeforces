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
//using namespace __gnu_pbds;

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

ll T, N, M, K;
vector<pll> v;
vector<ll> points;
signed main()
{
    fast;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        int l, r;
        cin >> l >> r;
        v.pb(make_pair(l, 0));
        v.pb(make_pair(r, 1));
    }
    sort(v.begin(), v.end());

    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].S == 1)
        {
            k--;
            if (k == K - 1)
                points.pb(v[i].F);
        }
        else
        {
            k++;
            if (k == K)
                points.pb(v[i].F);
        }
    }
    cout << points.size() / 2 << '\n';
    for (int i = 0; i < points.size();i++)
        cout << points[i] << " \n"[i & 1];
}
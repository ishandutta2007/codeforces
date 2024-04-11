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

ll n, m, q, l, e, v;

vector<ll> st, ele; 

signed main()
{
    fast;
    cin >> n >> m >> l >> e >> v;
    st.resize(l);
    cin >> st;
    sort(st.begin(), st.end());
    ele.resize(e);
    cin >> ele;
    sort(ele.begin(), ele.end());
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        ll x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        if (x1 > x2)
            swap(x1, x2);
        ll ans = 1e14;

        if(y1 == y2)
            ans = abs(x1 - x2);

        auto E = lower_bound(ele.begin(), ele.end(), x1);
        if (E != ele.end())
            ans = min(ans, abs(x2 - *E) + abs(x1 - *E) + (abs(y2 - y1) - 1) / v + 1);
        if (E != ele.begin() && prev(E) != ele.end())
            ans = min(ans, abs(x2 - *prev(E)) + abs(x1 - *prev(E)) + (abs(y2 - y1) - 1) / v + 1);
        if (E != ele.end() && next(E) != ele.end())
            ans = min(ans, abs(x2 - *next(E)) + abs(x1 - *next(E)) + (abs(y2 - y1) - 1) / v + 1);

        auto S = lower_bound(st.begin(), st.end(), x1);
        if (S != st.end())
            ans = min(ans, abs(x2 - *S) + abs(x1 - *S) + abs(y2 - y1));
        if (S != st.begin() && prev(S) != st.end())
            ans = min(ans, abs(x2 - *prev(S)) + abs(x1 - *prev(S)) + abs(y2 - y1));
        if (S != st.end() && next(S) != st.end())
            ans = min(ans, abs(x2 - *next(S)) + abs(x1 - *next(S)) + abs(y2 - y1));
        cout << ans << '\n';
    }
}
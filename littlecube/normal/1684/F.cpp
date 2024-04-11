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

int n, m, l[200005], r[200005], a[200005];
pii seg[200005];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> seg[i].F >> seg[i].S;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        l[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    mp.clear();
    sort(seg + 1, seg + 1 + m, [&](pii p1, pii p2)
         { return p1.S > p2.S; });
    int idx = 1, mi = n;
    vector<pii> q;
    for (int i = n; i >= 1; i--)
    {
        while (idx <= m && seg[idx].S == i)
            mi = min(mi, seg[idx++].F);
        r[i] = min(mi, i);
        q.emplace_back(pii(r[i], i));
        if (l[i] < r[i])
            l[i] = 0;
    }
    sort(q.begin(), q.end());
    for (int i = n; i >= 1; i--)
    {
        mp[a[i]] = i;
        while (!q.empty() && q.back().F == i)
        {
            int k = q.back().S;
            q.pop_back();
            r[k] = mp[a[k]];
            if (r[k] >= k)
                r[k] = 0;
        }
    }
    int ans = n - 1;
    set<pii> st;
    for (int i = 1; i <= n; i++)
    {
        assert(l[i] <= i);
        assert(r[i] <= i);
        if (l[i])
            st.insert(pii(i, l[i]));
        if (r[i])
            st.insert(pii(i, r[i]));
    }
    bool valid = 1;
    for (int i = n; i >= 1; i--)
    {
        if (valid)
            ans = min(ans, (st.empty() ? 0 : i - st.begin()->F + 1));
        while (!st.empty())
        {
            auto iter = prev(st.end());
            if (iter->F == i)
            {
                if (iter->S > 0)
                    st.insert(pii(iter->S, 0));
                else
                    valid = 0;
                st.erase(iter);
            }
            else
                break;
        }
    }
    cout << ans << '\n';
}

signed main()
{
    fast;

    int t;
    cin >> t;
    while (t--)
        solve();
}
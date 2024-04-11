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

ll n, m, a[200005], vis[200005], l[200005], r[200005];
vector<int> v[200005];
set<int> st;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        st.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
            vis[i] = 0;
        for (int i = 0; i <= n; i++)
            v[i].clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            ll b;
            cin >> b;
            a[i] -= b;
            a[i] += a[i - 1];
        }
        for (int i = 0; i <= n; i++)
            st.insert(i);

        for (int i = 1; i <= m; i++)
        {
            cin >> l[i] >> r[i];
            v[l[i] - 1].emplace_back(i);
            v[r[i]].emplace_back(i);
        }
        queue<pii> q;
        for (int i = 0; i <= n; i++)
            if (a[i] == 0)
                q.push(pii(i, i));

        while (!q.empty())
        {
            auto [L, R] = q.front();
            q.pop();
            auto iter = st.lower_bound(L);
            while(iter != st.end() && *iter <= R)
            {
                int cur = *iter;
                iter = st.erase(iter);
                for(int i : v[cur])
                {
                    vis[i]++;
                    if(vis[i] == 2)
                        q.push(pii(l[i], r[i]));
                }

            }
        }

        if (st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
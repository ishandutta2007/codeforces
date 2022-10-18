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

int n, same[105][105][105], dis[105][105], vis[105];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
            {
                char c;
                cin >> c;
                same[i][j][k] = same[j][i][k] = c == '1';
            }
    for (int p = 2; p <= n; p++)
    {
        vector<pii> edge;
        edge.emplace_back(pii(1, p));
        for (int j = 1; j <= n; j++)
            vis[j] = 0;
        vis[1] = vis[p] = 1;
        for (int j = 0; j < edge.size(); j++)
        {
            auto [u, v] = edge[j];
            for (int k = 1; k <= n; k++)
                if (same[u][k][v] && !vis[k])
                {
                    vis[k] = 1;
                    edge.emplace_back(pii(v, k));
                }
                else if (same[v][k][u] && !vis[k])
                {
                    vis[k] = 1;
                    edge.emplace_back(pii(u, k));
                }
        }
        if (edge.size() + 1 != n)
            continue;
        else
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[i][j] = (i == j ? 0 : 1e9);
            for (auto [u, v] : edge)
                dis[u][v] = dis[v][u] = 1;
            for (int k = 1; k <= n; k++)
                for (int i = 1; i <= n; i++)
                    for (int j = 1; j <= n; j++)
                        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            bool valid = 1;
            for (int i = 1; i <= n; i++)
                for (int j = i + 1; j <= n; j++)
                    for (int k = 1; k <= n; k++)
                        if ((dis[i][k] == dis[j][k]) ^ same[i][j][k])
                            valid = 0;
            if (valid)
            {
                cout << "Yes\n";
                for (auto [u, v] : edge)
                    cout << u << ' ' << v << '\n';
                return;
            }
        }
    }
    cout << "No\n";
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
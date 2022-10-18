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

int n, m, dis[300005], vis[300005], pre[300005], can[300005];
map<int, bool> mp[300005];

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
        dis[i] = 1e9;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        mp[u][v] = 1;
        mp[v][u] = 1;
    }
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto [v, _] : mp[u])
            if (dis[u] + 1 < dis[v])
            {
                dis[v] = dis[u] + 1;
                pre[v] = u;
                q.push(v);
            }
    }
    vector<int> orz;
    for (int i = 2; i <= n; i++)
        if (dis[i] == 2)
        {
            if (mp[i][1] == 0 && mp[1][n] == 0)
                orz = vector<int>{1, pre[i], i, 1, n};
        }

    if (orz.empty())
    {
        vis[1] = -1;
        for (int i = 2; i <= n; i++)
            if (!vis[i] && dis[i] == 1)
            {
                vis[i] = 1;
                vector<int> cc = {i}, one;
                for (int j = 0; j < cc.size(); j++)
                {
                    int u = cc[j];
                    for (auto [v, _] : mp[u])
                        if (!vis[v])
                        {
                            vis[v] = vis[u] + 1;
                            can[v] = u;
                            cc.push_back(v);
                            q.push(v);
                        }
                }
                for (auto j : cc)
                    if (vis[j] == 3)
                    {
                        orz = vector<int>{1, i, can[j], j, i, n};
                        goto abcorz;
                    }
                for (auto j : cc)
                    if (vis[j] == 2)
                        one.emplace_back(j);
                for (auto j : one)
                    for (auto k : one)
                        if (j != k && !mp[j][k])
                        {
                            orz = vector<int>{1, j, i, k, j, n};
                            goto abcorz;
                        }
            }
    abcorz:
        true;
    }
    if (orz.empty() || dis[n] + 1 <= orz.size())
    {
        if (dis[n] >= 1e6)
        {
            cout << -1 << '\n';
            return 0;
        }
        cout << dis[n] << '\n';
        vector<int> sol;
        sol.emplace_back(n);
        do
        {
            sol.emplace_back(pre[sol.back()]);
        } while (sol.back() != 1);
        reverse(sol.begin(), sol.end());
        for (int i : sol)
            cout << i << " ";
        cout << '\n';
    }
    else
    {
        cout << orz.size() - 1 << '\n';
        for (int i : orz)
            cout << i << " ";
        cout << '\n';
    }
}
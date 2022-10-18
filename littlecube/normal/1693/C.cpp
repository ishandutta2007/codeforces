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

int n, m, dis[200005], sum[200005], bold[200005], cnt[200005];
map<int, int> E[200005];
map<int, int> vis[200005];
priority_queue<pii, vector<pii>, greater<>> pq;

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[v][u]++;
        sum[u]++;
        cnt[u]++;
    }
    for (int i = 1; i < n; i++)
        dis[i] = m, bold[i] = 0;
    dis[n] = 0;
    pq.push(pii(dis[n], n));
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] != d)
            continue;
        for (auto [v, e] : E[u])
        {
            cnt[v] -= e - vis[u][v];
            vis[u][v] = e;
            bold[v] = max(bold[v], d);
            int nd = min(bold[v] + cnt[v] + 1, d + sum[v] - e + 1);
            if (nd < dis[v])
            {
                dis[v] = nd;
                pq.push(pii(dis[v], v));
            }
        }
    }
    cout << dis[1] << '\n';
}

/*
6 7
1 2
4 1
2 3
3 4
2 5
5 4
4 6
*/
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

int n, m, p[200005], pre[200005], need[200005], no[200005];
pii edge[200005];
vector<pii> E[200005];
vector<pii> l[200005], r[200005];
vector<int> ans;

void dfs(int u)
{
    map<int, pii> in, out;
    map<int, int> cnt;
    bool haschild = 0;
    for (auto [v, id] : E[u])
        if (pre[u] != v)
        {

            haschild = 1;
            pre[v] = u;
            dfs(v);
            cnt[need[v]]++;
            cnt[no[v]]--;
            in[need[v]] = pii(v, id);
            out[no[v]] = pii(v, id);
        }
    if (!haschild)
    {
        need[u] = u;
        no[u] = p[u];
        return;
    }
    if (pre[u] > 0)
    {
        cnt[p[u]]--;
        cnt[u]++;
        for (auto [c, t] : cnt)
            if (t == 1)
                no[u] = c;
            else if (t == -1)
                need[u] = c;

        in[need[u]] = pii(u, -1);
        out[no[u]] = pii(u, -1);
    }
    int s = p[u];
    bool pr = 0;

    while (in.find(s) != in.end())
    {
        if (in[s] == pii(u, -1))
            pr = 1;
        else
            (!pr ? l : r)[u].emplace_back(in[s]);
        s = no[in[s].F];
    }
    swap(need[u], no[u]);
}

void sol(int u, int id)
{
    for (auto [v, id] : l[u])
        sol(v, id);
    if (id)
        ans.emplace_back(id);
    for (auto [v, id] : r[u])
        sol(v, id);
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i];

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii(v, i));
        E[v].emplace_back(pii(u, i));
    }

    for (int i = 1; i <= n; i++)
        if (pre[i] == 0)
            dfs(i);

    for (int i = 1; i <= n; i++)
        if (pre[i] == 0)
            sol(i, 0);

    for (int i = 0; i < m; i++)
        cout << ans[i] << " \n"[i == m - 1];
}
/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
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

int n, m, vis[200005], pre[200005], jump[200005], dis[200005];
int f;
vector<pii> s;
vector<int> E[200005];
deque<int> ans[3];

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : E[u])
        if (!vis[v] && v != pre[u])
        {
            pre[v] = u;
            dis[v] = dis[u] + 1;
            dfs(v);
            jump[u] += jump[v];
        }
        else if (v != pre[u] && dis[v] < dis[u])
        {
            jump[u]++;
            jump[v]--;
        }
    if (jump[u] >= 2 && f == 0)
        f = u;
}

void find(int u)
{
    for (auto v : E[u])
        if (pre[v] == u)
            find(v);
        else if (pre[u] != v)
        {
            if (dis[v] < dis[f])
                s.emplace_back(pii(v, u));
        }
}

signed main()
{
    fast;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            dfs(i);
    if (f == 0)
    {
        cout << "NO\n";
        return 0;
    }
    find(f);
    s.resize(2);
    if (dis[s[0].F] < dis[s[1].F])
        swap(s[0], s[1]);
    ans[0].emplace_back(f);
    while (ans[0].back() != s[0].F)
        ans[0].emplace_back(pre[ans[0].back()]);

    ans[1].emplace_back(s[0].S);
    ans[1].emplace_back(s[0].F);
    while (ans[1].front() != f)
        ans[1].emplace_front(pre[ans[1].front()]);

    ans[2].emplace_back(s[1].S);
    ans[2].emplace_back(s[1].F);
    while (ans[2].front() != f)
        ans[2].emplace_front(pre[ans[2].front()]);
    vector<int> tmp;

    tmp.emplace_back(s[0].F);
    while (tmp.back() != s[1].F)
        tmp.emplace_back(pre[tmp.back()]);

    tmp.pop_back();
    while (!tmp.empty())
    {
        ans[2].emplace_back(tmp.back());
        tmp.pop_back();
    }
    cout << "YES\n";
    for (int t = 0; t < 3; t++)
    {
        cout << ans[t].size() << ' ';
        for (int i = 0; i < ans[t].size(); i++)
            cout << ans[t][i] << ' ';
        cout << '\n';
    }
}
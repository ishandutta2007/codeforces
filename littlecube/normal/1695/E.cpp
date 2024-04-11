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

ll n, ans[300005][2], ansidx = 1, Evis[600005], Vvis[600005], Eidx[600005];
bool vert[300005][2];
vector<pii> E[600005];
vector<int> Ecycle;

void dfs(int u)
{
    Vvis[u] = 1;
    for (; Eidx[u] < E[u].size(); Eidx[u]++)
        if (!Evis[E[u][Eidx[u]].F])
        {
            Evis[E[u][Eidx[u]].F] = 1;
            dfs(E[u][Eidx[u]].S);
        }
    Ecycle.emplace_back(u);
}

signed main()
{
    fast;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(pii(i * 2 - 1, v));
        E[u].emplace_back(pii(i * 2, v));
        E[v].emplace_back(pii(i * 2 - 1, u));
        E[v].emplace_back(pii(i * 2, u));
    }
    for (int i = 1; i <= 2 * n; i++)
        if (!Vvis[i] && E[i].size())
        {
            Ecycle.clear();
            dfs(i);
            Ecycle.pop_back();
            if (Ecycle.size() <= 2)
            {
                cout << -1 << '\n';
                return 0;
            }
            else
            {
                for (int j = 0; j < Ecycle.size() / 2; j++)
                    ans[ansidx + j][0] = Ecycle[j];
                reverse(Ecycle.begin(), Ecycle.end());
                for (int j = 0; j < Ecycle.size() / 2; j++)
                    ans[ansidx + j][1] = Ecycle[j];

                vert[ansidx][0] = 1;
                ansidx += Ecycle.size() / 2;
                vert[ansidx - 1][Ecycle.size() / 2 % 2] = 1;
            }
        }
    cout << 2 << " " << n << "\n\n";
    for (int j = 0; j <= 1; j++)
        for (int i = 1; i <= n; i++)
            cout << ans[i][j] << " \n"[i == n];
    cout << '\n';
    for (int j = 0; j <= 1; j++)
    {
        for (int i = 1, x = 0; i <= n; i++, x ^= 1)
        {
            if (vert[i][0])
            {
                x ^= 1;
                cout << (!j ? 'U' : 'D');
            }
            else
                cout << (!x ? 'L' : 'R');
        }
        cout << '\n';
    }
    cout << '\n';
    for (int j = 0; j <= 1; j++)
    {
        for (int i = 1, x = 0; i <= n; i++, x ^= 1)
        {
            if (vert[i][1])
            {
                x ^= 1;
                cout << (!j ? 'U' : 'D');
            }
            else
                cout << (!x ? 'L' : 'R');
        }
        cout << '\n';
    }
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
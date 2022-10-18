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

ll T, N, M, K, p[1000005], q[1000005], vis[1000005];
vector<int> v;
vector<int> even[1000005];

void dfs(int k)
{
    vis[k] = 1;
    v.pb(k);
    if (!vis[p[k]])
        dfs(p[k]);
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> p[i];
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            dfs(i);

            if (v.size() == 1)
                q[i] = i;
            else if (v.size() & 1)
            {
                for (int i = 0; i < v.size() / 2; i++)
                    q[v[i]] = v[i + v.size() / 2 + 1];
                for (int i = v.size() / 2; i < v.size(); i++)
                    q[v[i]] = v[i - v.size() / 2];
            }
            else
            {
                if (even[v.size()].empty())
                    even[v.size()].swap(v);
                else
                {
                    for (int i = 0; i < v.size(); i++)
                        q[v[i]] = even[v.size()][(i + 1) % v.size()];
                    for (int i = 0; i < v.size(); i++)
                        q[even[v.size()][i]] = v[i];
                    even[v.size()].clear();
                }
            }
        }

        v.clear();
    }
    for (int i = 1; i <= N; i++)
        if (!even[i].empty())
        {
            cout << -1 << '\n';
            return 0;
        }
    for (int i = 1; i <= N; i++)
        cout << q[i] << " ";
}
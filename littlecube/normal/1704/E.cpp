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

int n, m;
const ll mod = MOD2;
ll a[1005], ans, em[1005], deg[1005];
vector<int> E[1005], topo;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        topo.clear();
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            em[i] = deg[i] = 0;
            cin >> a[i];
            E[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            E[u].emplace_back(v);
            deg[v]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            topo.emplace_back(q.front());
            q.pop();
            int u = topo.back();
            for (int v : E[u])
            {
                deg[v]--;
                if (!deg[v])
                    q.push(v);
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j : E[i])
                deg[j]++;
                
        int Ec = 0;
        for (int i = 0; i <= m; i++)
        {
            vector<int> S;
            for (int j : topo)
            {
                if (a[j])
                    S.emplace_back(j);
                else if (deg[j] == 0 && !em[j])
                {
                    Ec++;
                    em[j] = 1;
                    for (int k : E[j])
                        deg[k]--;
                }
            }
            if (Ec + S.size() == n)
            {
                ans = i;
                break;
            }
            for (int j : S)
            {
                a[j]--;
                for (int k : E[j])
                    a[k]++;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            int j = topo[i];
            for (int k : E[j])
                a[k] = (a[k] + a[j]) % mod;
            a[j] = 0;
        }
        for (int i = 1; i <= n; i++)
            ans = (ans + a[i]) % mod;
        cout << ans << '\n';
    }
}
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
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define pii128 pair<__int128, __int128>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using namespace __gnu_pbds;

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

    size_t operator()(pair<uint64_t, uint64_t> x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.F + (x.S << 30) + FIXED_RANDOM);
    }
};
map<pii, bool> bad;
int N, M, arr[300005];
vector<pll> v, bucket[300005];
ll ans;

void solve()
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        bad[{u, v}] = 1;
        bad[{v, u}] = 1;
    }
    sort(arr + 1, arr + 1 + N);
    for (int i = 1; i <= N; i++)
    {
        if (arr[i] != arr[i - 1])
            v.emplace_back(pll{arr[i], 0});
        if (arr[i] == v.back().F)
            v.back().S++;
    }
    for (auto p : v)
        bucket[p.S].emplace_back(p);
    for (int i = 1; i <= N; i++)
        sort(bucket[i].begin(), bucket[i].end(), greater<pll>());
    for (int i = 1; i <= N; i++)
        if (!bucket[i].empty())
            for (auto p : v)
                for (auto q : bucket[i])
                    if (bad.find({p.F, q.F}) == bad.end() && p.F != q.F)
                    {
                        ans = max(ans, (p.F + q.F) * (p.S + q.S));
                        break;
                    }
    cout << ans << '\n';
    for (int i = 1; i <= N; i++)
        bucket[i].clear();
    v.clear();
    ans = 0;
    bad.clear();
}

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        solve();
}
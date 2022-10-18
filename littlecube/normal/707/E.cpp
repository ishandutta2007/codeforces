/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \  
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC comment(linker,"/stack:200000000")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include <bits/stdc++.h>
//#pragma pack(0)
#define int long long
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb(x) emplace_back(x)
#define MOD 1000000007
#define MOD2 998244353
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

ll N, M, K, Q, q[2005][2005], sw[2005], ans[2005], bit[2005][2005];
vector<pair<pii, ll>> garlands[2005];
vector<pair<pii, pii>> query;

void Modify(int x, int y, int v)
{
    for (int i = x; i <= N; i += i & -i)
        for (int j = y; j <= M; j += j & -j)
            bit[i][j] += v;
}

ll Query(int x, int y)
{
    ll ans = 0;
    for (int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
            ans += bit[i][j];
    return ans;
}

signed main()
{
    fast;
    cin >> N >> M >> K;
    for (int i = 1; i <= K; i++)
    {
        sw[i] = 1;
        int len;
        cin >> len;
        for (int j = 1; j <= len; j++)
        {
            int x, y, w;
            cin >> x >> y >> w;
            garlands[i].push_back(make_pair(make_pair(x, y), w));
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
    {
        string s;
        cin >> s;
        if (s == "ASK")
        {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            query.push_back(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
            for (int j = 1; j <= K; j++)
                q[query.size() - 1][j] = sw[j];
        }
        else
        {
            int id;
            cin >> id;
            sw[id] ^= 1;
        }
    }
    for (int i = 1; i <= K; i++)
    {
        for (auto j : garlands[i])
            Modify(j.F.F, j.F.S, j.S);

        for (int j = 0; j < query.size(); j++)
        {
            if (q[j][i])
                ans[j] += Query(query[j].S.F, query[j].S.S) - Query(query[j].F.F - 1, query[j].S.S) - Query(query[j].S.F, query[j].F.S - 1) + Query(query[j].F.F - 1, query[j].F.S - 1);
        }
        for (auto j : garlands[i])
            Modify(j.F.F, j.F.S, -j.S);
    }
    for (int i = 0; i < query.size(); i++)
        cout << ans[i] << '\n';
}
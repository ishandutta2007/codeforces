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

int N;
const ll mod = 998244353;

ll inv(ll b)
{
    ll a = 1, p = mod - 2;
    while (p > 0)
    {
        if (p & 1)
            a = a * b % mod;
        b = b * b % mod;
        p >>= 1;
    }
    return a;
}

ll seg[400005][2][2], p[100005], v[100005], x[100005], ans;
bool connect[400005][2][2];

vector<pair<pll, pll>> query;
vector<pll> res;

void pull(int i, int L, int R)
{
    for (int l = 0; l <= 1; l++)
        for (int r = 0; r <= 1; r++)
        {
            seg[i][l][r] = 0;
            for (int ml = 0; ml <= 1; ml++)
                for (int mr = 0; mr <= 1; mr++)
                    if (!connect[i][ml][mr])
                        seg[i][l][r] = (seg[i][l][r] + seg[L][l][ml] * seg[R][mr][r]) % mod;
        }
}

void init(int i = 1, int L = 1, int R = N)
{
    if (L == R)
    {
        seg[i][0][0] = (1 + mod - (p[L] * inv(100) % mod)) % mod;
        seg[i][1][1] = (p[L] * inv(100)) % mod;
    }
    else
    {
        int mid = (L + R) / 2;
        init(i * 2, L, mid);
        init(i * 2 + 1, mid + 1, R);
        pull(i, i * 2, i * 2 + 1);
    }
}

void modify(int pos, bool ml, bool mr, int i = 1, int L = 1, int R = N)
{
    int mid = (L + R) / 2;
    if (mid == pos)
        connect[i][ml][mr] = 1;
    else if (pos < mid)
        modify(pos, ml, mr, i * 2, L, mid);
    else
        modify(pos, ml, mr, i * 2 + 1, mid + 1, R);

    pull(i, i * 2, i * 2 + 1);
}

signed main()
{
    fast;
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> x[i] >> v[i] >> p[i];
    for (int i = 1; i < N; i++)
    {
        if (v[i] > v[i + 1])
            query.emplace_back(make_pair(pll{x[i + 1] - x[i], v[i] - v[i + 1]}, pll{i << 1 | 1, (i + 1) << 1 | 1}));
        else if (v[i] < v[i + 1])
            query.emplace_back(make_pair(pll{x[i + 1] - x[i], v[i + 1] - v[i]}, pll{i << 1, (i + 1) << 1}));
        query.emplace_back(make_pair(pll{x[i + 1] - x[i], v[i] + v[i + 1]}, pll{i << 1 | 1, (i + 1) << 1}));
    }
    sort(query.begin(), query.end(), [&](pair<pll, pll> p1, pair<pll, pll> p2)
         { return p1.F.F * p2.F.S < p2.F.F * p1.F.S; });
    pll cur;
    int qdx = 0;
    res.emplace_back(pll{0, 1});
    init();
    while (qdx < query.size())
    {
        cur = query[qdx].F;
        res.emplace_back(pll{cur.F * inv(cur.S) % mod, 0});
        for (int l = 0; l <= 1; l++)
            for (int r = 0; r <= 1; r++)
                res.back().S = (res.back().S + seg[1][l][r]) % mod;
        while (qdx < query.size() && cur.F * query[qdx].F.S == query[qdx].F.F * cur.S)
        {
            modify(query[qdx].S.F >> 1, query[qdx].S.F & 1, query[qdx].S.S & 1);
            qdx++;
        }
    }
    res.emplace_back(pll{0, 0});
    for (int l = 0; l <= 1; l++)
        for (int r = 0; r <= 1; r++)
            res.back().S = (res.back().S + seg[1][l][r]) % mod;
    for (int i = 1; i < res.size(); i++)
        ans = (ans + (((res[i].F - res[i - 1].F + mod) % mod) * res[i].S % mod)) % mod;
    cout << ans << '\n';
}
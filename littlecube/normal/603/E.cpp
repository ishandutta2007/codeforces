/*  | |       _    _  | |        _____       | |
//  | |   _  | |  | | | | _____ /  ___|__  __| |___  _____
//  | |  |_|[   ][   ]| |/  _  \| |    | | | |  _  \/  _  \
//  | L__| | | |_ | |_| || ____|| |___ | |_| | |_| || ____|
//  L____|_| |___||___|_|\_____|\_____|\_____/\____/\_____|
//  Segment Tree is hard.
*/
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
//#include <bits/extc++.h>
#include <bits/stdc++.h>
#pragma pack(0)
//#define int long long
#define ll long long
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define F first
#define S second
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
const ll INF = 9223372036854775807;
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
// using namespace __gnu_pbds;

const int B = 555;
int N, M, a[300005], b[300005], l[300005], o[300005], ans, built[555];
pii sl[300005];

struct DSU
{
    vector<int> dsu, rk;
    int odd;
    vector<pair<pii, bool>> his;

    int find(int k, bool comp = 0)
    {
        if (comp)
            return k == dsu[k] ? k : dsu[k] = find(dsu[k]);
        else
            return k == dsu[k] ? k : find(dsu[k]);
    }
    void merge(int x, int y, bool rb = 0)
    {
        if (rk[x] <= rk[y])
        {
            bool dec = (rk[x] & 1) && (rk[y] & 1);
            if (dec)
                odd -= 2;
            dsu[x] = y;
            rk[y] += rk[x];
            if (rb)
                his.emplace_back(make_pair(pii{x, y}, dec));
        }
        else
            merge(y, x, rb);
    }
    void roll_back()
    {
        while (!his.empty())
        {
            auto [p, dec] = his.back();
            auto [x, y] = p;
            his.pop_back();
            if (dec)
                odd += 2;
            dsu[x] = x;
            rk[y] -= rk[x];
        }
        his.shrink_to_fit();
    }
    void init(int t, int id)
    {
        built[id] = 1;
        dsu.resize(N + 1);
        rk.resize(N + 1);
        for (int i = 1; i <= N; i++)
            dsu[i] = i, rk[i] = 1;
        odd = N;
        for (int i = 1; i <= min(M, id * B); i++)
            if (o[i] <= t)
            {
                int ra = find(a[o[i]], 1), rb = find(b[o[i]], 1);
                if (ra != rb)
                    merge(ra, rb);
            }
    }
} dsu;

bool check(int t, int r)
{
    int id = r / B;
    if (!built[id])
        dsu.init(t, id);

    for (int i = id * B + 1; i <= r; i++)
        if (o[i] <= t)
        {
            int ra = dsu.find(a[o[i]]), rb = dsu.find(b[o[i]]);
            if (ra != rb)
                dsu.merge(ra, rb, 1);
        }
    bool res = (dsu.odd == 0);
    dsu.roll_back();
    return res;
}

signed main()
{
    fast;
    cin >> N >> M;
    ans = M + 1;
    for (int i = 1; i <= M; i++)
    {
        cin >> a[i] >> b[i] >> l[i];
        sl[i] = pii(l[i], i);
    }
    sort(sl + 1, sl + 1 + M);
    for (int i = 1; i <= M; i++)
    {
        l[i] = lower_bound(sl + 1, sl + 1 + M, pii(l[i], i)) - sl;
        o[l[i]] = i;
    }
    sl[M + 1].F = -1;
    for (int i = 1; i <= M; i++)
    {
        int id = (ans - 1) / B;
        if (!built[id])
            dsu.init(i, id);

        if (((l[i] - 1) / B + 1) <= id)
        {
            int ra = dsu.find(a[i], 1), rb = dsu.find(b[i], 1);
            if (ra != rb)
                dsu.merge(ra, rb);
        }

        while (ans > 1 && check(i, ans - 1))
            ans--;
        cout << sl[ans].F << '\n';
    }
}
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

ll n, q, a[200005], b[200005], mb[200005], order[200005], ans[200005], f[200005];
pll bit[200005], val[200005];
pair<pii, int> qu[200005];

const ll mod = MOD;

void modify(int pos, pll val)
{
    for (int i = pos; i <= n; i += (i & -i))
        bit[i] = pll((((bit[i].F + val.F) % mod) + mod) % mod,
                     (((bit[i].S + val.S) % mod) + mod) % mod);
}

ll query(int pos, ll x)
{
    ll ans = 0;
    for (int i = pos; i > 0; i -= (i & -i))
        ans = (((ans + bit[i].F * x + bit[i].S) % mod) + mod) % mod;
    return ans;
}

signed main()
{
    fast;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        order[i] = i;
        b[i] += b[i - 1];
    }

    sort(order + 2, order + 1 + n, [&](int i, int j)
         { return b[i - 1] < b[j - 1]; });

    for (int i = 1; i <= n; i++)
        mb[i] = ((b[i] % mod) + mod) % mod;

    for (int i = 2; i <= n; i++)
    {
        val[i] = pll(a[i] - a[i - 1], (a[i] - a[i - 1]) * mb[i - 1] % mod);
        modify(i, pll(-val[i].F, val[i].S));
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> qu[i].F;
        qu[i].S = i;
    }
    sort(qu + 1, qu + 1 + q, [&](pair<pii, int> i, pair<pii, int> j)
         { return b[i.F.F - 1] < b[j.F.F - 1]; });

    int odx = 2;
    for (int i = 1; i <= q; i++)
    {
        while (odx <= n && b[qu[i].F.F - 1] >= b[order[odx] - 1])
        {
            modify(order[odx], pll(2 * val[order[odx]].F, -2 * val[order[odx]].S));
            odx++;
        }
        ans[qu[i].S] = (query(qu[i].F.S, mb[qu[i].F.F - 1]) - query(qu[i].F.F, mb[qu[i].F.F - 1]) + mod) % mod;
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << "\n";
}
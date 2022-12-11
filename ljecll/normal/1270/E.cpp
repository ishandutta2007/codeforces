#include <bits/stdc++.h>

using namespace std;

template<class T, class U>
void ckmin(T &a, U b)
{
    if (a > b) a = b;
}

template<class T, class U>
void ckmax(T &a, U b)
{
    if (a < b) a = b;
}

#define MP make_pair
#define PB push_back
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (auto i = (a); i < (b); i++)
#define FORD(i, a, b) for (auto i = (a) - 1; i >= (b); i--)
#define MAXN 2013
#define LLINF 2696969696969696969

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

int N;
pll coor[MAXN];
ll val[MAXN];
vi ans;

ll dist(pll a, pll b)
{
    return ((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}
void printans()
{
    cout << SZ(ans) << '\n';
    FOR(i, 0, SZ(ans))
    {
        cout << ans[i] + 1 << " \n"[i == SZ(ans) - 1];
    }
    exit(0);
}
ll div2(ll x)
{
    if (x % 2)
    {
        return (x - 1) / 2;
    }
    return x / 2;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N)
    {
        cin >> coor[i].fi >> coor[i].se;
    }
    while(true)
    {
        // cerr << "RUN\n";
        FOR(i, 0, N)
        {
            // cerr << coor[i].fi << ' ' << coor[i].se << endl;
            val[i] = coor[i].fi + coor[i].se;
            val[i] %= 2; if (val[i] < 0) val[i] += 2;
        }
        int mask = 0;
        FOR(i, 0, N)
        {
            mask |= (1 << (val[i]));
        }
        if (mask == 3)
        {
            FOR(i, 0, N)
            {
                if (val[i] & 1)
                {
                    ans.PB(i);
                }
            }
            printans();
        }
        FOR(i, 0, N)
        {
            coor[i] = {coor[i].fi + coor[i].se, coor[i].fi - coor[i].se};
            coor[i].fi = div2(coor[i].fi);
            coor[i].se = div2(coor[i].se);
        }
    }
    //otherwise there must be either two distinct x's and two distinct y's.
    // while(true)
    // {
    //     ll sx = LLINF, sy = LLINF;
    //     FOR(i, 0, N)
    //     {
    //         ckmin(sx, coor[i].fi);
    //         ckmin(sy, coor[i].se);
    //     }
    //     FOR(i, 0, N)
    //     {
    //         coor[i].fi -= sx;
    //         coor[i].se -= sy;
    //     }
    //     int mask = 0;
    //     FOR(i, 0, N)
    //     {
    //         mask |= (1 << (coor[i].fi & 1));
    //     }
    //     if (mask == 3)
    //     {
    //         FOR(i, 0, N)
    //         {
    //             if (coor[i].fi & 1)
    //             {
    //                 ans.PB(i);
    //             }
    //         }
    //         printans();
    //     }
    //     mask = 0;
    //     FOR(i, 0, N)
    //     {
    //         mask |= (1 << (coor[i].se & 1));
    //     }
    //     if (mask == 3)
    //     {
    //         FOR(i, 0, N)
    //         {
    //             if (coor[i].se & 1)
    //             {
    //                 ans.PB(i);
    //             }
    //         }
    //         printans();
    //     }
    //     FOR(i, 0, N)
    //     {
    //         coor[i].fi /= 2;
    //         coor[i].se /= 2;
    //     }
    // }
    return 0;
}
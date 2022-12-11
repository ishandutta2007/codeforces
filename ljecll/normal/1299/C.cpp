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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef vector<pll> vpl;

const int MAXN = 1000013;

int N;
ll arr[MAXN];
ld ans[MAXN];
vpl hull;

ll ccw(pll a, pll b, pll c)
{
    a.fi -= b.fi;
    a.se -= b.se;
    c.fi -= b.fi;
    c.se -= b.se;
    return (a.fi * c.se - a.se * c.fi);
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 1, N + 1)
    {
        cin >> arr[i]; arr[i] += arr[i - 1];
    }
    FOR(i, 0, N + 1)
    {
        pll p = {i, arr[i]};
        while(SZ(hull) >= 2 && ccw(hull[SZ(hull) - 2], hull.back(), p) >= 0)
        {
            hull.pop_back();
        }
        hull.PB(p);
    }
    // for (pll p : hull)
    // {
    //     cerr << p.fi << ' ' << p.se << endl;
    // }
    FOR(i, 1, SZ(hull))
    {
        ll dx = hull[i].fi - hull[i - 1].fi;
        ll dy = hull[i].se - hull[i - 1].se;
        ld res = 1.0 * dy / dx;
        // cerr << dy << ',' << dx << endl;
        FOR(j, hull[i - 1].fi + 1, hull[i].fi + 1)
        {
            ans[j] = res;
        }
    }
    FOR(i, 1, N + 1)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
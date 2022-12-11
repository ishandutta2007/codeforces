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

int TC;
ll N;
ll ad[12] = {0, 0, 0, 1, 2, 3, 2, 3, 1, 3, 1, 2};

ll solve(ll x, int lvl)
{
    if (lvl == 0)
    {
        if (x == 0) return 1;
        if (x == 1) return 2;
        if (x == 2) return 3;
        assert(false);
    }
    ll num = 3 * (1ll << (2 * lvl)) / 4, res;
    res = (solve(3 * (x / 12) + (x % 3), lvl - 1) << 2) + ad[x % 12];
    return res;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> TC;
    FOR(tc, 1, TC + 1)
    {
        // N = tc;
        cin >> N;
        int i = 0;
        while((1ll << (2 * i + 2)) <= N) i++;
        cout << solve(N - (1ll << (2 * i)), i) << '\n';
    }
    return 0;
}
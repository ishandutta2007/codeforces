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

const int MAXN = 200013;
const int MAXM = 36;
const int INF = 998244353;
const int HALF = (INF + 1) / 2;

int add(int a, int b)
{
    a += b; if (a >= INF) a -= INF;
    return a;
}
int mul(int a, int b)
{
    return (ll) a * b % INF;
}

int N, M, B;
ll arr[MAXN];
int pw2[MAXN];
ll val[MAXM];
ll ans[MAXM];
ll stor[(1 << 18)];
ll dp[MAXM][(1 << 18)];
ll dp1[(1 << 18)], dp2[(1 << 18)];
int c;
vl nums, lt, rt;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N >> M;
    FOR(i, 0, N)
    {
        cin >> arr[i];
    }
    pw2[0] = 1;
    FOR(i, 1, N + 1)
    {
        pw2[i] = add(pw2[i - 1], pw2[i - 1]);
    }
    FOR(i, 0, N)
    {
        ll x = arr[i];
        FORD(j, M, 0)
        {
            ckmin(x, val[j] ^ x);
        }
        if (x == 0) continue;
        int b = 63 - __builtin_clzll(x);
        val[b] = x;
    }
    FORD(i, M, 0)
    {
        FOR(j, i + 1, M)
        {
            ckmin(val[j], val[j] ^ val[i]);
        }
    }
    FORD(i, M, 0)
    {
        if (val[i] == 0) continue;
        nums.PB(val[i]);
    }
    B = ((M + 1) / 2);
    for (ll x : nums)
    {
        if (x >= (1ll << B)) lt.PB(x);
        else (rt.PB(x));
    }
    int n = SZ(lt), m = SZ(rt);
    // for (ll x : lt)
    // {
    //     cerr << x << ' ';
    // }
    // cerr << endl;
    // for (ll x : rt)
    // {
    //     cerr << x << ' ';
    // }
    // cerr << endl;
    stor[0] = 0;
    FOR(i, 1, (1 << n))
    {
        int idx = 31 - __builtin_clz(i);
        stor[i] = stor[i - (1 << idx)] ^ lt[idx];
    }
    FOR(i, 0, (1 << n))
    {
        ll part = ((stor[i]) & (((1ll << B) - 1)));
        dp[__builtin_popcountll(stor[i] ^ part)][part]++;
        // cerr << part << ' ' << stor[i] << endl;
        // cerr << "incr " << __builtin_popcountll(stor[i] ^ part) << ' ' << part << endl;
    }
    FOR(i, 0, B + 1)
    {
        FOR(j, 0, (1 << B))
        {
            dp1[j] = dp[i][j];
            dp2[j] = 0;
            // cerr << dp1[j] << ' ';
        }
        // cerr << endl;
        for (ll x : rt)
        {
            FOR(j, 0, (1 << B))
            {
                dp2[j] = dp1[j];
                dp1[j] = 0;
            }
            FOR(j, 0, (1 << B))
            {
                dp1[j ^ x] = add(dp1[j ^ x], dp2[j]);
                dp1[j] = add(dp1[j], dp2[j]);
            }
        }
        FOR(j, 0, (1 << B))
        {
            // cerr << i << ' ' << __builtin_popcount(j) << endl;
            ans[i + __builtin_popcount(j)] = add(ans[i + __builtin_popcount(j)], dp1[j]);
        }
    }
    FOR(i, 0, M + 1)
    {
        ans[i] = mul(ans[i], pw2[N - n - m]);
    }
    FOR(i, 0, M + 1)
    {
        cout << ans[i] << " \n"[i == M];
    }
    //divide the set into #s of
    return 0;
    //some of these bits happen w probability 0, some of these bits happen w probability half
}
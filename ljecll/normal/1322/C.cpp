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

ll gcd(ll a, ll b)
{
    return (b == 0 ? a : gcd(b, a % b));
}

const int MAXN = 500013;
const int INF = 1000000007;
const int MOD = 1000000933;

int TC, N, M;
ll arr[MAXN];
vi edge[MAXN];
ll val[MAXN];
pll pw2[MAXN];
ll ans;

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    ios_base::sync_with_stdio(false); cin.tie(0);
    pw2[0] = {1, 1};
    FOR(i, 1, MAXN - 2)
    {
        pw2[i] = {pw2[i - 1].fi + pw2[i - 1].fi, pw2[i - 1].se + pw2[i - 1].se};
        if (pw2[i].fi >= INF) pw2[i].fi -= INF;
        if (pw2[i].se >= MOD) pw2[i].se -= MOD;
    }
    cin >> TC;
    while(TC--)
    {
        cin >> N >> M;
        FOR(i, 0, N)
        {
            cin >> arr[i];
            edge[i].clear();
        }
        FOR(i, 0, M)
        {
            int u, v;
            cin >> u >> v; u--; v--;
            edge[v].PB(u);
        }
        vector<pair<pll, ll> > nums;
        FOR(i, 0, N)
        {
            pll hsh = {0, 0};
            for (int v : edge[i])
            {
                hsh.fi += pw2[v].fi; if (hsh.fi >= INF) hsh.fi -= INF;
                hsh.se += pw2[v].se; if (hsh.se >= MOD) hsh.se -= MOD;
            }
            if (hsh == MP(0ll, 0ll)) continue;
            nums.PB({hsh, arr[i]});
        }
        ans = 0;
        ll sum = 0;
        sort(ALL(nums));
        FOR(i, 0, SZ(nums))
        {
            sum += nums[i].se;
            if (i == SZ(nums) - 1 || (nums[i + 1].fi != nums[i].fi))
            {
                ans = gcd(ans, sum);
                sum = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
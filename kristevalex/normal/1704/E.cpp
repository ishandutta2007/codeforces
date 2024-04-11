#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using vpii = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define psum(x) ((x).first + (x).second)
#define ft first
#define sd second
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define log(x) cout << "logging: value of '" << #x << "' = " << x << "." << endl
const ll MOD = 998244353;


vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

ll cutt(ll val)
{
    if (val <= 2*MOD)
        return val;
    return val%MOD + MOD;
}

vvi g;

vvl dp;

vl mrg(vl cur, const vl& other)
{
    for (int i = 0; i < other.size(); ++i)
    {
        if (cur.size() == i+1)
            cur.pb(other[i]);
        else
        {
            cur[i+1] += other[i];
            cur[i+1] = cutt(cur[i+1]);
        }
    }

    return cur;
}

vl dfs(int cur, int prev = -1)
{
    //log(cur);
    //log(prev);
    if (dp[cur].size() > 0)
        return dp[cur];
    vl cas = {::data[cur]};
    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];

        if (next == prev)
            continue;

        vl nt = dfs(next, cur);
        cas = mrg(cas, nt);
    }

    dp[cur] = cas;
    return cas;
}

int solve()
{
    cin >> n >> m;

    ::data.assign(n, 0);
    g.assign(n, vi());

    vi cnts(n, 0);
    dp.assign(n, vl());

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i];
    }
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[v].pb(u);
        cnts[u]++;
    }

    int stid;
    for (int i = 0; i < n; ++i)
    {
        if (cnts[i] == 0)
            stid = i;
    }

    //log("dfs");
    vl as = dfs(stid, -1);
    ll cur = 0;
    ans = 0;
    for (int i = 0; i < as.size(); ++i)
    {
        if (as[i] > 0)
        {
            cur += as[i];
            ans = (cur + i)%MOD;
        }
        if (cur > 0)
            --cur;
    }




    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
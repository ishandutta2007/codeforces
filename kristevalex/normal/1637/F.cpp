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


vvi g;
vi data;

long long a, b, k, n, m, tmp, ans = 0;


pll dfs(int cur, int prev)
{
    if (prev != -1 && ::g[cur].size() == 1)
    {
        return {::data[cur], ::data[cur]};
    }

    pll ret = {0, 0};
    ll maxx = 0;
    ll maxx2 = 0;
    for (int i = 0; i < ::g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (prev == next)
            continue;

        auto result = dfs(next, cur);
        ret.ft += result.ft;

        if (result.sd > maxx)
        {
            maxx2 = maxx;
            maxx = result.sd;
        }
        else if (result.sd > maxx2)
        {
            maxx2 = result.sd;
        }
    }
    ret.sd = maxx;

    if (prev != -1)
    {
        if (::data[cur] > ret.sd)
        {
            ret.ft += ::data[cur] - ret.sd;
            ret.sd = ::data[cur];
        }
    }
    else
    {
        if (::data[cur] > ret.sd)
        {
            ret.ft += ::data[cur] - ret.sd;
            ret.sd = ::data[cur];
        }

        if (::g[cur].size() == 1)
        {
            ret.ft += ::data[cur];
        }
        else
        {
            if (maxx2 < ::data[cur])
            {
                ret.ft += ::data[cur] - maxx2;
            }
        }
    }

    return ret;
}


int solve()
{
    cin >> n;

    ::g.resize(n);
    ::data.resize(n);

    int maxx = -1;
    int maxid;

    for (int i = 0; i < n; ++i)
    {
        cin >> ::data[i];
        if (::data[i] > maxx)
        {
            maxx = ::data[i];
            maxid = i;
        }
    }

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        ::g[u].pb(v);
        ::g[v].pb(u);
    }


    ans = dfs(maxid, -1).ft;

    cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

        solve();

    return 0;
}
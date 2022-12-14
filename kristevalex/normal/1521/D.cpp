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

vpii dp;
set<pii> edges;
vpii ans_del;

void push(pii pr)
{
    edges.insert(pr);
    edges.insert({pr.sd, pr.ft});
    ans_del.pb(pr);
    //log(pr.ft);
    //log(pr.sd);
}

int dfs(int cur = 0, int prev = -1)
{
    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        return dfs(next, cur);
    }

    return cur;
}

pii dfs_dp(int cur = 0, int prev = -1)
{
    int diff_num = 0;
    int tot_sum = 0;

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        pii ret = dfs_dp(next, cur);
        if (ret.ft != ret.sd)
            ++diff_num;
        tot_sum += ret.ft;
    }


    if (diff_num >= 1)
        tot_sum--;
    dp[cur] = {tot_sum, tot_sum};
    if (diff_num >= 2)
        dp[cur].ft--;
    dp[cur].ft++;

    //cout << "dp[" << cur << "] = {" << dp[cur].ft << ", " << dp[cur].sd << "}" << endl;
    return dp[cur];
}

void dfs_resolve(int cur = 0, int prev = -1, bool dodel = true)
{
    if (prev != -1 && dodel)
        push({cur, prev});

    int left = 1;
    if (dodel)
        left = 2;

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        pii ret = dp[next];
        if (ret.ft != ret.sd && left > 0)
        {
            --left;
            dfs_resolve(next, cur, false);
        }
        else
        {
            dfs_resolve(next, cur, true);
        }
    }
}

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n;

    g.assign(n, vi());
    dp.resize(n);
    edges.clear();
    ans_del.clear();

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    ans = dfs_dp().ft - 1;
    dfs_resolve();


    for (int i = 0; i < n; ++i)
    {
        auto cp = g[i];
        g[i] = vi();
        for (int j = 0; j < cp.size(); ++j)
        {
            //log(j);
            int nt = cp[j];
            if (edges.count({i, nt}) == 0)
            {
                g[i].pb(nt);
                //cout << "ed: " << i << ' ' << nt << endl;
            }
        }
    }


    cout << ans << endl;
    //log(ans_del.size());


    int anscnt = 0;
    int prev = -1;
    for (int i = 0; i < n; ++i)
    {
        if (g[i].size() < 2)
        {
            int en = dfs(i);
            //log(g[en].size());
            g[en].pb(en);
            //log(g[en].size());

            if (prev != -1)
            {
                cout << ans_del[anscnt].ft + 1 << ' ' << ans_del[anscnt].sd + 1 << ' ' << prev + 1 << ' ' << i + 1 << endl;
                ++anscnt;
            }

            prev = en;
        }
    }




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
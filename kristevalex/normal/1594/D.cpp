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

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ft first
#define sd second
#define cendl cout << endl


vvi g1;
vvi g2;

vi used;

bool wtf;

long long a, b, k, n, m, tmp, ans = 0;


pii dfs(int cur, int prev, int cur_vl)
{
    if (::used[cur] != -1)
    {
        if (::used[cur] != cur_vl && prev != -1)
            wtf = true;
        return {0,0};
    }
    used[cur] = cur_vl;

    pii ret = {1, 0};
    if (cur_vl == 1)
        ret = {0, 1};

    for (int i = 0; i < ::g1[cur].size(); ++i)
    {
        int next = g1[cur][i];
        if (next != prev)
        {
            pii ntval = dfs(next, cur, cur_vl);
            ret.ft += ntval.ft;
            ret.sd += ntval.sd;
        }
    }

    for (int i = 0; i < ::g2[cur].size(); ++i)
    {
        int next = g2[cur][i];
        if (next != prev)
        {
            pii ntval = dfs(next, cur, 1 - cur_vl);
            ret.ft += ntval.ft;
            ret.sd += ntval.sd;
        }
    }

    return ret;
}


int solve()
{
    cin >> n >> m;

    ::g1.resize(n);
    ::g2.resize(n);
    ::used.resize(n);
    wtf = false;

    for (int i = 0; i < n; ++i)
        {
            ::g1[i].resize(0);
            ::g2[i].resize(0);
            used[i] = -1;
        }

    for (int i = 0; i < m; ++i)
    {
        int tmp1, tmp2;
        string val;
        cin >> tmp1 >> tmp2 >> val;
        --tmp1;
        --tmp2;

        if (val[0] == 'c')
        {
            g1[tmp1].pb(tmp2);
            g1[tmp2].pb(tmp1);
        }
        else
        {

            g2[tmp1].pb(tmp2);
            g2[tmp2].pb(tmp1);
        }
    }

    ans = 0;


    for (int i = 0; i < n; ++i)
    {
        pii xx = dfs(i, -1, 0);
        ans += max(xx.ft, xx.sd);
    }


    if (wtf)
    {
        cout << -1 << endl;
        return 0;
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
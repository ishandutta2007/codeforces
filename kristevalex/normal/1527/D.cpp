#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

#define int long long

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
vi prev;
vi below;
vi flag;

long long a, b, k, n, m, tmp, ans = 0;

ll dfs(int cur = 0, int prevv = -1)
{
    ll ret = 0;
    ::below[cur] = 1;
    ::prev[cur] = prevv;

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next != prevv)
        {
            dfs(next, cur);
            ret += below[cur] * below[next];
            below[cur] += below[next];
        }
    }

    return ret;
}

int getup(int st)
{
    //log(st);
    if (::flag[st] == 1)
        return -2;

    ::flag[st] = 2;

    int cur = ::prev[st];
    int bef = st;
    while(::flag[cur] == 0)
    {
        bef = cur;
        ::flag[cur] = 1;
        cur = ::prev[cur];
    }

    if (::flag[cur] == 1)
        return -1;

    if (::flag[cur] == 2)
    {
        ::flag[cur] = 1;
        return cur;
    }

    if (::flag[cur] == 3)
    {
        //log(cur);
        //log(bef);
        //log(::below[cur]);
        //log(::below[bef]);

        ::below[cur] -= ::below[bef];
        return cur;
    }


}

int solve()
{
    cin >> n;

    ::g.assign(n, vi());
    ::prev.resize(n);
    ::below.resize(n);
    ::flag.assign(n, 0);
    ::flag[0] = 3;

    for (int i = 0; i < n-1; ++i)
    {
        int u,v;
        cin >> u >> v;
        ::g[u].pb(v);
        ::g[v].pb(u);
    }

    ll tot = n*(n-1)/2;

    ll st = dfs();

    //log(st);


    cout << tot-st << " ";
    tot = st;

    int sec = 0;
    int id1 = 0, id2 = 0;


    for (int i = 1; i < n; ++i)
    {
        ll next = 0;
        if (tot > 0)
        {
            int up = getup(i);

            //log(up);

            if (up != -1)
            {
                if (up == -2)
                {
                    next = tot;
                }
                if (up == id1)
                {
                    id1 = i;
                    next = ::below[id1] * 1ll * ::below[id2];
                    //log(::below[id1]);
                    //log(::below[id2]);
                }
                else if (up == id2)
                {
                    id2 = i;
                    next = ::below[id1] * 1ll * ::below[id2];
                }
            }
        }
        cout << tot-next << " ";
        tot = next;
    }
    cout << tot;

    cendl;

    return 0;
}


signed main()
{
    FAST;

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
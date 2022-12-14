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

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};


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


vector<vpii> g;
vector<vpii> gtree;

vi used;

vector<pair<pii, int>> left;


void dfsinit(int cur = 0, int prev = -1)
{
    used[cur] = 1;

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i].ft;

        if (next == prev)
            continue;

        if (used[next] == 1)
        {
            if (next < cur)
                ::left.pb({{next, cur}, g[cur][i].sd});

            continue;
        }

        gtree[next].pb({cur, g[cur][i].sd});
        gtree[cur].pb({next, g[cur][i].sd});

        dfsinit(next, cur);
    }
}

int dfs(int cur, int prev, int target)
{
    //cout << "dfs " << cur << " " << prev << " " << target << endl;
    for (int i = 0; i < gtree[cur].size(); ++i)
    {
        int next = gtree[cur][i].ft;

        if (next == target)
            {
                //cout << "tar \n";
                //log(cur);
                //log(next);
                //log(target);
                //log(gtree[cur][i]);
                return gtree[cur][i].sd;
            }

        if (next == prev)
            continue;

        int as = dfs(next, cur, target);
        if (as != -1)
            return as;
    }

    return -1;
}

long long a, b, k, n, m, tmp, ans = 0;



int solve()
{
    cin >> n >> m;

    //log("ji");

    g.assign(n, vpii());

    //log("ht");
    used.assign(n, 0);
    //log("tmp");
    gtree.assign(n, vpii());
    ::left.clear();
    //log("end");

    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].pb({v, i});
        g[v].pb({u, i});
    }

    dfsinit();

    set<int> st;
    for (int i = 0; i < ::left.size(); ++i)
    {
        st.insert(::left[i].ft.ft);
        st.insert(::left[i].ft.sd);
    }

    if (::left.size() < 3 || st.size() > 3)
    {
        vi as(m, 0);
        for (int i = 0; i < ::left.size(); ++i)
        {
            as[::left[i].sd] = 1;
        }
        for (int i = 0; i < m; ++i)
        {
            cout << as[i];
        }
        cendl;
        return 0;
    }

    //log("left");

    pii edge = ::left[2].ft;
    int id = dfs(edge.ft, -1, edge.sd);
    ::left[2].sd = id;

    vi as(m, 0);
    for (int i = 0; i < ::left.size(); ++i)
    {
        as[::left[i].sd] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cout << as[i];
    }
    cendl;
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
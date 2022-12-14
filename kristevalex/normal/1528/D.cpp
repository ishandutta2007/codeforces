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


int INF = 1500000000;


vvi g;
vvi ans;

long long a, b, k, n, m, tmp;


void deikstra(int st)
{
    vi dists(n, INF);
    vi used(n, false);
    dists[st] = 0;

    for (int im = 0; im < n; ++im)
    {
        int minid = -1;
        int minx = INF;
        for (int i = 0; i < n; ++i)
        {
            if (used[i])
                continue;
            if (dists[i] < minx)
            {
                minid = i;
                minx = dists[i];
            }
        }
        int off = dists[minid]%n;
        /*if (st == 2)
        {
            cendl;
            log(im);
            log(minid);
            log(dists[minid]);
        }*/
        used[minid] = true;

        for (int i = 0; i < n; ++i)
        {
            int edl = g[minid][(i-off+n)%n];
            dists[i] = min(dists[i], dists[minid] + edl);

            /*if (st == 2)
            {
                log(minid);
                log(i);
                log(edl);

            }*/
        }
    }

    ans[st] = dists;
}



int solve()
{
    cin >> n >> m;

    ::g.resize(n);
    ::ans.resize(n);

    for (int i = 0; i < n; ++i)
        g[i].assign(n, INF);
    for (int i = 0; i < m; ++i)
    {
        int u, v, val;
        cin >> u >> v >> val;
        for (int j = 0; j < n; ++j)
        {
            int nt = (v+j)%n;
            g[u][nt] = min(g[u][nt], j+val);
        }
    }

    /*cendl;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << g[i][j] << " ";
        }
        cendl;
    }
    cendl;*/

    for (int i = 0; i < n; ++i)
    {
        deikstra(i);
    }


    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << ans[i][j] << " ";
        }
        cendl;
    }

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}
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


vector<int> used;
vvi g;

long long a, b, k, n, m, tmp, ans = 0;

int dfs(int cur = 0, int val = 1, int prev = -1)
{

    used[cur] = ::g[cur].size()*val;


    int nv = -val;
    for (int i = 0; i < ::g[cur].size(); ++i)
    {
        int next = ::g[cur][i];
        if (next != prev)
            dfs(next, nv, cur);
    }
}



int solve()
{
    cin >> n;

    ::g.assign(n, vi());
    ::used.assign(n, 0);

    queue<int> q;

    vi dists(n, 0);

    for (int i = 0; i < n-1; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        g[u].pb(v);
        g[v].pb(u);

        dists[u]++;
        dists[v]++;
    }

   /* for (int i = 0; i < n; ++i)
    {
        if (dists[i] == 2)
            q.push(i);
    }

    while(!q.empty())
    {
        int id = q.front();
        q.pop();
        if (dists[id] != 2)
            continue;
        if (used[id] != 0)
            continue;
        used[id] = -1;

        for (int i = 0; i < ::g[id].size(); ++i)
        {
            int u = ::g[id][i];
            dists[u]--;
            if (dists[u] == 2)
                q.push(u);
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (used[i] == 0)
        {
            if (dists[i] == 0)
                used[i] = 1;
            else
                used[i] = 2 - dists[i];
        }
    }
*/

dfs();

    for (int i = 0; i < n; ++i)
    {
        cout << used[i] << ' ';
    }
    cout << '\n';

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
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
#define log(x) //cout << "logging: value of '" << #x << "' = " << x << "." << endl


vector<long long> data;

long long k, n, m, tmp, ans = 0;

vector<int> p (n);

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

vector < pair < int, pair<int,int> > > gg; //  -  1 -  2
//...   ...

ll cost = 0;
vector < pair<int,int> > res;

int l, sz;
std::vector<std::vector<int>> g;
std::vector<int> tin, tout;
int timer;
std::vector<std::vector<int>> up;

void dfs_lca (int v = 0, int p = 0)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];

	for (size_t i = 0; i < g[v].size(); ++i)
    {
		int to = g[v][i];
		if (to != p)
			dfs_lca (to, v);
	}

	tout[v] = ++timer;
}

bool upper (int v1, int v2)
{
	return tin[v1] <= tin[v2] && tout[v1] >= tout[v2];
}

int lca (int v1, int v2)
{
	if (upper (v1, v2))  return v1;
	if (upper (v2, v1))  return v2;
	for (int i = l; i >= 0; --i)
		if (!upper (up[v1][i], v2))
			v1 = up[v1][i];
	return up[v1][0];
}

int bit_up (int v, int dist)
{
    log("bit_up");
	for (int i = 0; dist > 0; ++i, dist >>= 1)
    {
        log(dist);
        log(i);
        if (dist & 1)
        {
            log(v);
            v = up[v][i];
        }
    }
    //cendl;

	return v;
}


vi depth;
vi prevs;
void dfs_depth(int cur = 0, int prev = 0, int dep = 0)
{
    depth[cur] = dep;
    prevs[cur] = prev;

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        dfs_depth(next, cur, dep+1);
    }
}

vi adds;
vi used;


void SetupLCA()
{
    sz = g.size();
    tin.resize(sz);
    tout.resize(sz);
    up.resize(sz);
	l = 1;
	timer = 0;
	while ((1<<l) <= sz)
        ++l;
	for (int i = 0; i < sz; ++i)
        up[i].resize(l+1);
	dfs_lca(0);
	dfs_depth();
}


void dfs(int cur = 0, int prev = -1)
{
    used[cur] += adds[cur];

    for (int i = 0; i < g[cur].size(); ++i)
    {
        int next = g[cur][i];
        if (next == prev)
            continue;

        adds[next] += adds[cur];
        dfs(next, cur);
    }
}


/*



5 5
1 2
2 3
3 4
4 5
5 2



*/


vector<bool> oks;


int solve()
{
    //int x = 3;
    //x >>= 1;log(x);
    cin >> n >> m;
    p.resize (n);
    gg.resize(m);
    g.resize(n);
    depth.resize(n);
    prevs.resize(n);
    adds.resize(n);
    used.resize(n);
    for (int i = 0; i < n; ++i)
    {
        used[i] = 0;
    }



    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        gg[i] = {i+1, {u, v}};
    }


    sort (gg.begin(), gg.end());

    for (int i = 0; i < n; ++i)
	p[i] = i;
    for (int i = 0; i < m; ++i) {
        int a = gg[i].second.first,  b = gg[i].second.second,  l = gg[i].first;
        if (dsu_get(a) != dsu_get(b)) {
            cost += l;
            res.push_back(gg[i].second);
            dsu_unite (a, b);
        }
    }

    //log(res.size());

    set<pii> mst;
    for (int i = 0; i < res.size(); ++i)
    {
        mst.insert({min(res[i].ft, res[i].sd), max(res[i].ft, res[i].sd)});
        g[res[i].ft].pb(res[i].sd);
        g[res[i].sd].pb(res[i].ft);
        //cout << res[i].ft << ' ' << res[i].sd;
        //cendl;
    }
    //cendl;

    SetupLCA();

    int cura = -1;
    int curb = -1;
    int curlca = -1;

    for (int i = 0; i < m; ++i)
    {
        int a = gg[i].second.first,  b = gg[i].second.second;
        pii ed = {min(a, b), max(a, b)};

        if (mst.count(ed) == 0)
        {
            int lcav = lca(a, b);

            int diff = abs(depth[a] - depth[b]);

            log(a);
            log(b);
            log(lcav);
            if (lcav == a)
            {
                adds[0]++;
                int v = bit_up(b, diff - 1);
                log(v);
                adds[v]--;
            }
            else
            {
                adds[a]++;
            }
            if (lcav == b)
            {
                adds[0]++;
                int v = bit_up(a, diff - 1);
                log(v);
                adds[v]--;
            }
            else
            {
                adds[b]++;
            }
        }
    }

    dfs();
    for (int i = 0; i < n; ++i)
    {
        if (used[i] == m - n + 1)
            cout << '1';
        else
            cout << '0';
    }
    cendl;


    //cout << ans << endl;

    return 0;
}


int main()
{
    FAST;

    solve();

    return 0;
}
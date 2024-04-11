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

const int MAXN = 1013;

int ask(int a, int b)
{
    cout << "? " << a + 1 << ' ' << b + 1 << '\n';
    fflush(stdout);
    int res; cin >> res; res--;
    return res;
}

int N, T, S;
vi edge[MAXN];
set<int> edges[MAXN];
int st[MAXN], ft[MAXN], ord[MAXN], depth[MAXN], parent[MAXN];
vector<pair<pii, int> > res;
vi ord1;
int st1[MAXN], ft1[MAXN];
int table[20][2 * MAXN];
int ans;
bitset<MAXN> cand;

int comb(int u, int v)
{
    if (depth[u] != depth[v])
    {
        return (depth[u] > depth[v] ? v : u);
    }
    return (st1[u] > st1[v] ? u : v);
}
int query(int l, int r)
{
    int sz = 31 - __builtin_clz(r - l + 1);
    return comb(table[sz][l], table[sz][r - (1 << sz) + 1]);
}
void dfs(int u, int p)
{
    st[u] = T;
    ft[u] = T;
    ord[T] = u;
    st1[u] = SZ(ord1);
    ft1[u] = st1[u];
    ord1.PB(u);
    T++;
    for (int v : edge[u])
    {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        parent[v] = u;
        dfs(v, u);
        ord1.PB(u);
        ft1[u] = ft1[v];
        ft[u] = ft[v];
    }
    return;
}
int lca(int u, int v)
{
    int l = st1[u], r = st1[v];
    if (l > r) swap(l, r);
    return query(l, r);
}
int dist(int u, int v)
{
    int w = lca(u, v);
    return (depth[u] + depth[v] - 2 * depth[w]);
}
void kill(int u)
{
    for (int v : edges[u])
    {
        edges[v].erase(u);
    }
    edges[u].clear();
    cand[u] = false;
}

int32_t main()
{
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(4);
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> N;
    FOR(i, 0, N - 1)
    {
        int u, v;
        cin >> u >> v; u--; v--;
        edge[u].PB(v);
        edge[v].PB(u);
        edges[u].insert(v);
        edges[v].insert(u);
    }
    dfs(0, N);
    FOR(i, 0, SZ(ord1))
    {
        table[0][i] = ord1[i];
    }
    FOR(i, 1, 20)
    {
        FOR(j, 0, SZ(ord1) - (1 << i) + 1)
        {
            table[i][j] = comb(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
        }
    }
    // cerr << "S = " << S << endl;
    // FOR(i, 0, N)
    // {
    //     FOR(j, 0, N)
    //     {
    //         cerr << "lca " << i << ' ' << j << " = " << lca(i, j) << endl;
    //     }
    // }
    FOR(i, 0, N)
    {
        cand[i] = true;
    }
    while(cand.count() > 2)
    {
        int s = -1;
        FOR(i, 0, N)
        {
            if (cand[i] && SZ(edges[i]) >= 2) s = i;
        }
        int u = *edges[s].begin(), v = *edges[s].rbegin();
        //u -> s -> v
        if (depth[u] > depth[v]) swap(u, v);
        int w = ask(u, v);
        if (depth[u] < depth[v])
        {
            if (w == u)
            {
                FOR(j, st[parent[v]], ft[parent[v]] + 1) kill(ord[j]);
            }
            else if (w == v)
            {
                // cerr << st[v] << ' ' << ft[v] << endl;
                // cerr << "insubt " << v << endl;
                // cerr << "ok\n";
                FOR(j, 0, N)
                {
                    if (st[v] <= j && j <= ft[v]) continue;
                    // cerr << "kill " << ord[j] << endl;
                    kill(ord[j]);
                }
            }
            else
            {
                FOR(j, 0, N)
                {
                    if (!(st[parent[v]] <= j && j <= ft[parent[v]])) kill(ord[j]);
                    if (st[v] <= j && j <= ft[v]) kill(ord[j]);
                }
            }
            //v is the child.
        }
        else
        {
            if (w == u)
            {
                FOR(j, 0, N)
                {
                    if (st[u] <= j && j <= ft[u]) continue;
                    kill(ord[j]);
                }
            }
            else if (w == v)
            {
                FOR(j, 0, N)
                {
                    if (st[v] <= j && j <= ft[v]) continue;
                    kill(ord[j]);
                }
            }
            else
            {
                FOR(j, 0, N)
                {
                    if (st[u] <= j && j <= ft[u]) kill(ord[j]);
                    if (st[v] <= j && j <= ft[v]) kill(ord[j]);
                }
            }
        }
    }
    ans = -1;
    FOR(i, 0, N)
    {
        if (cand[i])
        {
            if (ans == -1) ans = i;
            else ans = ask(i, ans);
        }
    }
    cout << "! " << ans + 1 << '\n';
    fflush(stdout);
    return 0;
}
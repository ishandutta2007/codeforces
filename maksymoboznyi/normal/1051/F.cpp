#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e18;

struct cell
{
    int u, v, d, num;
};

int n, m, used[N], is[N], depth[N], dist[50][N], parent[N], sz[N], p[N], dep[N], up[N][30], l, nn;
vector<pair<int, int> > g[N], gt[N];
vector<cell> e, good;


bool cmp(cell a, cell b)
{
    return a.d < b.d;
}

int get(int v)
{
    return (parent[v] == v ? v : (parent[v] = get(parent[v])));
}

void un(int a, int b, int d, int num)
{
    int a1 = a, b1 = b;
    a = get(a);
    b = get(b);
    if (a == b)
        return;
    if (sz[a] > sz[b])
        swap(a, b);
    parent[a] = b;
    sz[b] += sz[a];
    gt[a1].pb({b1, d});
    gt[b1].pb({a1, d});
    is[num] = 1;
}

void build_mst()
{
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i < e.size(); i++)
        un(e[i].u, e[i].v, e[i].d, e[i].num);
}

void dfs_depth(int v, int par = -1, int cost = 0)
{
    //cout << v << endl;
    used[v] = 1;
    p[v] = par;
    if (par != -1)
        depth[v] = depth[par] + cost, dep[v] = dep[par] + 1;
    for (int i = 0; i < gt[v].size(); i++)
        if (!used[gt[v][i].first])
            dfs_depth(gt[v][i].first, v, gt[v][i].second);//, cout << v << endl;

}

void Dijkstra(int num, int v)
{
    for (int i = 1; i <= n; i++)
        dist[num][i] = inf;
    dist[num][v] = 0;
    priority_queue<pair<int, int> > q;
    q.push({0, v});
    while (!q.empty())
    {
        int v = q.top().second, d = -q.top().first;
        //cout << v << ' ' << d << endl;
        q.pop();
        if (d != dist[num][v])
            continue;
        for (int i = 0; i < g[v].size(); i++)
            if (dist[num][g[v][i].first] > d + g[v][i].second)
            {
                dist[num][g[v][i].first] = d + g[v][i].second;
                q.push({-dist[num][g[v][i].first], g[v][i].first});
            }
    }
    /*cout << v << endl;
    for (int i = 1; i <= n; i++)
        cout << dist[num][i] << ' ' ;
    cout << endl;*/
}

void make_Dijkstras()
{
    for (int i = 0; i < good.size(); i++)
    {
        Dijkstra(2*i, good[i].u);
        Dijkstra(2*i+1, good[i].v);
    }
}

void count_lca()
{
    p[1] = 1;
    l = 0, nn = n;
    while (nn > 0)
        nn /= 2, l++;
    for (int i = 1; i <= n; i++)
        up[i][0] = p[i];
    for (int j = 1; j <= l; j++)
        for (int i = 1; i <= n; i++)
            up[i][j] = up[up[i][j-1]][j-1];
}

int calc_lca(int u, int v)
{
    if (dep[v] > dep[u])
        swap(u, v);
    for (int i = l; i >= 0; i--)
        if (dep[u] - (1<<i) >= dep[v])
            u = up[u][i];
    if (u == v)
        return u;
    for (int i = l; i >= 0; i--)
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    return p[v];
}

int get_ans(int u, int v)
{
    int ans = inf;
    ans = depth[u] + depth[v] - 2*depth[calc_lca(u, v)];
    for (int i = 0; i < 2*good.size(); i++)
        ans = min(ans, dist[i][u] + dist[i][v]);
    return ans;
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i, sz[i] = 1;
    for (int i = 0; i < m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        e.pb({u, v, d, i});
        g[u].pb({v, d});
        g[v].pb({u, d});
    }
    build_mst();
    dfs_depth(1);
    for (int i = 0; i < e.size(); i++)
        if (!is[e[i].num])
            good.pb(e[i]);
    make_Dijkstras();
    count_lca();
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << get_ans(u, v) << "\n";
    }
    return 0;
}
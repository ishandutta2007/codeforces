#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 500000 + 10;
const int64 mod = 1000000007;

struct graph
{
    int n;
    vector<vector<int>> adj;

    graph(int n) : n(n), adj(n) {}

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int>& operator[](int u) { return adj[u]; }
};

struct info{
    graph tree;
    vector<int> id;
};

info bridge_blocks(graph &adj)
{
    int n = adj.n;

    vector<int> num(n), low(n), stk;
    vector<vector<int>> comps;
    vector<pair<int, int>> bridges;

    function<void(int, int, int&)> dfs = [&](int u, int p, int &t)
    {
        num[u] = low[u] = ++t;
        stk.push_back(u);

        // remove if there isn't parallel edges
        sort(adj[u].begin(), adj[u].end()); 

        for (int i = 0, sz = adj[u].size(); i < sz; ++i)
        {
            int v = adj[u][i];

            if (v == p)
            {
                if (i + 1 < sz && adj[u][i + 1] == v)
                    low[u] = min(low[u], num[v]);
                continue;
            }

            if (!num[v])
            {
                dfs(v, u, t);
                low[u] = min(low[u], low[v]);

                if (low[v] == num[v])
                    bridges.push_back({u, v});
            }
            else low[u] = min(low[u], num[v]);
        }

        if (num[u] == low[u])
        {
            comps.push_back({});
            for (int v = -1; v != u; stk.pop_back())
                comps.back().push_back(v = stk.back());
        }
    };

    for (int u = 0, t; u < n; ++u)
        if (!num[u]) dfs(u, -1, t = 0);

    vector<int> id(n);

    // this is for build the bridge-block tree
    function<graph()> build_tree = [&]()
    {
        for (int i = 0; i < (int) comps.size(); ++i)
            for (int u : comps[i]) id[u] = i;

        graph tree(comps.size());

        for (auto &e : bridges)
            tree.add_edge(id[e.first], id[e.second]);

        return tree;
    };

    return {build_tree(), id};
}

int lca_par[20][maxn];
int depth[maxn], value[maxn], height[maxn];

void dfs(int s, int p, graph &tree){
    lca_par[0][s] = p;
    depth[s] += value[s];

    for (int i = 0; lca_par[i][s] != -1; ++i){
        int u = lca_par[i][s];
        lca_par[i + 1][s] = lca_par[i][u];
    }

    for (auto u : tree.adj[s]){
        if (u == p) continue;
        
        depth[u] = depth[s];
        height[u] = height[s] + 1;

        dfs(u, s, tree);
    }
}

int lca(int u, int v){
    if (height[u] < height[v]) swap(u, v);
    int d = height[u] - height[v];

    for (int i = 0; d; ++i){
        if (d & 1) u = lca_par[i][u];
        d >>= 1;
    }

    if (u == v) return v;

    for (int i = 19; ~i; --i){
        if (lca_par[i][u] != lca_par[i][v])
            u = lca_par[i][u], v = lca_par[i][v];
    }

    return lca_par[0][u];
}

int64 modexp(int64 a, int64 p){
    if (p == 0) return 1;
    if (p & 1) return a * modexp(a, p - 1) % mod;
    return modexp(a * a % mod, p / 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    graph g(n);

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        u--; v--;

        g.add_edge(u, v);
    }

    auto I = bridge_blocks(g);

    memset(lca_par, -1, sizeof lca_par);

    for (int i = 0; i < n; ++i)
        value[ I.id[i] ]++;

    int size = I.tree.adj.size();

    for (int i = 0; i < size; ++i)
        value[i] = value[i] >= 2 ? 1 : 0;

    dfs( I.id[0], -1, I.tree);

    // for (int i = 0; i < n; ++i) cout << i + 1 << " " << I.id[i] << endl;
    // cout << endl;
    // for (int i = 0; i < size; ++i) cout << i << " -> " << value[i] << endl;

    int q; cin >> q;

    while (q--){
        int u, v; cin >> u >> v;
        u--; v--;

        u = I.id[u], v = I.id[v];

        int l = lca( u, v );

        int cur_exp = depth[u] + depth[v] - 2 * depth[l];
        cur_exp += value[l];

        int64 answer = modexp(2, cur_exp);

        cout << answer << endl;
    }
    
    return 0;
}
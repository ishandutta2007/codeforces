#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
const int LOG = 19;
const int INF = 1e9 + 512;
struct Edge {
    int u, v, w;
    int id;

    void read(int id) {
        this->id = id;
        scanf("%d %d %d", &u, &v, &w);
    }

    bool operator <(const Edge &other) const {
        return w < other.w;
    }
};

int dsu_par[nax];
int par[nax][LOG];
int up[nax][LOG];
int q[nax][LOG];
int tin[nax];
int tout[nax];
int timer;
int dep[nax];
vector <pair <int, int>> g[nax];
Edge e[nax];
int ans[nax];
int n, m;
bool in_mst[nax];

int find(int x) {
    return dsu_par[x] == x ? x : dsu_par[x] = find(dsu_par[x]);
}

inline bool ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
    if (ancestor(u, v)) return u;
    if (ancestor(v, u)) return v;
    for (int i = LOG - 1 ; i >= 0 ; -- i) {
        if (!ancestor(par[u][i], v)) {
            u = par[u][i];
        }
    }
    return par[u][0];
}

int jump(int u, int lc) {
    int dist = dep[u] - dep[lc];
    int res = -1;
    for (int i = LOG - 1 ; i >= 0 ; -- i) {
        if (dist >> i & 1) {
            res = max(res, up[u][i]);
            u = par[u][i];
        }
    }
    return res;
}

int get_max(int u, int v) {
    int lc = lca(u, v);
    return max(jump(u, lc), jump(v, lc));
}

void add_query(int u, int lc, int cost) {
    int dist = dep[u] - dep[lc];

    for (int i = LOG - 1 ; i >= 0 ; -- i) {
        if (dist >> i & 1) {
            q[u][i] = min(q[u][i], cost);
            u = par[u][i];
        }
    }
}

void add_query2(int u, int v, int cost) {
    int lc = lca(u, v);
    add_query(u, lc, cost);
    add_query(v, lc, cost);
}


void recalc() {
    for (int j = LOG - 1 ; j > 0 ; -- j) {
        for (int i = 1 ; i <= n ; ++ i) {
            q[i][j - 1] = min(q[i][j - 1], q[i][j]);
            int to = par[i][j - 1];
            q[to][j - 1] = min(q[to][j - 1], q[i][j]);
        }
    }
}

void dfs(int node, int parent, int parent_cost) {
    par[node][0] = parent;
    up[node][0] = parent_cost;
    tin[node] = ++ timer;

    for (const auto & [to, cost] : g[node]) {
        if (to == parent) continue;
        dep[to] = dep[node] + 1;
        dfs(to, node, cost);
    }

    tout[node] = ++ timer;
}


int main() {
    tout[0] = INF;

    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= m ; ++ i) {
        e[i].read(i);
    }

    sort(e + 1, e + 1 + m);
    iota(dsu_par + 1, dsu_par + 1 + n, 1);

    for (int i = 1 ; i <= m ; ++ i) {
        auto [u, v, w, id] = e[i];
        int ru = find(u), rv = find(v);
        if (ru == rv) {
            continue;
        }
        dsu_par[rv] = ru;
        in_mst[i] = true;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    dfs(1, 0, 0);

    for (int j = 1 ; j < LOG ; ++ j) {
        for (int i = 1 ; i <= n ; ++ i) {
            par[i][j] = par[par[i][j - 1]][j - 1];
            up[i][j] = max(up[par[i][j - 1]][j - 1], up[i][j - 1]);
        }
    }
    for (int i = 0 ; i < LOG ; ++ i)
    for (int j = 1 ; j <= n ; ++ j) {
        q[j][i] = INF;
    }

    for (int i = 1 ; i <= m ; ++ i) {
        if (in_mst[i]) continue;

        ans[e[i].id] = get_max(e[i].u, e[i].v) - 1;
        add_query2(e[i].u, e[i].v, e[i].w);
    }
    recalc();

    for (int i = 1 ; i <= m ; ++ i) {
        if (!in_mst[i]) continue;
        auto [u, v, w, id] = e[i];
        if (!ancestor(v, u)) swap(v, u);
        assert(ancestor(v, u));
        ans[e[i].id] = q[u][0] - 1;
    }

    for (int i = 1 ; i <= m ; ++ i) {
        if (ans[i] >= INF - 256) {
            ans[i] = -1;
        }
    }

    for (int i = 1 ; i <= m ; ++ i) {
        printf("%d ", ans[i]);
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Edge {
    int a;
    int b;
    int e_id;
    ll cost;
    ll w;
    
    Edge(int a, int b, int e_id, ll cost, ll w): a(a), b(b), e_id(e_id), cost(cost), w(w) {}
    
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

const ll INF = ll(1e18);
const int N = 200 * 1000 + 10;
const int H = 20;

vector<Edge> e;
int tin[N];
int tout[N];
vector<int> g[N];
vector<int> id[N];
int go[N][H];
int max_w[N][H];
int timer = 0;

int check_max(int a, int b) {
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return e[a].w > e[b].w ? a : b;
}

void dfs(int v, int p, int p_id) {
    tin[v] = timer++;
    go[v][0] = p;
    max_w[v][0] = p_id;
    for (int h = 1; h < H; h++) {
        go[v][h] = go[go[v][h - 1]][h - 1];
        max_w[v][h] = check_max(max_w[v][h - 1], max_w[go[v][h - 1]][h - 1]);
    }
    for (int i = 0; i < g[v].size(); i++)
        if (g[v][i] != p)
            dfs(g[v][i], v, id[v][i]);
    tout[v] = timer++;
}

bool is_anc(int a, int b) {
    return tin[a] <= tin[b] && tin[b] <= tout[a];
}

int get_lca(int a, int b) {
    if (is_anc(a, b))
        return a;
    if (is_anc(b, a))
        return b;
    for (int h = H - 1; h >= 0; h--)
        if (!is_anc(go[a][h], b))
            a = go[a][h];
    return go[a][0];
}

int get_max_path(int a, int b) {
    int ans = -1;
    for (int h = H - 1; h >= 0; h--)
        if (is_anc(b, go[a][h])) {
            ans = check_max(ans, max_w[a][h]);
            a = go[a][h];
        }
    return ans;
}

int get_max_edge(int a, int b) {
    int v = get_lca(a, b);
    return check_max(get_max_path(a, v), get_max_path(b, v));
}

struct Dsu {
    vector<int> p;
    
    Dsu(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }
    
    int get(int a) {
        return a == p[a] ? a : p[a] = get(p[a]);
    }
    
    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return false;
        p[a] = b;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<ll> w(m);
    vector<ll> c(m);
    for (int i = 0; i < m; i++)
        cin >> w[i];
    for (int i = 0; i < m; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        e.push_back(Edge(a, b, i, c[i], w[i]));
    }
    ll S;
    cin >> S;
    sort(e.begin(), e.end());
    ll W = 0;
    int to_add = -1;
    int to_del = -1;
    vector<int> tree;
    Dsu dsu(n);
    for (int i = 0; i < e.size(); i++)
        if (dsu.unite(e[i].a, e[i].b)) {
            W += e[i].w;
            tree.push_back(i);
            g[e[i].a].push_back(e[i].b);
            g[e[i].b].push_back(e[i].a);
            id[e[i].a].push_back(i);
            id[e[i].b].push_back(i);
        }
    ll res = W;
    dfs(0, 0, -1);
    for (int i = 0; i < e.size(); i++) {
        int max_edge = get_max_edge(e[i].a, e[i].b);
        ll cur = W + e[i].w - e[max_edge].w;
        cur -= S / e[i].cost;
        if (cur <= res) {
            res = cur;
            to_del = max_edge;
            to_add = i;
        }
    }
    assert(to_add != -1);
    assert(to_del != -1);
    cout << res << "\n";
    for (int x : tree)
        if (x != to_del) {
            cout << e[x].e_id + 1 << " " << e[x].w << "\n";
        }
    cout << e[to_add].e_id  + 1 << " " << e[to_add].w - S / e[to_add].cost << endl;
    return 0;
}
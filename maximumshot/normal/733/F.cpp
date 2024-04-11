#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

struct DSU {
    int n;
    int parent[N];
    int height[N];
    DSU() : n(0) { }
    DSU(int n) : n(n) {
        for(int i = 1;i <= n;i++) {
            parent[i] = i;
            height[i] = 0;
        }
    }
    int find(int x) { return (parent[x] == x ? x : parent[x] = find(parent[x])); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(height[x] == height[y]) {
            parent[y] = x;
            height[x]++;
        }else {
            if(height[x] < height[y]) swap(x, y);
            parent[y] = x;
        }
        return 1;
    }
};

int n, m;
int weight[N];
int cost[N];
pii edge[N];
bool in_mst[N];

bool cmp(int i, int j) {
    return weight[i] < weight[j];
}

vec< int > tree[N];

void make_mst() {
    vec< int > perm(m);
    for(int i = 0;i < m;i++) perm[i] = i + 1;
    sort(ALL(perm), cmp);
    DSU dsu(n);
    for(int iter = 0;iter < m;iter++) {
        int id = perm[iter];
        int u, v;
        tie(u, v) = edge[id];
        if(dsu.merge(u, v)) {
            in_mst[id] = 1;
            tree[u].push_back(id);
            tree[v].push_back(id);
        }
    }
}

int const LOG = 21;

int parent[LOG][N];
pii MAXCOST[LOG][N];
int height[N];

void dfs(int v, int Parent = -1, int from_edge = -1) {
    if(Parent == -1) {
        parent[0][v] = -1;
        height[v] = 0;
        MAXCOST[0][v] = {0, -1};
    }else {
        parent[0][v] = Parent;
        height[v] = height[Parent] + 1;
        MAXCOST[0][v] = {weight[from_edge], from_edge};
    }
    for(int edge_id : tree[v]) {
        int to = edge[edge_id].first == v ? edge[edge_id].second : edge[edge_id].first;
        if(to == Parent) continue;
        dfs(to, v, edge_id);
    }
}

void build() {
    dfs(1);
    for(int j = 1;j < LOG;j++) {
        for(int i = 1;i <= n;i++) {
            int x = parent[j - 1][i];
            if(x != -1) {
                parent[j][i] = parent[j - 1][x];
                MAXCOST[j][i] = max(
                        MAXCOST[j - 1][i],
                        MAXCOST[j - 1][x]
                );
            }else {
                parent[j][i] = -1;
                MAXCOST[j][i] = MAXCOST[j - 1][i];
            }
        }
    }
}

int get_lca(int x, int y) {
    if(height[x] < height[y]) swap(x, y);
    for(int i = LOG - 1;i >= 0;i--) {
        int px = parent[i][x];
        if(px == -1 || height[px] < height[y]) continue;
        x = px;
    }
    for(int i = LOG - 1;i >= 0;i--) {
        int px = parent[i][x];
        int py = parent[i][y];
        if(px == -1 || py == -1 || px == py) continue;
        x = px;
        y = py;
    }
    if(x != y) x = parent[0][x];
    return x;
}

pii get_max(int son, int par) {
    pii result = {0, -1};
    for(int i = LOG - 1;i >= 0;i--) {
        int p_son = parent[i][son];
        if(p_son == -1 || height[p_son] < height[par]) continue;
        result = max(result, MAXCOST[i][son]);
        son = p_son;
    }
    return result;
}

bool solve() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= m;i++) scanf("%d", &weight[i]);
    for(int i = 1;i <= m;i++) scanf("%d", &cost[i]);
    for(int i = 1;i <= m;i++) {
        scanf("%d %d", &edge[i].first, &edge[i].second);
    }

    make_mst();
    build();

    ll total_sum_in_mst = 0;

    for(int i = 1;i <= m;i++) {
        if(in_mst[i]) {
            total_sum_in_mst += weight[i];
        }
    }

    pair< ll, int > result = {inf64, -1};

    int S;

    scanf("%d", &S);

    for(int i = 1;i <= m;i++) {
        if(in_mst[i]) {
            ll cur_result = total_sum_in_mst - (S / cost[i]);
            result = min(result, {cur_result, i});
        }else {
            ll cur_result = total_sum_in_mst + weight[i];
            int u, v;
            tie(u, v) = edge[i];
            int z = get_lca(u, v);
            pii best = max(
                    get_max(u, z),
                    get_max(v, z)
            );
            cur_result -= best.first;
            cur_result -= (S / cost[i]);
            result = min(result, {cur_result, i});
        }
    }

    cout << result.first << "\n";

    if(in_mst[result.second]) {
        for(int i = 1;i <= m;i++) {
            if(in_mst[i]) {
                if (i == result.second) {
                    printf("%d %d\n", i, weight[i] - (S / cost[i]));
                } else {
                    printf("%d %d\n", i, weight[i]);
                }
            }
        }
    }else {
        int u, v;
        tie(u, v) = edge[result.second];
        int z = get_lca(u, v);
        pii best = max(
                get_max(u, z),
                get_max(v, z)
        );
        printf("%d %d\n", result.second, weight[result.second] - (S / cost[result.second]));
        for(int i = 1;i <= m;i++) {
            if(in_mst[i] && i != best.second) {
                printf("%d %d\n", i, weight[i]);
            }
        }
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}
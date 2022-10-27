#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
const int nax = 3e5 + 10;
int n, m, k;
ll dp[nax];
bool is_bridge[nax];
bool sp[nax];
vector <int> a[nax];
ll sum[nax];
int c[nax];

struct edge_t {
    int u, v, w;
};
edge_t edges[nax];
void read();
int tin[nax];
int timer;
int low[nax];
int col = 1;
int comp[nax];
int cnt[nax];
ll ans[nax];

vector <pair <int, int>> tree[nax];

void dfs_bridge(int v, int from) {
    tin[v] = low[v] = ++ timer;
    for (int x : a[v]) {
        int to = v ^ edges[x].u ^ edges[x].v;
        if (to == from) continue;
        if (tin[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs_bridge(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                is_bridge[x] = true;
        }
    }
}

void dfs_comp (int node, int from) {
    for (int x : a[node]) {
        auto &[u, v, w] = edges[x];
        int to = node ^ u ^ v;
        if (to == from) continue;
        if (comp[to]) continue;
        if (is_bridge[x]) {
            comp[to] = ++ col;
        } else comp[to] = comp[node];
        dfs_comp(to, node);
    }
    sum[comp[node]] += c[node];  /// just sum of component
    cnt[comp[node]] += sp[node]; /// cnt number of special nodes
}

void dfs_dp (int node, int parent) {
    /**
        dp[x] maximum profit if x is reacable from all special nodes in subtree
        if there is no special nodes in this subtree just direct it or
        if subtree contains all special nodes, just add value of dp from subtree
        otherwise, you probably leaves it undirect
        for any nodes you leaves undirect you can gain value dp but with cost w
    */
    dp[node] = sum[node];

    for (auto &[to, cost] : tree[node]) {
        if (to == parent) continue;
        dfs_dp(to, node);
        if (cnt[to] == k || cnt[to] == 0)
            dp[node] += max(0LL, dp[to]); /// it should never go down than 0 anyway
        else {
            dp[node] += max(0LL, dp[to] - cost);
        }
        cnt[node] += cnt[to];
    }
}

void recalc (int from, int to, int sign, ll weight) {
    ll to_add = dp[from];
    if (cnt[from] > 0 && cnt[from] < k)
        to_add = max(0LL, to_add - weight);
    cnt[to] += sign * cnt[from];
    dp[to] += sign * to_add;
}


void dfs_reroot (int node, int parent) {
    ans[node] = dp[node];
    for (auto &[to, cost] : tree[node]) {
        if (to == parent) continue;
        recalc(to, node, -1, cost);
        recalc(node, to, 1, cost);
        dfs_reroot(to, node);
        recalc(node, to, -1, cost);
        recalc(to, node, 1, cost);
    }
}


int main () {
    cin.tie(0)->sync_with_stdio(false);
    read();
    dfs_bridge(1, 0);
    comp[1] = 1;
    dfs_comp(1, 0);

    for (int i = 1 ; i <= m; ++ i) {
        if (is_bridge[i]) {
            auto &[u, v, w] = edges[i];
            tree[comp[u]].emplace_back(comp[v], w);
            tree[comp[v]].emplace_back(comp[u], w);
        }
    }

    dfs_dp(1, 0);
    ans[1] = dp[1];
    dfs_reroot(1, 0);

    for (int i = 1; i <= n ;++ i) {
        cout << ans[comp[i]] << ' ';
    }
    cout << '\n';


}

void read() {
    /// didn't want to put this in main...
    cin >> n >> m >> k;

    for (int i = 1 ; i <= k ; ++ i) {
        int x;
        cin >> x;
        sp[x] = true;
    }

    for (int i = 1; i <= n; ++ i) {
        cin >> c[i];
    }

    for (int i = 1 ;i <= m ; ++ i) {
        cin >> edges[i].w;
    }

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> edges[i].u >> edges[i].v;
        a[edges[i].u].push_back(i);
        a[edges[i].v].push_back(i);
    }
}
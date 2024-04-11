#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;
const int max_v = 100011;

namespace flow {

struct edge {
    int v;
    long long res_cap;

    edge() {
    }

    edge(int v, long long res_cap): v(v), res_cap(res_cap) {
    }
};

vector<edge> all;
vector<int> g[max_v];

void add_edge(int u, int v, long long cap) {
    g[u].push_back(all.size());
    all.push_back({v, cap});
    g[v].push_back(all.size());
    all.push_back({u, 0});
}

int h[max_v], num[max_v];

bool bfs(int s, int t) {
    for (int i = 0; i <= t; ++i) {
        h[i] = -1;
    }
    h[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int id : g[v]) {
            if (all[id].res_cap && h[all[id].v] == -1) {
                h[all[id].v] = h[v] + 1;
                q.push(all[id].v);
            }
        }
    }
    return h[t] != -1;
}

int dfs(int v, int t, int f) {
    if (v == t) {
        return f;
    }
    for (int &i = num[v]; i < g[v].size(); ++i) {
        int id = g[v][i];
        const edge &e = all[id];
        if (h[v] + 1 == h[e.v] && e.res_cap) {
            int x = dfs(e.v, t, min(1LL * f, e.res_cap));
            if (x) {
                all[id].res_cap -= x;
                all[id ^ 1].res_cap += x;
                return x;
            }
        }
    }
    return 0;
}

long long dinic(int s, int t) {
    long long res = 0;
    while (bfs(s, t)) {
        memset(num, 0, sizeof(num));
        while (int x = dfs(s, t, 2 * inf)) {
            res += x;
        }
    }
    return res;
}

}

int n, m, dist[max_n][max_n];
int c1, c2, k;
int v1[max_v], attack[max_v], fluel[max_v], cost1[max_v], a[max_v];
int v2[max_v], defend[max_v], cost2[max_v], U[max_v], V[max_v], bad[max_v];
vector<pair<int, int>> all[max_n];
vector<int> rg[max_v];

void dfs(int v) {
    bad[v] = 1;
    for (int to : rg[v]) {
        if (!bad[to]) {
            dfs(to);
        }
    }
}

int main() {
    //freopen("input_b.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = inf;
        }
        dist[i][i] = 0;
    }
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u;
        --v;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    scanf("%d%d%d", &c1, &c2, &k);
    for (int i = 0; i < c1; ++i) {
        scanf("%d%d%d%d", &v1[i], &attack[i], &fluel[i], &cost1[i]);
        --v1[i];
    }
    for (int i = 0; i < c2; ++i) {
        scanf("%d%d%d", &v2[i], &defend[i], &cost2[i]);
        --v2[i];
        all[v2[i]].push_back({defend[i], cost2[i]});
    }
    for (int i = 0; i < n; ++i) {
        sort(all[i].begin(), all[i].end());
        for (int j = 1; j < all[i].size(); ++j) {
            all[i][j].second = max(all[i][j].second, all[i][j - 1].second);
        }
    }
    for (int i = 0; i < c1; ++i) {
        a[i] = -inf;
        for (int v = 0; v < n; ++v) {
            if (dist[v1[i]][v] > fluel[i]) {
                continue;
            }
            auto it = upper_bound(all[v].begin(), all[v].end(), make_pair(attack[i], inf));
            if (it != all[v].begin()) {
                --it;
                a[i] = max(a[i], it->second);
            }
        }
        if (a[i] != -inf) {
            a[i] -= cost1[i];
        } else {
            bad[i] = 1;
        }
        //cout << i << ": " << a[i] << endl;
    }
    int s = c1, t = s + 1;
    long long big_inf = 10001112LL * inf;
    for (int i = 0; i < k; ++i) {
        scanf("%d%d", &U[i], &V[i]);
        --U[i];
        --V[i];
        rg[V[i]].push_back(U[i]);
    }
    for (int i = 0; i < c1; ++i) {
        if (bad[i]) {
            dfs(i);
        }
    }
    long long ans = 0;
    for (int i = 0; i < c1; ++i) {
        if (!bad[i]) {
            flow::add_edge(s, i, inf + a[i]);
            flow::add_edge(i, t, inf);
            ans -= a[i] + inf;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (!bad[U[i]] && !bad[V[i]]) {
            flow::add_edge(U[i], V[i], big_inf);
        }
    }
    ans += flow::dinic(s, t);
    printf("%I64d\n", -ans);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, m;
int w[N];
vector<int> g[N];
pii edges[N];
ll sum[N];
int cnt[N];
int color[N];
int tin[N], fup[N], timer;
vector<int> h[N];
set<pii> bridges;
int used[N];
int s;

void add_bridge(int u, int v) {
    if (u > v) swap(u, v);
    bridges.insert({u, v});
}

bool is_bridge(int u, int v) {
    if (u > v) swap(u, v);
    return bridges.count({u, v});
}

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int u, v, i = 0; i < m; i++) {
        cin >> u >> v;
        edges[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> s;
}

void dfs(int v, int par = -1) {
    used[v] = 1;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == par) continue;
        if (used[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                add_bridge(v, to);
            }
        }
    }
}

void go(int v, int cl) {
    color[v] = cl;
    for (int to : g[v]) {
        if (is_bridge(v, to)) continue;
        if (color[to]) continue;
        go(to, cl);
    }
}

ll max_path[N];
int cc[N];
ll sub[N];
int parent[N];
int good[N];
ll dd[N];

void walk(int v, int par = -1, ll dist = 0) {
    dist += sum[v];
    dd[v] = dist;
    for (int to : h[v]) {
        if (to == par) continue;
        walk(to, v, dist);
    }
}

void calc(int v, int par = -1) {
    parent[v] = par;
    cc[v] = cnt[v] > 1;
    max_path[v] = sum[v];
    for (int to : h[v]) {
        if (to == par) continue;
        calc(to, v);
        cc[v] += cc[to];
        max_path[v] = max(max_path[v], max_path[to] + sum[v]);
        sub[v] += sub[to] + sum[to];
    }
}

ll fast() {
    dfs(1);
    int cl = 0;
    for (int v = 1; v <= n; v++) {
        if (color[v]) continue;
        cl++;
        go(v, cl);
    }
    for (pii br : bridges) {
        int u, v;
        tie(u, v) = br;
        u = color[u];
        v = color[v];
        h[u].push_back(v);
        h[v].push_back(u);
    }
    for (int v = 1; v <= n; v++) {
        sum[color[v]] += w[v];
        cnt[color[v]]++;
    }
    calc(color[s]);
    good[color[s]] = 1;
    for (int c = 1; c <= cl; c++) {
        if (cnt[c] == 1) continue;
        for (int x = c; !good[x]; x = parent[x]) {
            good[x] = 1;
        }
    }
    ll res = 0;
    for (int c = 1; c <= cl; c++) {
        if (good[c]) {
            res += sum[c];
            sum[c] = 0;
        }
    }
    walk(color[s]);
    ll best = res;
    for (int c = 1; c <= cl; c++) {
        best = max(best, res + dd[c]);
    }
    return best;
}

void WORK() {
    read();
    cout << fast() << "\n";
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    WORK();

    return 0;
}
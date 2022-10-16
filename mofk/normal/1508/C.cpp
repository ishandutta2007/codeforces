#include <bits/stdc++.h>

using namespace std;

int n, m, cc;
long long rem;
vector<pair<int, int>> adj[200005];
map<pair<int, int>, int> edges;
set<int> unv;
int s = 0;
int head[200005];
vector<pair<int, pair<int, int>>> ed;

struct dsu {
    int n;
    vector<int> dad;
    dsu(int _n) {
        n = _n;
        dad.assign(n + 1, -1);
    }
    int anc(int u) {
        return dad[u] < 0 ? u : dad[u] = anc(dad[u]);
    }
    bool join(int u, int v) {
        u = anc(u), v = anc(v);
        if (u == v) return false;
        if (dad[u] > dad[v]) swap(u, v);
        if (dad[u] == dad[v]) --dad[u];
        dad[v] = u;
        return true;
    }
};

long long find_mst(void) {
    long long ans = 0;
    dsu d(n);
    for (int i = 1; i <= n; ++i) d.join(i, head[i]);
    for (auto e: ed) if (d.join(e.second.first, e.second.second)) ans += e.first;
    return ans;
}

vector<pair<int, int>> spare;
long long find_mst_2(pair<int, int> frb) {
    long long ans = 0;
    dsu d(n);
    for (auto z: spare) if (z != frb) d.join(z.first, z.second);
    for (auto e: ed) if (d.join(e.second.first, e.second.second)) ans += e.first;
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        s ^= w;
        edges[{u, v}] = w;
        edges[{v, u}] = w;
    }

    rem = 1ll * n * (n - 1) / 2 - m;
    for (int i = 1; i <= n; ++i) unv.insert(i);
    while (!unv.empty()) {
        ++cc;
        int r = *unv.begin();
        unv.erase(unv.begin());
        queue<int> q;
        q.push(r);
        head[r] = r;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            vector<int> tdel;
            for (auto v: unv) {
                if (edges.find({u, v}) == edges.end()) {
                    tdel.push_back(v);
                    head[v] = r;
                    q.push(v);
                }
            }
            for (auto v: tdel) unv.erase(unv.find(v));
        }
    }
    for (auto e: edges) ed.push_back({ e.second, e.first });
    sort(ed.begin(), ed.end());

    if (rem + cc != n) {
        cout << find_mst() << endl;
    } else {
        long long ans = find_mst() + s;
        for (int i = 1; i < n; ++i) for (int j = i + 1; j <= n; ++j) if (edges.find({i, j}) == edges.end()) spare.push_back({i, j});
        for (auto z: spare) ans = min(ans, find_mst_2(z));
        cout << ans << endl;
    }
    return 0;
}
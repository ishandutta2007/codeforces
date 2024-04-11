#include <bits/stdc++.h>
using namespace std;

const int N = 100005, LG = 17;

int n, m, u, v, d, s, t, ans = 0, h[N] = {-1}, par[N][LG];
long long tim = -1;
set<pair<long long, int>> se[N];
vector<pair<int, int>> adj[N];
vector<int> eve[N];
multiset<pair<long long, long long>> ran;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int LCA(int u, int v) {
    if (h[u] < h[v]) {
        swap(u, v);
    }
    for (int i = 0; i < LG; i++) {
        if ((h[u] - h[v]) >> i & 1) {
            u = par[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = LG - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void add(long long t, int c, int u, long long d) {
    if (se[u].empty() || se[u].find({t, c}) != se[u].end()) {
        return;
    }
    auto it = se[u].upper_bound({t, c});
    if (it == se[u].begin()) {
        auto [rt, rc] = *it;
        if (LCA(c, rc) == u) {
            ran.insert({d + t + 1, d + rt});
        }
    } else if (it == se[u].end()) {
        auto [lt, lc] = *prev(it);
        if (LCA(c, lc) == u) {
            ran.insert({d + lt + 1, d + t});
        }
    } else {
        auto [lt, lc] = *prev(it);
        auto [rt, rc] = *it;
        if (LCA(lc, rc) == u) {
            ran.erase(ran.find({d + lt + 1, d + rt}));
        }
        if (LCA(lc, c) == u) {
            ran.insert({d + lt + 1, d + t});
        }
        if (LCA(rc, c) == u) {
            ran.insert({d + t + 1, d + rt});
        }
    }
}

void DFS_1(int u, int p = 0) {
    h[u] = h[p] + 1;
    par[u][0] = p;
    for (int i = 1; (1 << i) <= h[u]; i++) {
        par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto &[v, _] : adj[u]) {
        DFS_1(v, u);
    }
}

void DFS_2(int u, long long h = 0) {
    for (auto &[v, d] : adj[u]) {
        DFS_2(v, h + d);
        if (se[u].size() < se[v].size()) {
            for (auto it = se[u].begin(); it != se[u].end(); it = next(it)) {
                if (next(it) == se[u].end()) {
                    break;
                }
                auto [lt, lc] = *it;
                auto [rt, rc] = *next(it);
                if (LCA(lc, rc) == u) {
                    ran.erase(ran.find({h + lt + 1, h + rt}));
                }
            }
            swap(se[u], se[v]);
        }
        for (auto [t, c] : se[v]) {
            add(t, c, u, h);
            se[u].insert({t, c});
        }
    }
    if (!adj[u].empty()) {
        add(-h, adj[u].back().first, u, h);
    }
    for (int &t : eve[u]) {
        se[u].insert({t, u});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    DFS_1(1);
    while (m--) {
        cin >> s >> t;
        eve[s].push_back(t);
    }
    DFS_2(1);
    for (auto it = ran.begin(); it != ran.end() && tim == -1; it = next(it)) {
        auto [l, r] = *it;
        pq.push(r);
        long long nxt = (next(it) == ran.end() ? LLONG_MAX : next(it)->first);
        for (; l < nxt && !pq.empty(); l++) {
            if (pq.top() < l) {
                tim = pq.top();
                break;
            }
            pq.pop();
        }
    }
    for (auto [l, r] : ran) {
        if (tim == -1 || r < tim) {
            ans++;
        }
    }
    cout << tim << " " << ans << '\n';
}
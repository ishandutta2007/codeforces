
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const ll X = 3e6;

template<typename Cap, typename Cost>
struct mcmf {
    struct edge {
        int v;
        Cap cap, flow;
        Cost cost;
    };
    int n;
    vector<edge> e;
    vector<vector<int>> g;
    vector<Cost> dist, pot;
    vector<Cap> f;
    vector<bool> vis;
    vector<int> par;
    bool n2dijkstra = false;
    mcmf(int n) : n(n), g(n), dist(n), pot(n), f(n), vis(n), par(n) {}
    void add_edge(int u, int v, Cap cap, Cost cost) {
        int k = e.size();
        e.push_back({v, cap, 0, cost});
        e.push_back({u, cap, cap, -cost});
        g[u].push_back(k);
        g[v].push_back(k ^ 1);
    }
    pair<Cap, Cost> solve(int s, int t) {
        Cap flow = 0;
        Cost cost = 0;
        Cost best = 0;
        while(true) {
            fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
            fill(vis.begin(), vis.end(), false);
            dist[s] = 0;
            f[s] = numeric_limits<Cap>::max();
            if(n2dijkstra) {
                while(true) {
                    int x = -1; Cost d = numeric_limits<Cost>::max();
                    for(int i = 0; i < n; i++) {
                        if(!vis[i] && dist[i] < d) {
                            x = i;
                            d = dist[x];
                        }
                    }
                    if(x == -1) break;
                    vis[x] = true;
                    for(int i : g[x]) {
                        Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
                        if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
                            dist[e[i].v] = d2;
                            f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
                            par[e[i].v] = i;
                        }
                    }
                }
            }else {
                priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<>> Q;
                Q.push({0, s});
                while(!Q.empty()) {
                    Cost d; int x;
                    tie(d, x) = Q.top(); Q.pop();
                    if(vis[x]) continue;
                    vis[x] = true;
                    for(int i : g[x]) {
                        Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
                        if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
                            dist[e[i].v] = d2;
                            f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
                            par[e[i].v] = i;
                            Q.push({d2, e[i].v});
                        }
                    }
                }
            }
            if(!vis[t]) break;
            for(int i = 0; i < n; i++) {
                dist[i] += pot[i] - pot[s];
            }
            cost += dist[t] * f[t];
            flow += f[t];
            int x = t;
            while(x != s) {
                e[par[x]].flow += f[t];
                e[par[x] ^ 1].flow -= f[t];
                x = e[par[x] ^ 1].v;
            }
            dist.swap(pot);
            best = max(best, 2LL * X * flow - cost);
        }
        return {flow, best};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vi a(1 << n);
    rep(i, 0, 1 << n) {
        cin >> a[i];
    }
    const int A = 2e6 + 1;
    vi cnt(A, 0);
    ll best = (2 * n - 1) * (k - 1) + 2;
    rep(i, 0, 1 << n) {
        rep(b, 0, n) {
            int j = i ^ (1 << b);
            if(i < j) {
                cnt[a[i] + a[j]]++;
            }
        }
    }
    rep(i, 1, A) cnt[i] += cnt[i - 1];
    vector<pii> e;
    vi nodes;
    rep(i, 0, 1 << n) {
        rep(b, 0, n) {
            int j = i ^ (1 << b);
            if(i < j) {
                cnt[a[i] + a[j]]--;
                if(cnt[a[i] + a[j]] >= n * (1 << (n - 1)) - best) {
                    e.push_back({i, j});
                    nodes.push_back(i);
                    nodes.push_back(j);
                }
            }
        }
    }
    sort(all(nodes));
    nodes.erase(unique(all(nodes)), nodes.end());
    for(auto &pa : e) {
        pa.first = lower_bound(all(nodes), pa.first) - nodes.begin();
        pa.second = lower_bound(all(nodes), pa.second) - nodes.begin();
    }
    int source = sz(nodes), source2 = source + 1, sink = source2 + 1;
    mcmf<int, ll> F(sink + 1);
    F.add_edge(source, source2, k, 0);
    rep(i, 0, source) {
        if(__builtin_popcount(nodes[i]) % 2 == 0) {
            F.add_edge(source2, i, 1, X - a[nodes[i]]);
        }else {
            F.add_edge(i, sink, 1, X - a[nodes[i]]);
        }
    }
    for(auto &pa : e) {
        int u, v;
        tie(u, v) = pa;
        if(__builtin_popcount(nodes[u]) % 2 == 1) swap(u, v);
        F.add_edge(u, v, 1, 0);
    }
    auto ans = F.solve(source, sink);
    cout << ans.second << '\n';
}
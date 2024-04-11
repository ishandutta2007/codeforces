
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

const ll INF = LLONG_MAX / 4;

template <class Cap, class Cost> struct MCMF {
  public:
    MCMF() {}
    MCMF(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        assert(0 <= cost);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }

    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        // variants (C = maxcost):
        // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
        // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            struct Q {
                Cost key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            std::priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                // dist[v] = shortest(s, v) + dual[s] - dual[v]
                // dist[v] >= 0 (all reduced cost are positive)
                // dist[v] <= (n-1)C
                for (int i = 0; i < int(g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    // |-dual[e.to] + dual[v]| <= (n-1)C
                    // cost <= C - -(n-1)C + 0 = nC
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }

            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                // dual[v] = dual[v] - dist[t] + dist[v]
                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) + (shortest(s, v) + dual[s] - dual[v])
                //         = - shortest(s, t) + dual[t] + shortest(s, v)
                //         = shortest(s, v) - shortest(s, t) >= 0 - (n-1)C
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }

  private:
    int _n;

    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };

    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

const int N = 205;
int n;
ll a[N][N];
ll dsu[N * N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        cin >> a[i][j];
    }
    fill(dsu, dsu + N * N, -1);
    rep(i, 0, n) rep(j, 0, n) {
        if(a[i][j] == -1) {
            join(i * n + j, (i - 1) * n + j);
            join(i * n + j, i * n + j - 1);
            join(i * n + j - 1, (i - 1) * n + j - 1);
        }
    }
    vector<vi> adj(n * n + 2);
    vector<pair<int, ll>> sup, dem;
    map<int, ll> ma;
    ll cost = 0;
    rep(i, 0, n) rep(j, 0, n) {
        if(i < n - 1) {
            if(j == 0 || j == n - 1) {
                int x = trace(i * n + min(n - 2, j));
                int dif = a[i + 1][j] - a[i][j];
                cost += abs(dif);
                if((dif > 0) ^ (j == 0)) {
                    ma[x] += abs(dif);
                }else {
                    ma[x] -= abs(dif);
                }
            }else {
                int x = trace(i * n + j - 1);
                int y = trace(i * n + j);
                if(x != y) {
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                }
            }
        }
        // horizontal edge
        if(j < n - 1) {
            if(i == 0 || i == n - 1) {
                int x = trace(min(n - 2, i) * n + j);
                int dif = a[i][j + 1] - a[i][j];
                cost += abs(dif);
                if((dif > 0) ^ (i != 0)) {
                    ma[x] += abs(dif);
                }else {
                    ma[x] -= abs(dif);
                }
            }else {
                int x = trace(i * n + j);
                int y = trace((i - 1) * n + j);
                if(x != y) {
                    adj[x].push_back(y);
                    adj[y].push_back(x);
                }
            }
        }
    }
    vi demidx(n * n + 5, -1);
    for(auto &pa : ma) {
        int x;
        ll s;
        tie(x, s) = pa;
        if(s > 0) {
            sup.emplace_back(x, s);
        }else {
            demidx[x] = sz(dem);
            dem.emplace_back(x, -s);
        }
    }
    int S = sz(sup), D = sz(dem);
    MCMF<ll, ll> orz(S + D + 2);
    int source = S + D, sink = S + D + 1;
    int idx = 0;
    for(auto &pa : sup) {
        int s;
        ll amt;
        tie(s, amt) = pa;
        orz.add_edge(source, idx, amt, 0);
        vi dist(n * n + 5, 1e9);
        queue<int> Q;
        dist[s] = 0;
        Q.push(s);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            if(demidx[x] != -1) {
                orz.add_edge(idx, S + demidx[x], INF, dist[x]);
            }
            for(int y : adj[x]) {
                if(dist[y] == 1e9) {
                    dist[y] = dist[x] + 1;
                    Q.push(y);
                }
            }
        }
        idx++;
    }
    for(auto &pa : dem) {
        int s;
        ll amt;
        tie(s, amt) = pa;
        orz.add_edge(idx, sink, amt, 0);
        idx++;
    }
    cout << cost + orz.flow(source, sink).second << '\n';
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e14;

struct Dinic {
    struct Edge {
        ll fr, to, cp, id, fl;
    };
    int n, S, T;
    vector<Edge> es;
    vector<vector<int>> g;
    vector<ll> dist, res, ptr;
    Dinic(int n_, int S_, int T_)
            : n(n_), S(S_), T(T_) {
        g.resize(n);
    }
    void add_edge(int fr, int to, ll cp, int id) {
        g[fr].push_back((int)es.size());
        es.push_back({fr, to, cp, id, 0});
        g[to].push_back((int)es.size());
        es.push_back({to, fr, 0, -1, 0});
    }
    bool bfs(ll K) {
        dist.assign(n, inf);
        dist[S] = 0;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int ps : g[v]) {
                Edge& e = es[ps];
                if (e.fl + K > e.cp) continue;
                if (dist[e.to] > dist[e.fr] + 1) {
                    dist[e.to] = dist[e.fr] + 1;
                    q.push(e.to);
                }
            }
        }
        return dist[T] < inf;
    }
    ll dfs(int v, ll _push = inf64) {
        if (v == T || !_push) return _push;
        for (ll& iter = ptr[v];
             iter < (int)g[v].size(); iter++) {
            int ps = g[v][ptr[v]];
            Edge& e = es[ps];
            if (dist[e.to] != dist[e.fr] + 1) continue;
            ll tmp =
                    dfs(e.to, min(_push, e.cp - e.fl));
            if (tmp) {
                e.fl += tmp;
                es[ps ^ 1].fl -= tmp;
                return tmp;
            }
        }
        return 0;
    }
    ll find_max_flow() {
        ptr.resize(n);
        ll max_flow = 0, add_flow;
        for (ll K = 1ll << 60; K > 0; K >>= 1) {
            while (bfs(K)) {
                ptr.assign(n, 0);
                while ((add_flow = dfs(S))) {
                    max_flow += add_flow;
                }
            }
        }
        return max_flow;
    }
    void assign_result() {
        res.resize(es.size());
        for (Edge e : es)
            if (e.id != -1) res[e.id] = e.fl;
    }
    int get_flow(int id) { return res[id]; }
    bool go(int v, vector<int>& F,
            vector<int>& path) {
        if (v == T) return 1;
        for (int ps : g[v]) {
            if (F[ps] <= 0) continue;
            if (go(es[ps].to, F, path)) {
                path.push_back(ps);
                return 1;
            }
        }
        return 0;
    }
    vector<pair<int, vector<int>>> decomposition() {
        find_max_flow();
        vector<int> F((int)es.size()), path, add;
        vector<pair<int, vector<int>>> dcmp;
        for (int i = 0; i < (int)es.size(); i++)
            F[i] = es[i].fl;
        while (go(S, F, path)) {
            int mn = INT_MAX;
            for (int ps : path)
                mn = min(mn, F[ps]);
            for (int ps : path)
                F[ps] -= mn;
            for (int ps : path)
                add.push_back(es[ps].id);
            reverse(add.begin(), add.end());
            dcmp.push_back({mn, add});
            add.clear();
            path.clear();
        }
        return dcmp;
    }
};

struct pt {
    int x = 0;
    int y = 0;
    int w = 0;
};

ll fast(int n, vector<pt> ps) {
    vector<vector<int>> type = {
        {1, 2},
        {0, 3}
    };
    int N = 2 * n + 2;
    int S = 0, T = 2 * n + 1;
    Dinic dinic(N, S, T);
    for (int i = 1; i <= n; i++) {
        int fr = 2 * i - 1;
        int to = 2 * i;
        dinic.add_edge(fr, to, ps[i - 1].w, -1);
    }
    for (int i = 1; i <= n; i++) {
        auto p = ps[i - 1];
        int t = type[abs(p.x) % 2][abs(p.y) % 2];
        if (t == 0) {
            dinic.add_edge(S, 2 * i - 1, inf64, -1);
        } else if (t == 3) {
            dinic.add_edge(2 * i, T, inf64, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int dx = abs(ps[i - 1].x - ps[j - 1].x);
            int dy = abs(ps[i - 1].y - ps[j - 1].y);
            if ((dx == 0 && dy == 1) || (dx == 1 && dy == 0)) {
                int ti = type[abs(ps[i - 1].x % 2)][abs(ps[i - 1].y % 2)];
                int tj = type[abs(ps[j - 1].x % 2)][abs(ps[j - 1].y % 2)];
                if ((ti + 1) % 4 == tj) {
                    dinic.add_edge(2 * i, 2 * j - 1, inf64, -1);
                }
            }
        }
    }
    ll res = 0;
    for (auto p : ps)
        res += p.w;
    return res - dinic.find_max_flow();
}

void work() {
    int n;
    cin >> n;
    vector<pt> ps(n);
    for (auto& p : ps)
        cin >> p.x >> p.y >> p.w;
    ll fs = fast(n, ps);
    cout << fs << "\n";
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();

    return 0;
}
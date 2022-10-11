#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<typename T>
struct max_flow {
    struct edge {
        int to, rev;
        T capasity, flow;
    };

    int n;
    std::vector<std::vector<edge>> g;

    max_flow(int n = 0) : n(n), g(n) {}

    int size() const {
        return n;
    }

    void add(int from, int to, T capasity) {
        g[from].push_back({to, int(g[to].size()), capasity, 0});
        g[to].push_back({from, int(g[from].size()) - 1, 0, 0});
    }

    std::vector<int> dist;
    std::vector<int> head;
    int source, sink;

    bool bfs() {
        std::fill(dist.begin(), dist.end(), n);
        dist[source] = 0;
        std::vector<int> que{source};
        for (int ptr = 0; ptr < int(que.size()); ptr++) {
            int v = que[ptr];
            for (const auto &[u, rev, capasity, flow] : g[v])
                if (dist[u] > dist[v] + 1 && flow < capasity) {
                    dist[u] = dist[v] + 1;
                    que.push_back(u);
                }
        }
        return dist[sink] != n;
    }

    T dfs(int v, T min_delta) {
        if (v == sink)
            return min_delta;

        while (head[v] < int(g[v].size())) {
            auto &[u, rev, capasity, flow] = g[v][head[v]];
            if (dist[u] == dist[v] + 1 && flow < capasity) {
                if (T delta = dfs(u, std::min(min_delta, capasity - flow))) {
                    flow += delta;
                    g[u][rev].flow -= delta;
                    return delta;
                }
            }
            head[v]++;
        }
        return 0;
    }

    T solve(int source_, int sink_) {
        source = source_, sink = sink_;
        for (int v = 0; v < n; v++)
            for (edge &e : g[v])
                e.flow = 0;

        dist.resize(n);
        head.resize(n);
        T flow = 0;
        while (bfs()) {
            std::fill(head.begin(), head.end(), 0);
            while (T delta = dfs(source, std::numeric_limits<T>::max()))
                flow += delta;
        }
        return flow;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> x1(m);
    vector<int> y1(m);
    vector<int> x2(m);
    vector<int> y2(m);

    vector<int> x_coords;
    x_coords.reserve(2 * m);
    vector<int> y_coords;
    y_coords.reserve(2 * m);

    for (int i = 0; i < m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x_coords.push_back(x1[i]);
        x_coords.push_back(x2[i]);
        y_coords.push_back(y1[i]);
        y_coords.push_back(y2[i]);
    }

    sort(all(x_coords));
    x_coords.resize(unique(all(x_coords)) - x_coords.begin());
    sort(all(y_coords));
    y_coords.resize(unique(all(y_coords)) - y_coords.begin());

    auto get_segs = [&](const vector<int> &coords) {
        vector<pair<int, int>> segs;
        for (int i = 0; i < len(coords); i++) {
            segs.emplace_back(coords[i], coords[i]);
            if (i + 1 < len(coords) && coords[i] + 1 != coords[i + 1])
                segs.emplace_back(coords[i] + 1, coords[i + 1] - 1);
        }
        return segs;
    };

    const auto x_segs = get_segs(x_coords);
    const auto y_segs = get_segs(y_coords);

    const int X = len(x_segs);
    const int Y = len(y_segs);

    int source = X + Y;
    int sink = X + Y + 1;
    max_flow<int> g(X + Y + 2);

    for (int i = 0; i < m; i++) {
        int from_x = lower_bound(all(x_segs), pair<int, int>{x1[i], -1}) - x_segs.begin();
        int to_x = lower_bound(all(x_segs), pair<int, int>{x2[i] + 1, -1}) - x_segs.begin();

        int from_y = lower_bound(all(y_segs), pair<int, int>{y1[i], -1}) - y_segs.begin();
        int to_y = lower_bound(all(y_segs), pair<int, int>{y2[i] + 1, -1}) - y_segs.begin();

        for (int a = from_x; a < to_x; a++)
            for (int b = from_y; b < to_y; b++)
                g.add(a, X + b, min(x_segs[a].second - x_segs[a].first, y_segs[b].second - y_segs[b].first) + 1);
    }

    for (int i = 0; i < X; i++)
        g.add(source, i, x_segs[i].second - x_segs[i].first + 1);

    for (int i = 0; i < Y; i++)
        g.add(X + i, sink, y_segs[i].second - y_segs[i].first + 1);

    cout << g.solve(source, sink) << '\n';
}
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
const int M = 1e5;
int n, m;
vector <int> com_x;
vector <int> com_y;
vector <int> g[nax];
vector <pair <int, int>> a[nax];
int x[nax];
int y[nax];
int sx, sy, fx, fy;
bool vis[nax];
int col[nax];
int top;
int to_col[nax];

void add_edge(int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
}

void add_edge(int x, int y, int cost) {
    a[x].emplace_back(y, cost);
    a[y].emplace_back(x, cost);
}


void dfs(int node) {
    vis[node] = true;
    col[node] = top;
    for (int to : g[node]) {
        if (!vis[to])
            dfs(to);
    }
}

struct state {
    int node;
    int64_t val;
    state() {}
    state(int node, int64_t val) : node(node), val(val) {}

    bool operator <(const state &other) const {
        return val > other.val;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    cin >> sx >> sy >> fx >> fy;

    for (int i = 1 ; i <= m ; ++ i) {
        cin >> x[i] >> y[i];
        com_x.push_back(x[i]);
        com_y.push_back(y[i]);
    }

    sort(com_x.begin(), com_x.end());
    sort(com_y.begin(), com_y.end());
    com_x.erase(unique(com_x.begin(), com_x.end()), com_x.end());
    com_y.erase(unique(com_y.begin(), com_y.end()), com_y.end());

    for (int i = 1 ; i <= m ; ++ i) {
        x[i] = lower_bound(com_x.begin(), com_x.end(), x[i]) - com_x.begin();
        y[i] = lower_bound(com_y.begin(), com_y.end(), y[i]) - com_y.begin();
        add_edge(x[i], y[i] + M);
    }

    for (int i = 0 ; i < nax ; ++ i) {
        if (vis[i] || g[i].empty()) continue;
        top++;
        dfs(i);
    }


    int S = 2e5 + 1;
    int T = 2e5 + 2;

    add_edge(S, T, abs(fx - sx) + abs(fy - sy));

    for (int i = 1 ; i <= m ; ++ i) {
        int X = com_x[x[i]];
        int Y = com_y[y[i]];
        int comp = col[x[i]];
        add_edge(S, comp, min(abs(X - sx), abs(Y - sy)));
        add_edge(T, comp, abs(X - fx) + abs(Y - fy));
        to_col[x[i]] = comp;
        to_col[y[i] + M] = comp;
    }

    for (int i = 1 ; i < com_x.size(); ++ i) {
        int foo = to_col[i - 1];
        int bar = to_col[i];
        if (foo != bar) {
            add_edge(foo, bar, com_x[i] - com_x[i - 1]);
        }
    }



    for (int i = 1 ; i < com_y.size() ; ++ i) {
        int foo = to_col[M + i - 1];
        int bar = to_col[M + i];
        if (foo != bar) {
            add_edge(foo, bar, com_y[i] - com_y[i - 1]);
        }
    }



    priority_queue <state> pq;
    static int64_t dist[nax];
    static bool vis2[nax];
    const int64_t INF = 1e16;
    fill(dist, dist + nax, INF);

    dist[S] = 0;
    pq.emplace(S, 0);

    while (!pq.empty()) {
        auto [nd, val] = pq.top();
        pq.pop();
        if (vis2[nd]) continue;
        vis2[nd] = true;

        for (const auto &[to, cost] : a[nd]) {
            if (dist[to] > val + cost) {
                dist[to] = val + cost;
                pq.emplace(to, val + cost);
            }
        }
    }

    cout << dist[T] << '\n';
}
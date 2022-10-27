#include<bits/stdc++.h>
using namespace std;

template <typename T> struct dinic {

    struct edge {
        int from, to;
        T cap;
        T flow = 0;
        edge (){}
        edge  (int from, int to, T cap) : from(from), to(to), cap(cap) {}
    };

    int n;
    int s; /// sources
    int t; /// sink
    vector <vector <int>> g;
    vector <int> ptr;
    vector <edge> edges;
    queue <int> q;
    vector <int> level;
    int m = 0;
    T INF = numeric_limits<T>::max() / 2;

    dinic(int n, int s, int t) : n(n), s(s), t(t) {
        g.resize(n + 1);
        ptr.resize(n + 1);
        level.resize(n + 1);
    }

    void add_edge(int from, int to, T cap) {
        edges.emplace_back(from, to, cap);
        edges.emplace_back(to, from, 0);
        g[from].push_back(m);
        g[to].push_back(m + 1);
        m += 2;
    }

    T dfs(int v, T pushed) {
        if (pushed == 0) return 0;
        if (v == t) return pushed;
        for (; ptr[v] < g[v].size(); ++ ptr[v]) {
            int id = g[v][ptr[v]];
            int to = edges[id].to;
            if (level[v] + 1 != level[to] || edges[id].cap - edges[id].flow < 1) continue;

            T get_pushed = dfs(to, min(pushed, edges[id].cap - edges[id].flow));
            if (get_pushed == 0) continue;
            edges[id].flow += get_pushed;
            edges[id ^ 1].flow -= get_pushed;
            return get_pushed;
        }
        return 0;
    }

    bool bfs() {
        q.push(s);
        level[s] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : g[v]) {
                if (edges[id].cap - edges[id].flow < 1 || level[edges[id].to] != -1) continue;
                level[edges[id].to] = level[v] + 1;
                q.push(edges[id].to);
            }
        }
        return level[t] != -1;
    }

    T max_flow() {
        T res = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            if (!bfs()) break;
            fill(ptr.begin(), ptr.end(), 0);
            while (T pushed = dfs(s, INF)) {
                res += pushed;
            }
        }
        return res;
    }
};

const int nax = 3010;
int n;
int a[nax];
int b[nax];
int lst[nax];

int main() {
    // cin.tie(0)->sync_with_stdio(false);
    cin >> n;

    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];

    for (int i = 1 ; i <= n ; ++ i)
        cin >> b[i];


    int s = n + 1;
    int t = n + 2;
    dinic <int> d(n + 2, s, t);

    for (int i = 1 ; i <= n ; ++ i) {
        if (b[i] > 0) d.add_edge(s, i, b[i]);
        if (b[i] < 0) d.add_edge(i, t, -b[i]);
        for (int j = 1 ; j <= 100 ; ++ j) {
            if (a[i] % j) continue;
            if (!lst[j]) continue;
            d.add_edge(i, lst[j], d.INF);
        }
        lst[a[i]] = i;
    }

    int res = 0;
    for (int i = 1 ; i <= n ; ++ i)
        res += max(0, b[i]);
    cout << res - d.max_flow() << '\n';
}
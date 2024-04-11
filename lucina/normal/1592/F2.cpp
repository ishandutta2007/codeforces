#include<bits/stdc++.h>
using namespace std;
const int nax = 512;
int n, m;
int a[nax][nax];
int b[nax][nax];
char f[nax];
/**
    most things remained true from F1
    , but now it makes sense to take 2 or more operations of type 3
    Operation of type 1 still flip some corner with cost = 1
    Operation of type 3 still flip 4 values with cost = 2

    Still not everything that make sense about type3
    Doing two operations at same (X or Y) cost 4
    x   ____
       |    |
       |____|
    The result is just some frame which can be done by 4 operations of type 1
    This suggest bipartite matching solution.
    Turn grid to bipartite graph edges from x->y makes sense if
    b[x][y], b[x][m], b[n][y] are all 1
    This will reduce cost from 3 to 2

*/
template <typename T>
struct edge {
    int from, to;
    T cap;
    T flow = 0;
    edge (){}
    edge  (int from, int to, T cap) : from(from), to(to), cap(cap) {}
};
template <typename T> struct dinic {
    int n;
    int s; /// sources
    int t; /// sink
    vector <vector <int>> g;
    vector <int> ptr;
    vector <edge<T>> edges;
    queue <int> q;
    vector <int> level;
    int m = 0;
    T INF = numeric_limits<T>::max() / 4;

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

    vector <bool> min_cut() {
        vector <bool> result(edges.size());
        for (int i = 0 ; i < edges.size() ; ++ i)
            if (edges[i].flow == edges[i].cap) result[i] = true;
        return result;
    }
};


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n ; ++ i) {
        cin >> f + 1;
        for (int j = 1 ; j <= m ; ++ j)
            a[i][j] = f[j] == 'B';
    }

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j) {
        b[i][j] = (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) & 1;
    }

    int S = n + m + 1, T = n + m + 2;
    dinic <int> flow(n + m + 2, S, T);

    for (int i = 1 ; i < n ; ++ i)
    for (int j = 1 ; j < m ; ++ j) {
        if (b[i][j] && b[n][j] && b[i][m]) {
            flow.add_edge(i, n + j, 1);
        }
    }
    for (int i = 1 ; i <= n ; ++ i)
        flow.add_edge(S, i, 1);
    for (int i = 1 ; i <= m ; ++ i)
        flow.add_edge(i + n, T, 1);
    int max_match = flow.max_flow();
    int ans = 0;
    for (int i = 0 ; i < flow.edges.size() ; i += 2) {
        int x = flow.edges[i].from, y = flow.edges[i].to - n;
        if (x != S && y + n != T && flow.edges[i].flow == 1) {
            b[x][y] ^= 1, b[x][m] ^= 1, b[n][y] ^= 1, b[n][m] ^= 1;
            ans += 2;
        }
    }

    for (int i = 1 ; i <= n ; ++ i)
    for (int j = 1 ; j <= m ; ++ j)
        if (b[i][j]) ans += 1;
    cout << ans << '\n';
}
/*
    Well, such a long time from last div.2 round
*/
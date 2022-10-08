
#include <bits/stdc++.h>

using namespace std;

#define SOURCE 0
#define HORZ(i, j) (m * (i) + (j) + 1)
#define VERT(i, j) ((n - 1) * m + n * (j) + (i) + 1)
#define SINK ((n - 1) * m + n * (m - 1) + 1)

const int N = 305, V = 2e5 + 5;

struct edge {
    int u, v, cap, flow;
};
 
struct Dinic {
    vector<edge> e;
    vector<vector<int>> adj;
    vector<int> ptr;
    vector<int> level;
    int n, source, sink;
    Dinic(int n, int s, int t): n(n), source(s), sink(t) {
        level.assign(n, -1);
        adj.assign(n, vector<int>());
        ptr.assign(n, 0);
    }
    void add_edge(int a, int b, int c) {
        int k = e.size();
        e.push_back({a, b, c, 0});
        e.push_back({b, a, c, c});
        adj[a].push_back(k);
        adj[b].push_back(k + 1);
    }
    bool bfs() {
        fill(level.begin(), level.end(), -1);
        level[source] = 0;
        queue<int> Q;
        Q.push(source);
        while(!Q.empty()) {
            int x = Q.front(); Q.pop();
            for(int i : adj[x]) {
                if(level[e[i].v] == -1 && e[i].flow < e[i].cap) {
                    level[e[i].v] = level[x] + 1;
                    Q.push(e[i].v);
                }
            }
        }
        return level[sink] != -1;
    }
    int dfs(int x, int pushed) {
        if(x == sink) return pushed;
        for(int &id = ptr[x]; id < (int) adj[x].size(); id++) {
            int i = adj[x][id];
            if(level[e[i].v] == level[x] + 1 && e[i].flow < e[i].cap) {
                int f = dfs(e[i].v, min(pushed, e[i].cap - e[i].flow));
                if(f > 0) {
                    e[i].flow += f;
                    e[i ^ 1].flow -= f;
                    return f;
                }
            }
        }
        return 0;
    }
    int calc() {
        int ans = 0;
        while(bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while(true) {
                int f = dfs(source, INT_MAX);
                if(f == 0) break;
                ans += f;
            }
        }
        return ans;
    }
};

int n, m;
string s[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    Dinic F(SINK + 1, SOURCE, SINK);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') {
                ans++;
                if(i > 0 && s[i - 1][j] == '#') {
                    F.add_edge(SOURCE, HORZ(i - 1, j), 1);
                    ans--;
                }
                if(j > 0 && s[i][j - 1] == '#') {
                    F.add_edge(VERT(i, j - 1), SINK, 1);
                    ans--;
                }
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(s[i][j] == '#') {
                // right, down
                if(i < n - 1 && j < m - 1 && s[i + 1][j] == '#' && s[i][j + 1] == '#') {
                    F.add_edge(HORZ(i, j), VERT(i, j), 1);
                }
                // right, up
                if(i > 0 && j < m - 1 && s[i - 1][j] == '#' && s[i][j + 1] == '#') {
                    F.add_edge(HORZ(i - 1, j), VERT(i, j), 1);
                }
                // left, down
                if(i < n - 1 && j > 0 && s[i + 1][j] == '#' && s[i][j - 1] == '#') {
                    F.add_edge(HORZ(i, j), VERT(i, j - 1), 1);
                }
                // left, up
                if(i > 0 && j > 0 && s[i - 1][j] == '#' && s[i][j - 1] == '#') {
                    F.add_edge(HORZ(i - 1, j), VERT(i, j - 1), 1);
                }
            }
        }
    }
    ans += F.calc();
    cout << ans << '\n';
}
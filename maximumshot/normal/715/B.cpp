#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

struct Dsu {
    int n;
    vec< int > p, h;
    Dsu() : n(0) {}
    Dsu(int n) : n(n) {
        p.resize(n);
        h.resize(n);
        for(int i = 0;i < n;i++) {
            p[i] = i;
            h[i] = 0;
        }
    }
    int find(int x) { return (p[x] == x?x : p[x] = find(p[x])); }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return false;
        if(h[x] == h[y]) {
            p[y] = x;
            h[x]++;
        }else {
            if(h[x] < h[y]) swap(x, y);
            p[y] = x;
        }
        return true;
    }
};

int const N = 1005;

int n, m, L, s, t;
ll g[N][N];

ll dist[N];
bool used[N];
ll dt[N];

ll dijkstra(int S, int T, bool fl = 0) {
    for(int i = 0;i < n;i++) dist[i] = inf64, used[i] = 0;
    dist[S] = 0;
    for(int iter = 0;iter < n;iter++) {
        int v = -1;
        for(int i = 0;i < n;i++) {
            if(!used[i] && (v == -1 || dist[v] > dist[i]))
                v = i;
        }
        if(v == -1 || dist[v] == inf64) break;
        used[v] = 1;
        for(int to = 0;to < n;to++) {
            if(g[v][to] > 0 && dist[to] > dist[v] + g[v][to]) {
                dist[to] = dist[v] + g[v][to];
            }
            if(fl) {
                if(g[v][to] == 0) {
                    if(dist[v] + dt[to] < L) {
                        g[v][to] = g[to][v] = L - dist[v] - dt[to];
                        return L;
                    }else if(dist[to] > dist[v] + 1) {
                        dist[to] = dist[v] + 1;
                        g[v][to] = g[to][v] = 1;
                    }
                }
            }
        }
    }
    return dist[T];
}

bool solve() {

    cin >> n >> m >> L >> s >> t;

    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            g[i][j] = -1;

    vec< pii > empty_edge;

    for(int u, v, w, iter = 0;iter < m;iter++) {
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
        if(!w) empty_edge.push_back({u, v});
    }

    if(dijkstra(s, t) < L) {
        cout << "NO\n";
        return true;
    }else if(dijkstra(s, t) == L) {
        cout << "YES\n";
        for(auto iter : empty_edge) {
            cout << iter.first << ' ' << iter.second << ' ' << L + 1 << "\n";
        }
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(g[i][j] > 0) {
                    cout << i << ' ' << j << ' ' << g[i][j] << '\n';
                }
            }
        }
        return true;
    }

    for(auto iter : empty_edge) {
        g[iter.first][iter.second] =
        g[iter.second][iter.first] = 1;
    }

    if(dijkstra(s, t) > L) {
        cout << "NO\n";
        return true;
    }else if(dijkstra(s, t) == L) {
        cout << "YES\n";
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(g[i][j] > 0) {
                    cout << i << ' ' << j << ' ' << g[i][j] << '\n';
                }
            }
        }
        return true;
    }

    for(auto iter : empty_edge) {
        g[iter.first][iter.second] =
        g[iter.second][iter.first] = 0;
    }

    dijkstra(t, s);
    for(int i = 0;i < n;i++) dt[i] = dist[i];

    dijkstra(s, t, 1);

    for(int i = 0;i < n;i++) {
        for(int j = i + 1;j < n;j++) {
            if(g[i][j] == 0) g[i][j] = L + 1;
            //if(g[i][j] > 0) cout << i << ' ' << j << ' ' << g[i][j] << '\n';
        }
    }

    if(dijkstra(s, t) != L) cout << "NO\n";
    else {
        cout << "YES\n";
        for(int i = 0;i < n;i++) {
            for(int j = i + 1;j < n;j++) {
                if(g[i][j] > 0) cout << i << ' ' << j << ' ' << g[i][j] << '\n';
            }
        }
    }

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}
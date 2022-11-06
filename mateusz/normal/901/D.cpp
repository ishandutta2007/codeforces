#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m, a, b, c[N];
vector<pair<int, int > > V[N];

int color[N];
int par[N], parEdge[N];

vector<int> cycle;
vector<int> cycleEdges;

bool vis[N];

long long value[N];

bool DFS(int w, int col) {
    vis[w] = true;
    color[w] = col;
    for (pair<int, int> p: V[w]) {
        int u = p.first;
        if (!vis[u]) {
            par[u] = w;
            parEdge[u] = p.second;
            if (DFS(u, 1 - col)) {
                return true;
            }
        } else if (color[w] == color[u]) {
            int v = w;
            cycleEdges.push_back(p.second);
            do {
                cycle.push_back(v);
                if (u != v) {
                    cycleEdges.push_back(parEdge[v]);
                }
                v = par[v];
            } while (v != u);
            return true;
        }
    }
    return false;
}

void solve(int w, int parEdge) {
    vis[w] = true;
    long long current = 0;
    for (int i = 0; i < V[w].size(); i++) {
        int u = V[w][i].first;
        int id = V[w][i].second;
        if (vis[u]) {
            continue;
        }
        par[u] = w;
        solve(u, id);
        current += value[id];
    }
    long long remaining = c[w] - current;
    value[parEdge] = remaining;
}

int main() {
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        V[a].push_back({b, i});
        V[b].push_back({a, i});
    }
    
    bool isCycle = DFS(1, 0);
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }
    int root;
    
    if (!cycle.empty()) {
        root = cycle[0];
    } else {
        root = 1;
    }
    
    solve(root, -1);
    
    long long current = 0;
    for (int i = 0; i < V[root].size(); i++) {
        int u = V[root][i].first;
        int id = V[root][i].second;
        if (par[u] == root) {
            current += value[id];
        }
    }
    long long remaining = c[root] - current;
    
    if (remaining != 0 && !isCycle) {
        printf("NO\n");
        return 0;
    }
    
    if (!isCycle) {
        printf("YES\n");
        for (int i = 1; i <= m; i++) {
            printf("%lld\n", value[i]);
        }
        return 0;
    }
    
    assert(remaining % 2 == 0);
    remaining /= 2;
    /*
    if (remaining > 0) {
        cerr << "Ehh\n";
    }*/
    for (int i = 1; i < cycleEdges.size(); i++) {
        if (i % 2 == 1) {
            value[cycleEdges[i]] += remaining;
        } else {
            value[cycleEdges[i]] -= remaining;
        }
    }
    value[cycleEdges[0]] += remaining;
    
    printf("YES\n");
    for (int i = 1; i <= m; i++) {
        printf("%lld\n", value[i]);
    }
    
    
    return 0;
}
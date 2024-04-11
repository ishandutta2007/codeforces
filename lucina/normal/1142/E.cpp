#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int n, m;
vector <int> g[nax];
vector <int> rev_g[nax];
vector <int> comp[nax];
bool vis[nax];
vector <int> order;
int col;
int cc[nax];
queue <int> free_comp;
int in_deg[nax];

void dfs_order(int node) {
    vis[node] = true;
    for (int to : g[node])
        if (!vis[to]) dfs_order(to);
    order.push_back(node);
}



void dfs_comp(int node) {
   // cout << "node " << node<< " In comp: " << col << endl;;
    vis[node] = true;
    comp[col].push_back(node);
    cc[node] = col;
    for (int to : rev_g[node]) {
        if (!vis[to]) dfs_comp(to);
    }
}

int query(int u, int v) {
    cout << "? " << u << ' ' << v << endl;
    int x;
    cin >> x;
    return x;
}

void del(int node) {
    for (int to : g[node]) {
        if (cc[node] < cc[to]) {
            in_deg[cc[to]] -= 1;
            if (in_deg[cc[to]] == 0) free_comp.push(cc[to]);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    vector <pair <int, int>> edges;
    for (int i = 1 ; i <= m ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); /// pink edges
        rev_g[v].push_back(u);
        edges.emplace_back(u, v);
    }
    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) dfs_order(i);
    }
    reverse(order.begin(), order.end());
    memset(vis, false, sizeof(vis));
    for (int x : order) {
        if (vis[x]) continue;
        col += 1;
        dfs_comp(x);
    }
    for (auto [u, v] : edges) {
        if (cc[u] < cc[v]) {
            in_deg[cc[v]] += 1;
        }
    }

    for (int i = 1 ; i <= col ; ++ i) {
      //  cout << "col " << i << ' ' << in_deg[i] << '\n';
        if (in_deg[i] == 0) free_comp.push(i);
    }
    int X = comp[free_comp.front()].back();  free_comp.pop();
    while (!free_comp.empty()) {
        int Y = comp[free_comp.front()].back();
        int dir = query(X, Y);
        if (dir == 1) {
            comp[free_comp.front()].pop_back();
            if (!comp[free_comp.front()].empty()) free_comp.push(free_comp.front());
            free_comp.pop();
            del(Y);
        } else {
            comp[cc[X]].pop_back();
            if (!comp[cc[X]].empty()) free_comp.push(cc[X]);
            free_comp.pop();
            del(X);
            X = Y;
        }
    }
    cout << "! " << X << endl;
}
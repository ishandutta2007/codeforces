#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, a, b, da, db;
vector <int> g[nax];
int dist[nax];
int mx_dist;
int mx_node;

void dfs(int node, int parent, int cur_dist) {
    dist[node] = cur_dist;

    if (dist[node] > mx_dist) {
        mx_dist = dist[node];
        mx_node = node;
    }

    for (int i : g[node]) {
        if (i == parent) continue;
        dfs(i, node, cur_dist + 1);
    }
}

bool solve() {
    cin >> n >> a >> b >> da >> db;

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    if (db <= da * 2) return true; /// alice will surely win

    mx_node = -1;
    mx_dist = -1;
    dfs(a, 0, 0);

    if (dist[b] <= da) {
        return true;
    }
    int sav = mx_node;
    mx_node = -1;
    mx_dist = -1;
    dfs(sav, 0, 0);


    if (2 * da >= mx_dist) {
        return true;
    } else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "Alice" : "Bob") << '\n';
        for (int i = 1 ; i <= n ; ++ i)
            g[i].clear();
    }
}
/*
    Good Luck
        -Lucina
*/
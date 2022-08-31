#include <bits/stdc++.h>
using namespace std;
int n, m;
int clr[505];
int prv[505];
vector < int > g[505];
vector < int > cycle;
int sz = 0;
vector < pair < int, int > > edges;
bool dfs(int v, int ind) {
    //cout << x << " " << y << endl;
    //if (x > 0) cout << "HERE " << v << endl;
    clr[v] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (ind >= 0 && v == edges[ind].first && to == edges[ind].second) continue;
        //if (v == x && to == y) continue;
        if (clr[to] == 1) {
            if (cycle.size() > 0 && ind == -1) continue;
            /*if (sz > 0 && ind == -1) {
                cout << "NO";
                exit(0);
            }*/
            int x = v;
            cycle.push_back(x);
            while (x != to) {
                x = prv[x];
                cycle.push_back(x);
            }
            sz++;
            return true;
        }
        if (clr[to] == 0) {
            prv[to] = v;
            if (dfs(to, ind)) return true;
        }
    }
    clr[v] = 2;
    return false;
}
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (clr[i] == 0) dfs(i, -1);
    }
    if (cycle.size() == 0) {
        cout << "YES";
        return 0;
    }
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i < cycle.size(); i++) {
        edges.push_back(make_pair(cycle[i], cycle[(i + 1) % cycle.size()]));
    }
    for (int i = 0; i < edges.size(); i++) {
        //cout << edges[i].first << " " << edges[i].second << " " << i << endl;
        bool ok = false;
        for (int j = 1; j <= n; j++) clr[j] = 0;
        for (int j = 1; j <= n; j++) prv[j] = 0;
        //ok |= dfs(cycle[0], i);
        if (!ok) {
            for (int j = 1; j <= n; j++) {
                if (clr[j] == 0) ok |= dfs(j, i);
                if (ok) break;
            }
        }
        //cout << i << '\n';
        if (!ok) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
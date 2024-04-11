#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[200005];
queue <int> q;
int d[200005];
int dad[200005];
int p[200005];
int pos[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v: adj[u]) if (!d[v]) {
            d[v] = d[u] + 1;
            dad[v] = u;
            q.push(v);
        }
    }
    for (int i = 1; i <= n; ++i) cin >> p[i], pos[p[i]] = i;
    if (p[1] != 1) return cout << "No" << endl, 0;
    for (int i = 2; i <= n; ++i) {
        int u = p[i-1], v = p[i];
        if (d[u] > d[v]) return cout << "No" << endl, 0;
        if (pos[dad[u]] > pos[dad[v]]) return cout << "No" << endl, 0;
    }
    cout << "Yes" << endl;
    return 0;
}
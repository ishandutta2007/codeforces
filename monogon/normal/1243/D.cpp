
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, u, v;
set<int> adj[N];

int dsu[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + n, -1);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(adj[i].size() < adj[m].size()) m = i;
    }
    for(int i = 0; i < n; i++) {
        if(adj[m].count(i) == 0) {
            join(m, i);
        }
    }
    for(int x : adj[m]) {
        for(int i = 0; i < n; i++) {
            if(adj[x].count(i) == 0) {
                join(x, i);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(dsu[i] < 0) cnt++;
    }
    cout << (cnt - 1) << endl;
}
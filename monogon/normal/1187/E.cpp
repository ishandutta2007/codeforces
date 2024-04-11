
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, u, v;
vector<int> adj[N];
ll sz[N], pts[N]; // size of subtree

void dfs(int x, int p) {
    sz[x] = 1;
    for(int u : adj[x]) {
        if(u != p) {
            dfs(u, x);
            sz[x] += sz[u];
            pts[x] += pts[u];
        }
    }
    pts[x] += sz[x];
}
void dfs2(int x, int p, ll points) {
    if(p != -1) {
        pts[x] = points + n - 2 * sz[x];
    }
    for(int u : adj[x]) {
        if(u != p) {
            dfs2(u, x, pts[x]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    dfs(0, -1);
    dfs2(0, -1, 0);
    ll M = 0;
    for(int i = 0; i < n; i++) {
        M = max(M, pts[i]);
    }
    cout << M << endl;
}
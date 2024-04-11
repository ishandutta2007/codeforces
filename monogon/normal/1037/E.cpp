
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// imagine the process in reverse
// we start with all edges
// a node with degree < k cannot go on trip,
// and will never be able to go. Unmark them.
// Then decrement their friends' degrees
// at every time, answer with the number of marked nodes

const int N = 2e5 + 5;
int n, m, k, u[N], v[N], ans[N];
vector<int> adj[N];
int deg[N];
bool vis[N];
int cnt = 0;

void unmark(int x) {
    if(vis[x]) return;
    cnt--;
    vis[x] = true;
    for(int y : adj[x]) {
        deg[y]--;
        if(deg[y] < k) unmark(y);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
        deg[u[i]]++;
        deg[v[i]]++;
    }
    cnt = n;
    for(int i = 1; i <= n; i++) {
        if(deg[i] < k) unmark(i);
    }
    for(int i = m - 1; i >= 0; i--) {
        ans[i] = cnt;
        adj[u[i]].pop_back();
        adj[v[i]].pop_back();
        if(!vis[v[i]]) deg[u[i]]--;
        if(!vis[u[i]]) deg[v[i]]--;
        if(deg[u[i]] < k) unmark(u[i]);
        if(deg[v[i]] < k) unmark(v[i]);
    }
    for(int i = 0; i < m; i++) {
        cout << ans[i] << '\n';
    }
}
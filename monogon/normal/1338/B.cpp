
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, a, b;
vector<int> adj[N];
bool vis[N];
int depth[N], par[N], cnt[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = 1 + depth[x];
            par[y] = x;
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 1;
    for(int i = 1; i <= n; i++) {
        if((int) adj[i].size() > 1) {
            root = i;
            break;
        }
    }
    par[root] = root;
    dfs(root);
    for(int i = 1; i <= n; i++) {
        if((int) adj[i].size() == 1) {
            cnt[par[i]]++;
            root = i;
        }
    }
    int ans = n - 1;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] > 0) {
            ans -= (cnt[i] - 1);
        }
    }
    fill(vis, vis + n + 1, false);
    depth[root] = 0;
    dfs(root);
    int minans = 1;
    for(int i = 1; i <= n; i++) {
        if((int) adj[i].size() == 1 && depth[i] % 2 == 1) {
            minans = 3;
        }
    }
    cout << minans << " " << ans << endl;
}
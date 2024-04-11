
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, u, v, a[N], dp[N], dp2[N], ans[N];
vector<int> adj[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    int sum = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            sum += dp[y];
        }
    }
    dp[x] = max(0, a[x] + sum);
}
void dfs2(int x) {
    vis[x] = true;
    int sum = dp2[x];
    for(int y : adj[x]) {
        if(!vis[y]) {
            sum += dp[y];
        }
    }
    ans[x] = a[x] + sum;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dp2[y] = max(0, a[x] + sum - dp[y]);
            dfs2(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) a[i] = -1;
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    fill(vis, vis + N, false);
    dfs2(0);
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 205;
int n, k, u, v;
vector<int> adj[N];
int dp[N][N];
bool vis[N];
int a[N];

void dfs(int x) {
    vis[x] = true;
    int j = 0;
    for(int i = 0; i < adj[x].size(); i++) {
        int y = adj[x][i];
        if(!vis[y]) {
            dfs(y);
            adj[x][i - j] = y;
        }else j++;
    }
    adj[x].erase(adj[x].end() - j, adj[x].end());
}

int solve(int x, int j) {
    if(j < 0) j = 0;
    if(dp[x][j] != -1) return dp[x][j];
    int len = adj[x].size();
    int w = 0, sum = 0;
    for(int m = j; m <= k / 2; m++) {
        sum = 0;
        for(int y : adj[x]) {
            sum += solve(y, k - m - 1);
        }
        for(int y : adj[x]) {
            w = max(w, sum - solve(y, k - m - 1) + solve(y, m - 1));
        }
    }
    if(j > k / 2) {
        sum = 0;
        for(int y : adj[x]) {
            sum += solve(y, j - 1);
        }
        w = max(w, sum);
    }
    if(j == 0) {
        sum = 0;
        for(int y : adj[x]) {
            sum += solve(y, k - 1);
        }
        w = max(w, sum + a[x]);
    }
    return dp[x][j] = w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    k++;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j] = -1;
        }
    }
    dfs(0);
    cout << solve(0, 0) << endl;
}
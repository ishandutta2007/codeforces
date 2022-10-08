
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// at most 2 nodes should have 0 in-degree
// n <= 3000
// delete edge, and answer case for one mother node in each subtree
// case for 1 root. Find cost for a particular root. Cost to move across edge: only changes direction of this one edge

const int N = 3005;
int n, a[N], b[N], ans, dp[N];
vi adj[2][N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    dp[x] = 0;
    for(int y : adj[0][x]) {
        if(!vis[y]) {
            dfs(y);
            dp[x] += dp[y];
        }
    }
    for(int y : adj[1][x]) {
        if(!vis[y]) {
            dfs(y);
            dp[x] += 1 + dp[y];
        }
    }
}
void dfs2(int x) {
    vis[x] = true;
    int res = dp[x];
    for(int y : adj[0][x]) {
        if(!vis[y]) {
            dp[y] = 1 + dp[x];
            dfs2(y);
            res = min(res, dp[y]);
        }
    }
    for(int y : adj[1][x]) {
        if(!vis[y]) {
            dp[y] = -1 + dp[x];
            dfs2(y);
            res = min(res, dp[y]);
        }
    }
    dp[x] = res;
}

void solve(int e) {
    rep(i, 1, n + 1) {
        adj[0][i].clear();
        adj[1][i].clear();
    }
    rep(i, 0, n - 1) {
        if(i != e) {
            adj[0][a[i]].push_back(b[i]);
            adj[1][b[i]].push_back(a[i]);
        }
    }
    fill(vis + 1, vis + n + 1, false);
    dfs(a[e]);
    fill(vis + 1, vis + n + 1, false);
    dfs(b[e]);
    fill(vis + 1, vis + n + 1, false);
    dfs2(a[e]);
    fill(vis + 1, vis + n + 1, false);
    dfs2(b[e]);
    ans = min(ans, dp[a[e]] + dp[b[e]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ans = n - 1;
    rep(i, 0, n - 1) {
        cin >> a[i] >> b[i];
    }
    rep(i, 0, n - 1) {
        solve(i);
    }
    cout << ans << '\n';
}
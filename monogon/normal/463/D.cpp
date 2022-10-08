
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

const int K = 6, N = 1005;
int n, k;
int p, pos[K][N], dp[N];
vi adj[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    dp[x] = 1;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
        dp[x] = max(dp[x], 1 + dp[y]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, k) {
        rep(j, 0, n) {
            cin >> p;
            pos[i][p] = j;
        }
    }
    rep(i, 1, n + 1) rep(j, 1, n + 1) {
        rep(l, 0, k) {
            if(pos[l][i] >= pos[l][j]) goto endloop;
        }
        // i -> j
        adj[i].push_back(j);
        endloop:;
    }
    int ans = 1;
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i);
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << '\n';
}
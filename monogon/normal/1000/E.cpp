
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

const int N = 3e5 + 5;
int n, m, u, v, depth[N], reach[N], dp[N], ans = 0;
vi adj[N];
bool vis[N], bridge[N];

void dfs(int x, int p = 0) {
    vis[x] = true;
    reach[x] = depth[x];
    dp[x] = 0;
    vi ve;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            dfs(y, x);
            if(reach[y] > depth[x]) bridge[y] = true;
            ve.push_back(dp[y] + bridge[y]);
            reach[x] = min(reach[x], reach[y]);
        }else if(y != p) {
            reach[x] = min(reach[x], depth[y]);
        }
    }
    int arr[2] = {0, 0};
    partial_sort_copy(all(ve), arr, arr + 2, greater<int>());
    ans = max(ans, arr[0] + arr[1]);
    dp[x] = arr[0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << ans << '\n';
}
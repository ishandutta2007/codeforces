
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, k, u, v;
vi adj[N];
bool vis[N], leaf[N];
int dp[N], cnt[N], sum[N];

void dfs(int x) {
    vis[x] = true;
    sum[x] = 0;
    bool leaf2 = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            if(leaf[y]) cnt[x]++;
            leaf2 &= leaf[y];
            sum[x] += dp[y];
        }
    }
    leaf[x] = (leaf2 && cnt[x] % k == 0);
    dp[x] = sum[x] + cnt[x] / k;
}

void dfs2(int x) {
    vis[x] = true;
    dp[x] = sum[x] + cnt[x] / k;
    for(int y : adj[x]) {
        if(!vis[y]) {
            // is x leaf-able?
            // deg - 1 == cnt[x] - leaf[y]
            // (cnt[x] - leaf[y]) % k == 0
            // S -= dp[y]
            bool L = (sz(adj[x]) - 1 == cnt[x] - leaf[y] && (cnt[x] - leaf[y]) % k == 0);
            cnt[y] += L;
            sum[y] += (sum[x] - dp[y]) + (cnt[x] - leaf[y]) / k;
            dfs2(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        rep(i, 1, n + 1) adj[i].clear();
        rep(i, 0, n - 1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        fill(dp + 1, dp + n + 1, 0);
        fill(vis + 1, vis + n + 1, false);
        fill(leaf + 1, leaf + n + 1, false);
        fill(cnt + 1, cnt + n + 1, 0);
        dfs(1);
        fill(vis + 1, vis + n + 1, false);
        dfs2(1);
        cout << *max_element(dp + 1, dp + n + 1) << '\n';
    }
}
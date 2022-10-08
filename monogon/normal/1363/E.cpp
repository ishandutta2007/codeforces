
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
int n, b[N], c[N], u, v, dp[N];
ll a[N];
vi adj[N];
bool vis[N];
ll cost = 0;

void dfs(int x) {
    vis[x] = true;
    int sum0 = (b[x] == 0 && c[x] == 1), sum1 = (b[x] == 1 && c[x] == 0);
    for(int y : adj[x]) {
        if(!vis[y]) {
            a[y] = min(a[y], a[x]);
            dfs(y);
            if(dp[y] < 0) {
                sum0 -= dp[y];
            }else {
                sum1 += dp[y];
            }
        }
    }
    cost += a[x] * 2 * min(sum0, sum1);
    dp[x] = sum1 - sum0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i] >> b[i] >> c[i];
    }
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    if(dp[1] != 0) {
        cout << "-1\n";
    }else {
        cout << cost << '\n';
    }
}
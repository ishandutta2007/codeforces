
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5;
int n, k;
vi adj[N];
array<ll, 5> dp[N];
ll sum[N];

void dfs(int x, int p) {
    sum[x] = 0;
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
            rep(i, 0, k) {
                dp[x][(i + 1) % k] += dp[y][i];
            }
            sum[x] += sum[y];
        }
    }
    sum[x] += dp[x][0];
    dp[x][k - 1]++;
}

void dfs2(int x, int p) {
    for(int y : adj[x]) {
        if(y != p) {
            ll sumtmp = sum[y];
            array<ll, 5> dptmp;
            rep(i, 0, k) dptmp[i] = dp[y][i];
            dp[y][k - 1]--;
            sum[y] -= dp[y][0];
            rep(i, 0, k) {
                dp[y][(i + 1) % k] += dp[x][i] - dptmp[(i + k - 1) % k];
            }
            sum[y] += sum[x] - sumtmp - dptmp[k - 1];
            sum[y] += dp[y][0];
            dp[y][k - 1]++;
            dfs2(y, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    dfs2(1, -1);
    cout << accumulate(sum + 1, sum + n + 1, 0LL) / 2 << '\n';
}

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

const int N = 1e5 + 5;
int n;
vi adj[N];
int dp[N], par[N];
int u1 = -1, v1 = -1, u2 = -1, v2 = -1;
int leaf[N];

void dfs(int x, int p) {
    par[x] = p;
    dp[x] = 1;
    leaf[x] = x;
    for(int y : adj[x]) {
        if(y != p) {
            dfs(y, x);
            dp[x] += dp[y];
            leaf[x] = leaf[y];
        }
    }
    if(dp[x] * 2 == n) {
        u1 = leaf[x];
        v1 = par[leaf[x]];
        u2 = leaf[x];
        v2 = p;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        rep(i, 1, n + 1) adj[i].clear();
        rep(i, 0, n - 1) {
            int u, v;
            cin >> u >> v;
            u1 = u2 = u;
            v1 = v2 = v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, -1);
        cout << u1 << ' ' << v1 << '\n' << u2 << ' ' << v2 << '\n';
    }
}
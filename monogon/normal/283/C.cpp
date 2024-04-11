
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

// b_i distinct and c_i distinct => paths and cycles.
// cycle => impossible
// for a path. increasing numbers of coins of the different types
// how many ways to achieve value W?
// for a path 1--2--3--4
// pretend there are actually four coins of these values:
// a[1], a[1]+a[2], a[1]+a[2]+a[3], a[1]+a[2]+a[3]+a[4]
// any combination of these satisfies the rule of the path.
// prefix sum array of values on path => new set of coins
// with the new coin values, the answer is just the number of ways to get the values to sum to t.
// usual O(n * t) coin-change problem.

// 7 + 3
// 3 + 3 + 2 + 2
// 2 + 2 + 2 + 2 + 2
// 8 + 2

const int N = 305, T = 1e5 + 5, M = 1e9 + 7;
int n, q, t, b[N], c[N], vis[N], depth[N];
vi adj[N], adjr[N];
ll ways[T], a[N];

void dfs(int x) {
    vis[x] = 1;
    for(int y : adj[x]) {
        if(vis[y] == 1) {
            cout << "0\n";
            exit(0);
        }else if(!vis[y]) {
            dfs(y);
        }
        a[x] += a[y];
    }
    vis[x] = 2;
}
void dfs2(int x) {
    vis[x] = 1;
    for(int y : adjr[x]) {
        if(vis[y] == 1) {
            cout << "0\n";
            exit(0);
        }else if(!vis[y]) {
            dfs2(y);
        }
        depth[x] = depth[y] + 1;
        t = max(-1LL, t - a[x] * depth[x]);
    }
    vis[x] = 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> t;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 0, q) {
        cin >> b[i] >> c[i];
        adj[c[i]].push_back(b[i]);
        adjr[b[i]].push_back(c[i]);
    }
    rep(i, 1, n + 1) {
        if(!vis[i]) dfs2(i);
    }
    fill(vis + 1, vis + n + 1, 0);
    rep(i, 1, n + 1) {
        if(!vis[i]) dfs(i);
    }
    if(t < 0) {
        cout << "0\n";
        return 0;
    }
    ways[0] = 1;
    rep(i, 1, n + 1) {
        rep(j, 0, t - a[i] + 1) {
            (ways[j + a[i]] += ways[j]) %= M;
        }
    }
    cout << ways[t] << '\n';
}
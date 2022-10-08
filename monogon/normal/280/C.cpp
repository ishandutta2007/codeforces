
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

// either delete root, or delete something in one of its subtrees
// random sequence of values selected from [1, n]
// when the first 1 appears, how many vertices are not a child of a previously listed node?
// let's say 1 appears first at spot k
// 1 step by default
// what is the probability that node in spot i is not a descendant of a previous node?
// each node has probability P(depth = d) of being at depth d,
// then probability 

const int N = 1e5 + 5;
int n, u, v, depth[N];
vi adj[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            depth[y] = depth[x] + 1;
            dfs(y);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n - 1) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    double ans = 1.0;
    rep(i, 2, n + 1) {
        ans += 1.0 / (1 + depth[i]);
    }
    cout << fixed << setprecision(8);
    cout << ans << '\n';
}
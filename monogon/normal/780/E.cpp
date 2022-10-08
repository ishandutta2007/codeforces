
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

// ceil(2n / k)
// visit every vertex in k paths
// k = 1? we can traverse the tree, returning to parent.
// This traversal has length at most 2n, so we can split it up into k steps.

const int N = 2e5 + 5;
int n, m, k, u, v;
vi adj[N], trav;
bool vis[N];

void dfs(int x) {
    trav.push_back(x);
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            trav.push_back(x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    rep(i, 0, m) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int amt = (2 * n + k - 1) / k;
    int j = 0;
    rep(i, 0, k) {
        int c = min(amt, sz(trav) - j);
        if(c == 0) {
            cout << "1 1\n";
            continue;
        }
        cout << c << ' ';
        rep(l, 0, c) {
            cout << trav[j + l] << ' ';
        }
        cout << '\n';
        j += c;
    }
}
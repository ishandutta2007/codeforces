
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

// if no subtree has majority => ask s, find subtree to eliminate at least half the nodes
// otherwise, follow largest subtree sizes until no subtree has a majority, or we reach depth of x
// ask distance to determine if in this subtree. If in, good. Ask s query
// otherwise, we can find LCA of this node and x, and go to a different subtree
// d = depth[y] + depth[x] - 2 depth[LCA] => compute depth[LCA] => we know it
// go down different branch with s query => eliminate at least half the nodes

const int N = 2e5 + 5;
int n, u, v, depth[N], dp[N], par[N], depthx;
vi adj[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    dp[x] = 1;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y] = x;
            depth[y] = 1 + depth[x];
            dfs(y);
            dp[x] += dp[y];
        }
    }
}

int askd(int u) {
    cout << "d " << u << endl;
    int d;
    cin >> d;
    if(d == -1) exit(0);
    return d;
}
int asks(int u) {
    cout << "s " << u << endl;
    int s;
    cin >> s;
    if(s == -1) exit(0);
    return s;
}

void solve(int r) {
    int y = r;
    while(depth[y] < depthx) {
        int y2 = -1;
        for(int z : adj[y]) {
            if(z != par[y] && 2 * dp[z] >= dp[y]) {
                y2 = z;
            }
        }
        if(y2 == -1) break;
        else y = y2;
    }
    int d = askd(y);
    assert((depthx + depth[y] - d) % 2 == 0);
    int depthlca = (depthx + depth[y] - d) / 2;
    while(depth[y] > depthlca) y = par[y];
    if(depth[y] == depthx) {
        cout << "! " << y << endl;
        return;
    }
    int s = asks(y);
    solve(s);
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
    depthx = askd(1);
    solve(1);
}
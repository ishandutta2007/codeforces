
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

// function graph, except some may have no
// outgoing edge because no one is at that node
// multiply answers for components together
// if component has no sink, i.e. a cycle, answer is 2
// otherwise, reverse edges make it a tree. Then the answer is number of nodes.

const int N = 2e5 + 5, M = 1e9 + 7;
int n, u, v, vis[N], vis2[N];
vi adj[N], adjr[N];
int focus = 0;
bool loop = false, cyc = false;

void dfs(int x) {
    vis[x] = 1;
    if(sz(adj[x]) == 0) focus = x;
    for(int y : adj[x]) {
        if(y == x) loop = true;
        if(!vis[y]) {
            dfs(y);
        }else if(vis[y] == 1) {
            cyc = true;
            focus = y;
        }
    }
    vis[x] = 2;
}
ll dfs2(int x) {
    vis2[x] = true;
    ll ret = 1;
    for(int y : adjr[x]) {
        if(!vis2[y]) {
            ret += dfs2(y);
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> u >> v;
        adj[u].push_back(v);
        adjr[v].push_back(u);
    }
    ll ans = 1;
    rep(i, 1, 2 * n + 1) {
        if(sz(adj[i]) > 0 && !vis2[i]) {
            focus = -1;
            loop = cyc = false;
            dfs(i);
            if(cyc) {
                if(!loop) ans = (ans * 2) % M;
                dfs2(focus);
            }else {
                ans = (ans * dfs2(focus)) % M;
            }
        }
    }
    cout << ans << '\n';
}
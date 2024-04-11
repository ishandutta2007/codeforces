
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;
int n, u, v, l[N], r[N], child[N], sz[N];
bool vis[N];
vector<int> adj[N];

void dfs(int x) {
    vis[x] = true;
    sz[x] = 1;
    child[x] = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            child[x]++;
            sz[x] += sz[y];
        }
    }
}
void solve(int x, bool left, int anchor) {
    vis[x] = true;
    if(left) {
        l[x] = anchor + child[x];
        r[x] = anchor + 2 * sz[x] - 1;
        anchor = l[x];
        int i = 0;
        for(int y : adj[x]) {
            if(!vis[y]) {
                i++;
                anchor += 2 * sz[y] - 1;
                solve(y, false, anchor);
                l[y] = l[x] - i;
            }
        }
    }else {
        r[x] = anchor - child[x];
        l[x] = anchor - 2 * sz[x] + 1;
        anchor = r[x];
        int i = 0;
        for(int y : adj[x]) {
            if(!vis[y]) {
                i++;
                anchor -= 2 * sz[y] - 1;
                solve(y, true, anchor);
                r[y] = r[x] + i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    fill(vis, vis + N, false);
    solve(1, true, 1);
    for(int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << endl;
    }
}

#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int n, m, u, v, k;
vector<int> adj[N];
bool vis[N], sel[N];
int par[N], depth[N];
bool flag = false;
vector<int> ind;

void printcycle(int x, int y) {
    if(flag) return;
    flag = true;
    cout << 2 << endl;
    vector<int> v = {x};
    while(x != y) {
        v.push_back(x = par[x]);
    }
    cout << v.size() << endl;
    for(int a : v) {
        cout << a << " ";
    }
    cout << endl;
}

int dfs(int x) {
    vis[x] = true;
    int reach = INT_MAX, reach2 = depth[x];
    bool selflag = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y] = x;
            depth[y] = depth[x] + 1;
            reach = min(reach, dfs(y));
            if(sel[y]) selflag = false;
        }else if(depth[x] - depth[y] + 1 >= k) {
            printcycle(x, y);
        }else {
            reach2 = min(reach2, depth[y]);
        }
    }
    if(reach > depth[x] && selflag) {
        ind.push_back(x);
        sel[x] = true;
        return reach2;
    }
    return reach;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(k * k < n) k++;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1] = 1;
    dfs(1);
    if(!flag) {
        assert((int) ind.size() >= k);
        cout << 1 << endl;
        for(int i = 0; i < k; i++) {
            cout << ind[i] << " ";
        }
        cout << endl;
    }
}
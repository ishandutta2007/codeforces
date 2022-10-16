#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, K;
bool a[200005];
vi adj[200005];
int sz[200005];
int dad[200005];
int root;
int h[200005];
ll ans;

void prep(int u) {
    sz[u] = a[u];
    int v;
    ff(i, 0, (int)adj[u].size() - 1) {
        v = adj[u][i];
        if (v == dad[u]) continue;
        dad[v] = u;
        prep(v);
        sz[u] += sz[v];
    }
}

void find_root(int u) {
    int v;
    ff(i, 0, (int)adj[u].size() - 1) {
        v = adj[u][i];
        if (v == dad[u]) continue;
        if (sz[v] > K) { find_root(v); return; }
    }
    root = u;
}

void dfs(int u) {
    if (a[u]) ans += h[u];
    int v;
    ff(i, 0, (int)adj[u].size() - 1) {
        v = adj[u][i];
        if (h[v] || v == root) continue;
        h[v] = h[u] + 1; dfs(v);
    }
}

int main(void) {
    cin >> N >> K;
    ff(i, 1, 2 * K) { int x; cin >> x; a[x] = 1; }
    int u, v;
    ff(i, 1, N - 1) {
        cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    prep(1);
    find_root(1);
    dfs(root);
    cout << ans << endl;
    return 0;
}
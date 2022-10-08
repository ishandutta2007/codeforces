
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

const int N = 1005;
int t, n, u, v;
vi adj[N];
bool vis[N];
int depth[N], par[N][20], tin[N], tout[N], ti = 0;

pii ask(vi &ve) {
    int k = sz(ve);
    assert(k > 0);
    cout << "? " << k;
    for(int x : ve) {
        cout << ' ' << x;
    }
    cout << endl;
    int x, d;
    cin >> x >> d;
    assert(x != -1);
    return {x, d};
}

void dfs(int x) {
    tin[x] = ti++;
    vis[x] = true;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y][0] = x;
            depth[y] = 1 + depth[x];
            dfs(y);
        }
    }
    tout[x] = ti++;
}
bool anc(int x, int y) {
    return tin[x] <= tin[y] && tout[y] <= tout[x];
}
int lca(int x, int y) {
    if(anc(x, y)) return x;
    for(int l = 19; l >= 0; l--) {
        if(!anc(par[x][l], y)) x = par[x][l];
    }
    return par[x][0];
}
int dist(int x, int y) {
    return depth[x] + depth[y] - 2 * depth[lca(x, y)];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        rep(i, 1, n + 1) {
            adj[i].clear();
        }
        rep(i, 0, n - 1) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vi ve(n, 0);
        iota(all(ve), 1);
        int x, d;
        tie(x, d) = ask(ve);
        int y = x;
        fill(vis + 1, vis + n + 1, false);
        fill(depth + 1, depth + n + 1, 0);
        ti = 0;
        par[x][0] = x;
        dfs(x);
        // int root = x;
        rep(l, 1, 20) {
            rep(i, 1, n + 1) {
                par[i][l] = par[par[i][l - 1]][l - 1];
            }
        }
        int D = d;

        while(d > 0) {
            ve.clear();
            rep(i, 1, n + 1) {
                int dd = dist(x, y);
                int dix = dist(i, x);
                int diy = dist(i, y);
                if((diy == dix + dd && dix == (d + 1) / 2) || (dix == diy + dd && diy == (d + 1) / 2)) {
                    ve.push_back(i);
                }
            }
            int z, d2;
            tie(z, d2) = ask(ve);
            if(anc(y, z)) {
                y = z;
            }else {
                x = z;
            }
            d = D - dist(x, y);
        }

        cout << "! " << x << ' ' << y << endl;
        string s;
        cin >> s;
        if(s == "Incorrect") return 0;
    }
}
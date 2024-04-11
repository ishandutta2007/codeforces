
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

const int N = 2e5 + 5;
int dsu[N], si[N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}

void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int depth[N], par[N];
vi adj[N];

void dfs(int x, int p) {
    par[x] = p;
    si[x] = 1;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = depth[x] + 1;
            dfs(y, x);
            si[x] += si[y];
        }
    }
}

vi ve;

void lca(int u, int v) {
    int subu = 0, subv = 0;
    while(depth[u] > depth[v]) {
        ve.push_back(si[u] - subu);
        subu = si[u];
        u = par[u];
    }
    while(depth[v] > depth[u]) {
        ve.push_back(si[v] - subv);
        subv = si[v];
        v = par[v];
    }
    while(u != v) {
        ve.push_back(si[u] - subu);
        subu = si[u];
        u = par[u];

        ve.push_back(si[v] - subv);
        subv = si[v];
        v = par[v];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        fill(dsu, dsu + n + 1, -1);
        rep(i, 1, n + 1) adj[i].clear();
        int eu, ev;
        rep(i, 0, n) {
            int u, v;
            cin >> u >> v;
            if(trace(u) == trace(v)) {
                eu = u; ev = v;
            }else {
                join(u, v);
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        depth[1] = 0;
        dfs(1, -1);
        ve.clear();
        lca(eu, ev);
        int sum = n - accumulate(all(ve), 0);
        ve.push_back(sum);
        ll ans = 2LL * n * (n - 1) / 2;
        for(int x : ve) {
            ans -= 1LL * x * (x - 1) / 2;
        }
        cout << ans << '\n';
    }
}
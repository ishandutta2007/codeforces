
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

const int N = 2e5 + 5;
int n, m, k, u, v;
vi adj[N];
int vis[N], par[N], depth[N];
pii cyc = {-1, -1};
int best = 1e9;

void indep(vi &ve) {
    cout << "1\n";
    rep(i, 0, (k + 1) / 2) {
        cout << ve[i] << ' ';
    }
    cout << '\n';
}

void solve(int x, int y) {
    vi ve;
    ve.push_back(x);
    while(x != y) {
        x = par[x];
        ve.push_back(x);
    }
    if(sz(ve) > k) {
        vi ve2;
        for(int i = 0; i < sz(ve); i += 2) {
            ve2.push_back(ve[i]);
        }
        indep(ve2);
        return;
    }else {
        cout << "2\n";
        cout << sz(ve) << '\n';
        for(int x : ve) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

void dfs(int x) {
    vis[x] = 1;
    for(int y : adj[x]) {
        if(!vis[y]) {
            par[y] = x;
            depth[y] = 1 + depth[x];
            dfs(y);
        }else if(vis[y] == 1 && y != par[x]) {
            // cycle
            if(depth[x] - depth[y] + 1 < best) {
                best = depth[x] - depth[y] + 1;
                cyc = {x, y};
            }
        }
    }
    vis[x] = 2;
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
    if(best < N) {
        solve(cyc.first, cyc.second);
        return 0;
    }
    vi ve0, ve1;
    rep(i, 1, n + 1) {
        if(depth[i] % 2 == 0) {
            ve0.push_back(i);
        }else {
            ve1.push_back(i);
        }
    }
    if(sz(ve0) >= (k + 1) / 2) {
        indep(ve0);
    }else {
        indep(ve1);
    }
}
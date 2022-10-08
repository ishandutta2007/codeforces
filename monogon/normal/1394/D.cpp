
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
int n;
ll t[N], h[N];
vi adj[N];
int aval[N], bval[N];
bool vis[N];
ll dp[N], dpa[N], dpb[N];

void dfs_color(int x, int p, bool c) {
    if(c) swap(aval[x], bval[x]);
    for(int y : adj[x]) {
        if(y != p) {
            dfs_color(y, x, !c);
        }
    }
}

void dfs(int x) {
    vis[x] = true;
    vi ve;
    ll dif = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            ve.push_back(dpb[y] - dpa[y]);
            dif += dpa[y];
        }
    }
    sort(ve.rbegin(), ve.rend());
    int s = sz(ve);
    rep(i, 0, s + 1) {
        // update dp
        dp[x] = max(dp[x], dif + t[x] * min(aval[x] + s - i, bval[x] + i));
        dpa[x] = max(dpa[x], dif + t[x] * min(aval[x] + s - i + 1, bval[x] + i));
        dpb[x] = max(dpb[x], dif + t[x] * min(aval[x] + s - i, bval[x] + i + 1));
        if(i < s) {
            dif += ve[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> t[i];
    }
    rep(i, 1, n + 1) {
        cin >> h[i];
    }
    ll ans = 0;
    vector<pii> ve;
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        ans += t[u] + t[v];
        if(h[u] < h[v]) {
            aval[u]++;
            bval[v]++;
        }else if(h[u] > h[v]) {
            bval[u]++;
            aval[v]++;
        }else {
            ve.emplace_back(u, v);
        }
    }
    dfs_color(1, -1, true);
    rep(i, 1, n + 1) {
        adj[i].clear();
    }
    for(auto &pa : ve) {
        int u, v;
        tie(u, v) = pa;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            dfs(i);
            ans -= dp[i];
        }
    }
    cout << ans << '\n';
}
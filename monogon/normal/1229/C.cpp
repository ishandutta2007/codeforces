
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

const int N = 1e5 + 5;
int n, m;
vi adj[N];
int deg[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        adj[u].push_back(v);
        deg[u]++; deg[v]++;
    }
    int q;
    cin >> q;
    ll ans = 0;
    rep(i, 1, n + 1) {
        ans += 1LL * sz(adj[i]) * (deg[i] - sz(adj[i]));
    }
    cout << ans << '\n';
    while(q--) {
        int u;
        cin >> u;
        for(int v : adj[u]) {
            ans -= 1LL * sz(adj[v]) * (deg[v] - sz(adj[v]));
            adj[v].push_back(u);
            ans += 1LL * sz(adj[v]) * (deg[v] - sz(adj[v]));
        }
        ans -= 1LL * sz(adj[u]) * (deg[u] - sz(adj[u]));
        adj[u].clear();
        cout << ans << '\n';
    }
}

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
int t, n, m, u, v;
vi adj[N];
vi del;
int dist[N];
bool vis[N];

void dfs(int x) {
    vis[x] = true;
    dist[x] = 0;
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
        }
        if(dist[y] < 2) {
            dist[x] = max(dist[x], 1 + dist[y]);
        }
    }
    if(dist[x] >= 2) {
        del.push_back(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        fill(vis + 1, vis + n + 1, 0);
        rep(i, 1, n + 1) {
            adj[i].clear();
        }
        del.clear();
        rep(i, 0, m) {
            cin >> u >> v;
            adj[v].push_back(u);
        }
        rep(i, 1, n + 1) {
            if(!vis[i]) dfs(i);
        }
        int k = sz(del);
        assert(7 * k <= 4 * n);
        cout << k << '\n';
        for(int x : del) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}

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

const int N = (1LL << 19) + 10;
int n, a[N], b[N], u[N], v[N];
vi eu, eu2, adj[2 * N];
bool vis[N];

void dfs(int x, int c, int j) {
    bool b1 = (c == a[j]);
    int xx = (b1 ? v[j] : u[j]);
    // int cc = (b1 ? b[j] : a[j]);
    while(!adj[xx].empty()) {
        int i = adj[xx].back();
        adj[xx].pop_back();
        if(!vis[i]) {
            vis[i] = true;
            int y = (v[i] == xx ? v[i] : u[i]);
            int d = (v[i] == xx ? b[i] : a[i]);
            dfs(y, d, i);
        }
    }
    eu.push_back(2 * j + b1 + 1);
    eu.push_back(2 * j + !b1 + 1);
}

void solve(int ans) {
    cout << ans << '\n';
    for(int x : eu2) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
    }
    rep(l, 0, 21) {
        rep(i, 0, 2 * N) {
            adj[i].clear();
        }
        fill(vis, vis + n, false);
        rep(i, 0, n) {
            u[i] = (a[i] & ((1LL << l) - 1));
            v[i] = (b[i] & ((1LL << l) - 1));
            adj[u[i]].push_back(i);
            adj[v[i]].push_back(i);
        }
        rep(i, 0, 2 * N) {
            if(sz(adj[i]) % 2 == 1) {
                solve(l - 1);
                return 0;
            }
        }
        eu.clear();
        vis[0] = true;
        dfs(u[0], a[0], 0);
        if(sz(eu) != 2 * n) {
            solve(l - 1);
            return 0;
        }
        eu2.clear();
        eu2.assign(all(eu));
    }
    solve(20);
}
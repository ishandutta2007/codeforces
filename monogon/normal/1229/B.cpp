
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

const int N = 1e5 + 5, M = 1e9 + 7;
int n;
ll x[N][20];
vi adj[N];
int par[N][20], depth[N];

void dfs(int x, int p) {
    for(int y : adj[x]) {
        if(y != p) {
            par[y][0] = x;
            depth[y] = 1 + depth[x];
            dfs(y, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> x[i][0];
    }
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    par[1][0] = 1;
    dfs(1, -1);
    rep(l, 1, 20) {
        rep(i, 1, n + 1) {
            par[i][l] = par[par[i][l - 1]][l - 1];
            x[i][l] = gcd(x[i][l - 1], x[par[i][l - 1]][l - 1]);
        }
    }
    ll ans = 0;
    rep(i, 1, n + 1) {
        int u = i;
        ll prvval = x[u][0];
        ll add = 0;
        while(u != 1) {
            ll val = gcd(prvval, x[u][0]);
            int prvu = u;
            // highest vertex with gcd = val
            for(int l = 19; l >= 0; l--) {
                if(gcd(val, x[u][l]) == val) {
                    u = par[u][l];
                }
            }
            ll jump = depth[prvu] - depth[u];
            add = (add + (val % M) * jump) % M;
            prvval = val;
        }
        add = (add + x[i][19]) % M;
        // cout << i << ' ' << add << '\n';
        ans = (ans + add) % M;
    }
    cout << ans << '\n';
}
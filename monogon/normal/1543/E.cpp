
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

void solve() {
    int n;
    cin >> n;
    vector<vi> g(1 << n);
    rep(i, 0, n * (1 << (n - 1))) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi p(1 << n);
    vector<bool> vis(1 << n, false);
    queue<int> Q;
    vi dep(1 << n);
    vis[0] = true;
    Q.push(0);
    int c = 0;
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        p[x] = 0;
        for(int y : g[x]) {
            if(vis[y]) {
                if(dep[y] + 1 == dep[x]) {
                    p[x] |= p[y];
                }
            }else {
                dep[y] = 1 + dep[x];
                vis[y] = true;
                Q.push(y);
            }
        }
        if(x != 0 && p[x] == 0) {
            p[x] = (1 << c);
            c++;
        }
    }
    vi P(1 << n);
    rep(i, 0, 1 << n) P[p[i]] = i;
    rep(i, 0, 1 << n) cout << P[i] << ' ';
    cout << '\n';
    if(__builtin_popcount(n) != 1) {
        cout << -1 << '\n';
        return;
    }
    int k = 0;
    while((1 << k) < n) k++;
    vi color = {0, 0};
    rep(i, 1, k + 1) {
        int m = (1 << i);
        vi col(1 << m);
        rep(mask, 0, 1 << m) {
            int a = mask & ((1 << (m / 2)) - 1);
            int b = mask >> (m / 2);
            col[mask] = 2 * color[a ^ b] + (__builtin_popcount(b) % 2);
        }
        color = col;
    }
    rep(i, 0, 1 << n) {
        cout << color[p[i]] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}
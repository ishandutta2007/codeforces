
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> h(N), v(N);
    rep(i, 0, n) {
        int x, y;
        cin >> x >> y;
        h[x].push_back(i);
        v[y].push_back(i);
    }
    vector<vi> g(n);
    string col(n, 'r');
    rep(i, 0, N) {
        for(int j = 0; j + 1 < sz(h[i]); j += 2) {
            g[h[i][j]].push_back(h[i][j + 1]);
            g[h[i][j + 1]].push_back(h[i][j]);
        }
        for(int j = 0; j + 1 < sz(v[i]); j += 2) {
            g[v[i][j]].push_back(v[i][j + 1]);
            g[v[i][j + 1]].push_back(v[i][j]);
        }
    }
    vector<bool> vis(n);
    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = true;
        for(int y : g[x]) {
            if(!vis[y]) {
                col[y] = col[x] ^ 'r' ^ 'b';
                dfs(dfs, y);
            }
        }
    };
    rep(i, 0, n) {
        if(!vis[i]) dfs(dfs, i);
    }
    cout << col << '\n';
}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(2 * n);
    vi a(n), b(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        g[a[i]].push_back(b[i]);
        g[b[i]].push_back(a[i]);
    }
    rep(i, 0, n) {
        g[2 * i].push_back(2 * i + 1);
        g[2 * i + 1].push_back(2 * i);
    }
    vector<bool> vis(2 * n);
    vi col(2 * n);
    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = true;
        for(int y : g[x]) {
            if(!vis[y]) {
                col[y] = col[x] ^ 1;
                dfs(dfs, y);
            }
        }
    };
    rep(i, 0, 2 * n) {
        if(!vis[i]) dfs(dfs, i);
    }
    rep(i, 0, n) {
        cout << col[a[i]] + 1 << ' ' << col[b[i]] + 1 << '\n';
    }
}

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
    vector<vi> g(n);
    rep(i, 0, n) {
        int k;
        cin >> k;
        rep(j, 0, k) {
            int u;
            cin >> u;
            g[i].push_back(u - 1);
        }
    }
    vi vis(n, 0), ans(n, 0);
    bool cyc = false;
    auto dfs = [&](auto dfs, int x) -> void {
        vis[x] = 1;
        ans[x] = 1;
        for(int y : g[x]) {
            if(vis[y] == 1) cyc = true;
            if(vis[y] == 0) {
                dfs(dfs, y);
            }
            ans[x] = max(ans[x], ans[y] + (y > x));
        }
        vis[x] = 2;
    };
    rep(i, 0, n) {
        if(vis[i] == 0) {
            dfs(dfs, i);
        }
    }
    cout << (cyc ? -1 : *max_element(all(ans))) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}
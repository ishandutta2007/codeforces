
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

int query(const vi &ve) {
    cout << "? " << sz(ve) << ' ';
    for(int x : ve) cout << x << ' ';
    cout << endl;
    int a;
    cin >> a;
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vi ve;
    rep(i, 1, n + 1) ve.push_back(i);
    int x = query(ve);
    vector<pii> e;
    auto dfs = [&](auto dfs, int u, int p) -> void {
        for(int v : g[u]) {
            if(v != p) {
                e.push_back({u, v});
                dfs(dfs, v, u);
            }
        }
    };
    dfs(dfs, 1, 1);
    int L = 0, R = sz(e) - 1;
    ve.clear();
    while(L < R) {
        int m = (L + R) / 2;
        ve.clear();
        rep(i, L, m + 1) {
            ve.push_back(e[i].first);
            ve.push_back(e[i].second);
        }
        sort(all(ve));
        ve.erase(unique(all(ve)), ve.end());
        int y = query(ve);
        if(x == y) {
            R = m;
        }else {
            L = m + 1;
        }
    }
    cout << "! " << e[L].first << ' ' << e[L].second << endl;
}
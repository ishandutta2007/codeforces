
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
    int n, k;
    cin >> n >> k;
    k--;
    vector<ll> a(n + 1);
    ll xo = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        xo ^= a[i];
    }
    vector<vi> g(n + 1);
    rep(i, 0, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(xo == 0) {
        cout << "YES\n";
        return;
    }else if(k == 1) {
        cout << "NO\n";
        return;
    }
    bool ok = false;
    auto dfs = [&](auto dfs, int x, int p) -> bool {
        int cnt = 0;
        for(int y : g[x]) {
            if(y != p) {
                cnt += dfs(dfs, y, x);
                a[x] ^= a[y];
            }
        }
        if(cnt >= 2 || (cnt == 1 && a[x] == 0)) ok = true;
        return cnt >= 1 || a[x] == xo;
    };
    dfs(dfs, 1, 1);
    cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}
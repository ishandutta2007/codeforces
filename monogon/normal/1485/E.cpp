
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

const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vi> g(n + 1);
    vector<ll> a(n + 1);
    vi dep(n + 1), par(n + 1);
    vector<vi> row(n + 1);
    vector<ll> dp(n + 1), dp2(n + 1);

    rep(i, 2, n + 1) {
        int p;
        cin >> p;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    function<void(int, int)> dfs = [&](int x, int p) {
        par[x] = p;
        for(int y : g[x]) {
            if(y != p) {
                dep[y] = 1 + dep[x];
                dfs(y, x);
            }
        }
    };
    dfs(1, 1);
    rep(i, 1, n + 1) {
        row[dep[i]].push_back(i);
    }

    rep(i, 2, n + 1) cin >> a[i];
    vector<ll> pre, suf;
    for(int l = n; l >= 0; l--) {
        if(row[l].empty()) continue;
        sort(all(row[l]), [&](int i, int j) { return a[i] < a[j]; });
        int k = sz(row[l]);
        pre.clear();
        suf.clear();
        pre.push_back(-INF);
        rep(idx, 0, k) {
            int i = row[l][idx];
            for(int j : g[i]) {
                dp[i] = max(dp[i], dp2[j]);
            }
            pre.push_back(-a[i] + dp[i]);
            suf.push_back(a[i] + dp[i]);
        }
        rep(i, 1, k) pre[i] = max(pre[i], pre[i - 1]);
        for(int i = k - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);
        ll le = a[row[l][0]], ri = a[row[l].back()];
        rep(idx, 0, k) {
            int i = row[l][idx];
            dp2[i] = max({a[i] + pre[idx], -a[i] + suf[idx], dp[i] + max(a[i] - le, ri - a[i])});
        }
    }
    cout << dp[1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}
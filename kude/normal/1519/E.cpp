#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<ll,ll>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int n;
vector<vector<pair<int, int>>> to;
bool visited[1000000];
VVI ans;
bool used[1000000];
bool dfs(int u, int i_par = -1) {
    visited[u] = true;
    for(auto [v, i]: to[u]) if (i != i_par && !used[i]) {
        if (visited[v]) {
            ans[u].push_back(i), used[i] = true;
        } else {
            bool use = dfs(v, i);
            if (!use) ans[u].push_back(i), used[i] = true;
        }
    }
    if (ans[u].size() % 2) {
        if (i_par != -1) {
            ans[u].push_back(i_par), used[i_par] = true;
            return true;
        } else {
            ans[u].pop_back();
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    VL a(n), b(n), c(n), d(n);
    map<P, int> mp;
    rep(i, n) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        ll x = a[i] * d[i], y = b[i] * c[i], w = b[i] * d[i];
        ll g1 = gcd(x + w, y);
        ll g2 = gcd(x, y + w);
        mp[{(x + w) / g1, y / g1}] = 0;
        mp[{x / g2, (y + w) / g2}] = 0;
    }
    int sz = 0;
    for(auto& [k, v]: mp) v = sz++;
    to.resize(sz);
    rep(i, n) {
        ll x = a[i] * d[i], y = b[i] * c[i], w = b[i] * d[i];
        ll g1 = gcd(x + w, y);
        ll g2 = gcd(x, y + w);
        int u = mp[{(x + w) / g1, y / g1}];
        int v = mp[{x / g2, (y + w) / g2}];
        to[u].emplace_back(v, i);
        to[v].emplace_back(u, i);
    }
    ans.resize(sz);
    rep(i, sz) if (!visited[i]) dfs(i);
    int cnt = 0;
    for(auto& a: ans) cnt += a.size() / 2;
    cout << cnt << '\n';
    for(auto& a: ans) {
        int n = a.size();
        for(int i = 0; i < n; i += 2) {
            cout << a[i] + 1 << ' ' << a[i + 1] + 1 << '\n';
        }
    }
}
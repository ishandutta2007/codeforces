#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= n * 2; i++) {
            cout << (i <= n ? i : i - n) << ' ';
        }
        cout << endl;
        return;
    }
    cout << "Second" << endl;
    vector<int> g(n * 2 + 1);
    vector<int> a(n + 1);
    for (int i = 1; i <= n * 2; i++) {
        int id;
        cin >> id;
        if (a[id]) {
            g[a[id]] = i;
            g[i] = a[id];
        }
        a[id] = i;
    }

    vector<int> used(n * 2 + 1);
    queue<int> q;
    vector<pair<vector<int>, vector<int>>> comps;
    bool odd = false;
    for (int i = 1; i <= n * 2; i++) {
        if (used[i]) continue;
        vector<vector<int>> comp(2);
        used[i] = 1;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            comp[used[v] - 1].push_back(v);
            if (!used[g[v]]) {
                used[g[v]] = 3 - used[v];
                q.push(g[v]);
            }
            int u = v <= n ? v + n : v - n;
            if (!used[u]) {
                used[u] = 3 - used[v];
                q.push(u);
            }
        }
        comps.push_back({comp[0], comp[1]});
    }
    ll total = 0;
    int m = comps.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        for (int v : comps[i].first) {
            total += v;
        }
    }
    for (int i = 0; i < m; i++) {
        if (total % (n * 2) && comps[i].first.size() % 2) {
            ans[i] = 1;
            for (int v : comps[i].first) {
                total -= v;
            }
            for (int v : comps[i].second) {
                total += v;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == 0) {
            for (int v : comps[i].first) {
                cout << v << ' ';
            }
        } else {
            for (int v : comps[i].second) {
                cout << v << ' ';
            }
        }
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}
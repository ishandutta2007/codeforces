#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;
 
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
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
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }


    vector<int> used(n + 1);
    vector<int> radii(n + 1);
    vector<int> dist(n + 1);
    int cur = 0;

    auto bfs = [&](int root) {
        queue<int> q;
        q.push(root);
        used[root] = cur;
        dist[root] = 0;
        int last = root;
        while (!q.empty()) {
            int v = q.front();
            last = v;
            q.pop();
            radii[v] = max(radii[v], dist[v]);
            for (int u : g[v]) {
                if (used[u] != cur) {
                    q.push(u);
                    dist[u] = dist[v] + 1;
                    used[u] = cur;
                }
            }
        }
        return last;
    };

    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        cur = cur + 3;
        int d1 = bfs(i);
        cur--;
        int d2 = bfs(d1);
        cur--;
        bfs(d2);
    }
    vector<vector<int>> comp(n + 1);
    for (int i = 1; i <= n; i++) {
        comp[used[i]].push_back(radii[i]);
    }
    vector<vector<ll>> suf(n + 1);
    for (int i = 1; i <= n; i++) {
        if (comp[i].empty()) break;
        sort(comp[i].begin(), comp[i].end());
        suf[i].resize(comp[i].size());
        for (int j = (int)comp[i].size() - 1; j >= 0; j--) {
            suf[i][j] = comp[i][j];
            if (j + 1 < comp[i].size()) {
                suf[i][j] += suf[i][j + 1];
            }
        }
    }

    map<pair<int, int>, double> mem;
    cout << fixed << setprecision(25);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a = used[a];
        b = used[b];
        if (a == b) {
            cout << "-1\n";
            continue;
        }
        if (mem.count({a, b})) {
            cout << mem[{a, b}] << '\n';
            continue;
        }
        if (comp[a].size() > comp[b].size()) {
            swap(a, b);
        }
        int kek = max(comp[a].back(), comp[b].back());
        double ans = 0;
        ll cnt = 0;
        for (int i = 0; i < comp[a].size(); i++) {
            int need = kek - 1 - comp[a][i];
            int j = lower_bound(comp[b].begin(), comp[b].end(), need) - comp[b].begin();
            int delta = comp[b].size() - j;
            cnt += delta;
            ans += (comp[a][i] + 1) * delta + suf[b][j];
        }
        ans += (1LL * comp[a].size() * comp[b].size() - cnt) * kek;
        ans /= 1LL * comp[a].size() * comp[b].size();
        mem[{a, b}] = mem[{b, a}] = ans;
        cout << ans << '\n';
    }
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
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t, n, m, k, u, v, w;
vector<array<int, 3>> ve;

struct dsu {
    int dsu[N];

    void init() {
        fill(dsu + 1, dsu + n + 1, -1);
    }

    int trace(int u) {
        return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
    }

    bool connect(int u, int v) {
        if ((u = trace(u)) == (v = trace(v))) {
            return false;
        }
        if (dsu[u] > dsu[v]) {
            swap(u, v);
        }
        dsu[u] += dsu[v];
        dsu[v] = u;
        return true;
    }
} dsu;

void solve() {
    cin >> n >> m >> k;
    ve.clear(); dsu.init();
    while (m--) {
        cin >> u >> v >> w;
        ve.push_back({w, u, v});
    }
    sort(ve.begin(), ve.end());
    long long ans = 0;
    for (auto [w, u, v] : ve) {
        if (dsu.connect(u, v)) {
            ans += max(0, w - k);
            
        }
    }
    if (ans == 0) {
        int mi = 1E9 + 7;
        for (auto [w, u, v] : ve) {
            mi = min(mi, abs(w - k));
        }
        ans += mi;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        solve();
    }
}
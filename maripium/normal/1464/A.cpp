#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        vector<int> par(N); iota(par.begin(), par.end(), 0);
        vector<int> sz(N, 1);
        vector<int> deg(N);
        auto get_par = [&](int v) {
            while (v != par[v]) {
                v = par[v] = par[par[v]];
            }
            return v;
        };
        auto merge = [&](int v, int u) {
            v = get_par(v);
            u = get_par(u);
            if (v != u) {
                par[u] = v;
                sz[v] += sz[u];
            }
        };
        for (int i = 0; i < M; ++i) {
            int x, y; cin >> x >> y;
            --x, --y;
            deg[x]++, deg[y] ++;
            merge(x, y);
        }
        vector<bool> ok(N);
        int ans = 0;
        for (int z = 0; z < N; ++z) if (deg[z] == 1) ok[get_par(z)] = true;
        for (int v = 0; v < N; ++v) {
            if (get_par(v) == v) {
                if (sz[v] == 1) continue;
                ans += sz[v]-1;
                if (!ok[v]) ans += 2;
            }
        }
        cout << ans << '\n';
    }
}
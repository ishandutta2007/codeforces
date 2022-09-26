#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    const int64_t INF = 1e18;
    while (T--) {
        int N, M, K; cin >> N >> M >> K;
        vector<array<int, 3>> edges(M);
        for (int i = 0; i < M; ++i) {
            cin >> edges[i][1] >> edges[i][2] >> edges[i][0];
            --edges[i][1];
            --edges[i][2];
        }
        sort(edges.begin(), edges.end());
        int cut = 0; while (cut < M && edges[cut][0] <= K) cut++;
        vector<int> par(N); iota(par.begin(), par.end(), 0);
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
                return true;
            }
            return false;
        };
        int tot = 0; for (int i = 0; i < cut; ++i) tot += merge(edges[i][1], edges[i][2]);
        int64_t ans;
        if (tot == N-1) {
            ans = K - edges[cut-1][0];
            if (cut < M) ans = min<int64_t>(ans, edges[cut][0] - K);
        } else {
            ans = 0;
            for (int i = cut; i < M; ++i) {
                if (merge(edges[i][1], edges[i][2])) {
                    tot += 1;
                    ans += edges[i][0] - K;
                }
            }
            assert(tot == N-1);
        }
        cout << ans << '\n';
    }
}
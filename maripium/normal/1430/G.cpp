#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    vector<int64_t> sum(1 << N);
    vector<int> adj(1 << N);
    for (int i = 0; i < M; ++i) {
        int x, y, w; cin >> x >> y >> w; --x, --y;
        sum[1 << x] += w;
        sum[1 << y] -= w;
        adj[1 << x] |= (1 << y);
    }
    for (int i = 0; i < N; ++i) {
        for (int m = 0; m < 1 << N; ++m) {
            if (m & (1 << i)) {
                sum[m] += sum[m ^ (1 << i)];
                adj[m] |= adj[m ^ (1 << i)];
            }
        }
    }
    vector<int64_t> dp(1 << N, int64_t(1) << 60);
    vector<int> opt(1 << N);
    dp[(1 << N) - 1] = 0;
    for (int m = (1 << N) - 1; m > 0; --m) {
        for (int sm = m; sm > 0; sm = (sm-1) & m) {
            int nm = m ^ sm;
            if (adj[sm] & m) continue;
            if (dp[nm] > dp[m] + sum[m]) {
                dp[nm] = dp[m] + sum[m];
                opt[nm] = m;
            }
        }
    }
    cerr << dp[0] << '\n';
    int m = 0;
    vector<int> layers;
    while (m +1 < (1 << N)) layers.emplace_back(m = opt[m]);
    vector<int> cnt(N);
    for (int m : layers) for (int i = 0; i < N; ++i) if (m & (1 << i)) cnt[i] ++;
    for (int v : cnt) cout << v << ' ';
    return 0;
}
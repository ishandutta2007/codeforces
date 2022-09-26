#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int K; cin >> K;
    vector<int64_t> F(6); for (auto &f : F) cin >> f;
    const int64_t INF = 1e18;
    vector<int64_t> dp = {0};
    for (int d = 5; d >= 0; --d) {
        vector<int64_t> ndp(dp.size() * 10, -INF);
        vector<deque<pair<int64_t, int>>> st(3);
        for (int N = 0; N < int(ndp.size()); ++N) {
            if (N % 10 == 0) {
                int64_t cur = dp[N/10] - (N/3) * F[d];
                int z = N%3;
                while (!st[z].empty() && cur >= st[z].back().first) st[z].pop_back();
                st[z].push_back({cur, N});
            }
            for (int z = 0; z < 3; ++z) {
                while (!st[z].empty() && N - st[z].front().second > 9 * (K-1)) st[z].pop_front();
                if (!st[z].empty()) {
                    int opt = st[z].front().second;
                    int64_t cur = st[z].front().first + (opt / 3) * F[d];
                    int diff = N - opt;
                    cur += (diff / 3) * F[d];
                    ndp[N] = max(ndp[N], cur);
                }
            }
            for (int v = 1; v <= 9; ++v) {
                int diff = 9*(K-1) + v;
                if (diff <= N && (N-diff) % 10 == 0) {
                    int64_t cur = dp[(N-diff) / 10];
                    cur += (K-1) * 3 * F[d];
                    if (v % 3 == 0) cur += (v/3) * F[d];
                    ndp[N] = max(ndp[N], cur);
                }
            }
        }
        dp.swap(ndp);
    }
    int Q; cin >> Q;
    while (Q--) {
        int N; cin >> N;
        cout << dp[N] << '\n';
    }
}
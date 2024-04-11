#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    const int64_t INF = 1e18;
    vector<vector<int64_t>> A(N);
    for (int i = 0; i < N; ++i) {
        int M; cin >> M;
        A[i] = {0};
        for (int j = 0; j < M; ++j) {
            int64_t x; cin >> x;
            A[i].emplace_back(A[i].back()+x);
        }
    }
    int64_t ans = 0;
    auto solve = [&](auto self, int l, int r, vector<int64_t> &dp) -> void {
        if (l == r) {
            for (int z = 0; z <= K; ++z) {
                if (A[l].size() > K-z) {
                    ans = max(ans, A[l][K-z]+dp[z]);
                }
            }
            return;
        }
        int md = (l+r)>>1;
        vector<int64_t> dp2 = dp;
        for (int i = l; i <= md; ++i) {
            int M = int(A[i].size())-1;
            for (int z=K; z >= M; --z) dp[z] = max(dp[z], dp[z-M]+A[i].back());
        }
        for (int i = md+1; i <= r; ++i) {
            int M = int(A[i].size())-1;
            for (int z = K; z >= M; --z) dp2[z] = max(dp2[z], dp2[z-M]+A[i].back());
        }
        self(self, l, md, dp2);
        self(self, md+1, r, dp);
    };
    vector<int64_t> dp(K+1, -INF); dp[0] = 0;
    solve(solve, 0, N-1, dp);
    cout << ans << '\n';
    return 0;
}
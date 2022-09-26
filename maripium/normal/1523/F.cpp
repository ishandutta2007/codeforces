#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    const int INF = 1.01e9;
    int N, M; cin >> N >> M;
    vector<int> XA(N), YA(N);
    for (int i = 0; i < N; ++i) cin >> XA[i] >> YA[i];
    vector<int> XB(M), YB(M), T(M);
    for (int i = 0; i < M; ++i) cin >> XB[i] >> YB[i] >> T[i];
    {
        vector<tuple<int, int, int>> qs;
        for (int i = 0; i < M; ++i) {
            qs.emplace_back(T[i], XB[i], YB[i]);
        }
        sort(qs.begin(), qs.end());
        for (int i = 0; i < M; ++i) {
            tie(T[i], XB[i], YB[i]) = qs[i];
        }
    }

    int ans = 0;

    vector<vector<int>> dp(1 << N, vector<int>(M + 1, INF));
    for (int i = 0; i < N; ++i) {
        dp[1 << i][0] = 0;
    }
    for (int msk = 0; msk < (1 << N); ++msk) {
        vector<int> dist(M, INF);
        for (int i = 0; i < N; ++i) if (msk >> i & 1) {
            for (int j = 0; j < M; ++j) {
                dist[j] = min(dist[j], abs(XA[i] - XB[j]) + abs(YA[i] - YB[j]));
            }
        }
        vector<int> dp1(M, -INF);
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j < M; ++j) if (dp[msk][i] + dist[j] <= T[j]) {
                dp1[j] = max(dp1[j], i + 1);
            }
        }
        if (msk == 0) fill(dp1.begin(), dp1.end(), 1);
        vector<int> dist1(N, INF);
        for (int i = 0; i < N; ++i) if (msk >> i & 1) {
            for (int j = 0; j < N; ++j) {
                dist1[j] = min(dist1[j], abs(XA[i] - XA[j]) + abs(YA[i] - YA[j]));
            }
        }
        for (int i = 0; i <= M; ++i) {
            for (int j = 0; j < N; ++j) if (!(msk >> j & 1)) {
                dp[msk | (1 << j)][i] = min(dp[msk | (1 << j)][i], dp[msk][i] + dist1[j]);
            }
        }
        for (int i = 0; i < M; ++i) if (dp1[i] > 0) {
            ans = max(ans, dp1[i]);
            for (int j = i + 1; j < M; ++j) if (T[i] + min(dist[j], abs(XB[i] - XB[j]) + abs(YB[i] - YB[j])) <= T[j]) {
                dp1[j] = max(dp1[j], dp1[i] + 1);
            }
            for (int j = 0; j < N; ++j) if (!(msk >> j & 1)) {
                dp[msk | (1 << j)][dp1[i]] = min(dp[msk | (1 << j)][dp1[i]], T[i] + min(dist1[j], abs(XB[i] - XA[j]) + abs(YB[i] - YA[j])));
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
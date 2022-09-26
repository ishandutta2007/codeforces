#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M, K; cin >> N >> M >> K;

    vector<vector<int>> A(N, vector<int>(M-1));
    vector<vector<int>> B(N-1, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j+1 < M; ++j) {
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> B[i][j];
        }
    }
    if (K & 1) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) cout << -1 << " \n"[j == M-1];
        }
        return 0;
    }

    K /= 2;

    const int INF = 1e9;
    vector<vector<int>> dp(N, vector<int>(M));

    while (K--) {
        vector<vector<int>> ndp(N, vector<int>(M, INF));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M-1; ++j) {
                ndp[i][j] = min(ndp[i][j], dp[i][j+1] + A[i][j]);
                ndp[i][j+1] = min(ndp[i][j+1], dp[i][j] + A[i][j]);
            }
        }

        for (int i = 0; i < N-1; ++i) {
            for (int j = 0; j < M; ++j) {
                ndp[i][j] = min(ndp[i][j], dp[i+1][j] + B[i][j]);
                ndp[i+1][j] = min(ndp[i+1][j], dp[i][j] + B[i][j]);
            }
        }
        dp.swap(ndp);
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << 2*dp[i][j] << " \n"[j==M-1];
        }
    }
}
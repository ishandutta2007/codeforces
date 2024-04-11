#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int R, N; cin >> R >> N;
    vector<int> X(N+1), Y(N+1), T(N+1);
    vector<int> dp(N+1);
    vector<int> pref(N+1);
    pref[0] = 0;
    X[0] = Y[0] = T[0] = 0;
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> X[i] >> Y[i];
        --X[i], --Y[i];
        int mj = max(0, i - R - R + 2);
        dp[i] = -1e9;
        for (int j = mj; j < i; ++j) {
            if (abs(X[i] - X[j]) + abs(Y[i] - Y[j]) <= T[i] - T[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        if (mj > 0) dp[i] = max(dp[i], pref[mj-1]+1);
        pref[i] = max(pref[i-1], dp[i]);
    }
    cout << pref[N] << '\n';
    return 0;
}
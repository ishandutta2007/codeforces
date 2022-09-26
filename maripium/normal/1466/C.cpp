#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    const int INF = 1e9;
    while (T--) {
        string S; cin >> S;
        int N = int(S.size());
        array<array<int, 2>, 2> dp;
        dp[0][0] = 0;
        dp[0][1] = dp[1][0] = dp[1][1] = INF;
        for (int i = 0; i < N; ++i) {
            array<array<int, 2>, 2> ndp;
            ndp[0][0] = ndp[0][1] = ndp[1][1] = ndp[1][0] = INF;
            for (int prv = 0; prv < 2; ++prv) {
                for (int cur = 0; cur < 2; ++cur) {
                    for (int nxt = 0; nxt < 2; ++nxt) {
                        if (i >= 2 && S[i] == S[i-2] && !prv && !nxt) continue;
                        if (i >= 1 && S[i] == S[i-1] && !cur && !nxt) continue;
                        ndp[cur][nxt] = min(ndp[cur][nxt], dp[prv][cur] + nxt);
                    }
                }
            }
            dp = move(ndp);
        }
        cout << min({dp[0][0], dp[0][1], dp[1][0], dp[1][1]}) << '\n';
    }
    return 0;
}
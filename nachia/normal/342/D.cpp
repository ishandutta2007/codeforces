#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

struct Problem {
    UL N;
    bool T[10000][3] = {};
    static const ULL M = 1000000007;

    ULL Solve2() {
        ULL dp[8] = {}; dp[0] = 1;
        rep(x, N) {
            dp[3] += dp[0]; dp[7] += dp[4];
            dp[6] += dp[0]; dp[7] += dp[1];
            if (T[x][0]) { dp[1] = dp[3] = dp[5] = dp[7] = 0; }
            if (T[x][1]) { dp[2] = dp[3] = dp[6] = dp[7] = 0; }
            if (T[x][2]) { dp[4] = dp[5] = dp[6] = dp[7] = 0; }
            rep(i, 8) dp[i] %= M;
            UL mask = (T[x][0] ? 0 : 1) | (T[x][1] ? 0 : 2) | (T[x][2] ? 0 : 4);
            ULL tmp[8]; rep(i, 8) tmp[i] = dp[i ^ mask];
            rep(i, 8) dp[i] = tmp[i];
        }
        return dp[0];
    }

    void Solve() {
        cin >> N;
        pair<UL, UL> P;
        rep(y, 3) {
            string S; cin >> S;
            rep(x, N) {
                if (S[x] == 'X') T[x][y] = true;
                else if (S[x] == 'O') { T[x][y] = true; P = { x, y }; }
            }
        }
        ULL tmp[16] = {};
        rep(i, 16) {
            if (i & 1) if (P.second != 0) continue;
            if (i & 2) if (P.second != 2) continue;
            if (i & 4) if (P.first < 2) continue;
            if (i & 8) if (P.first + 2 >= N) continue;

            if (i & 1) if (T[P.first][1] | T[P.first][2]) continue;
            if (i & 2) if (T[P.first][1] | T[P.first][0]) continue;
            if (i & 4) if (T[P.first - 1][P.second] | T[P.first - 2][P.second]) continue;
            if (i & 8) if (T[P.first + 1][P.second] | T[P.first + 2][P.second]) continue;

            if (i & 1) T[P.first][1] = T[P.first][2] = true;
            if (i & 2) T[P.first][1] = T[P.first][0] = true;
            if (i & 4) T[P.first - 1][P.second] = T[P.first - 2][P.second] = true;
            if (i & 8) T[P.first + 1][P.second] = T[P.first + 2][P.second] = true;
            tmp[i] = Solve2();
            if (i & 1) T[P.first][1] = T[P.first][2] = false;
            if (i & 2) T[P.first][1] = T[P.first][0] = false;
            if (i & 4) T[P.first - 1][P.second] = T[P.first - 2][P.second] = false;
            if (i & 8) T[P.first + 1][P.second] = T[P.first + 2][P.second] = false;
        }
        ULL ans = tmp[1] + tmp[2] + tmp[4] + tmp[8];
        ans += 6 * M - (tmp[3] + tmp[5] + tmp[6] + tmp[9] + tmp[10] + tmp[12]);
        ans += tmp[7] + tmp[11] + tmp[13] + tmp[14];
        ans += M - tmp[15];
        ans %= M;
        cout << ans << endl;
    }
};

int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using UL = unsigned long;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(int i = 0; i < (n); i++)

const ULL M = 998244353;

struct Problem {

    ULL dp[3001][3001] = {};

    void Solve() {
        string S, T; cin >> S >> T;
        UL N = S.size();
        UL L = T.size();
        while (T.size() != N) T.push_back('?');
        rep(i, N + 1) dp[i][i] = 1;
        for (UL l = 1; l <= N; l++) {
            for (UL s = 0; s + l <= N; s++) {
                if (T[s] == '?' || T[s] == S[l - 1])
                    dp[s][s + l] += dp[s + 1][s + l];
                if (T[s + l - 1] == '?' || T[s + l - 1] == S[l - 1])
                    dp[s][s + l] += dp[s][s + l - 1];
                dp[s][s + l] %= M;
            }
        }
        ULL ans = 0;
        for (UL r = L; r <= N; r++) ans += dp[0][r];
        ans %= M;
        cout << ans << endl;
    }
};

int main() {
    cin.tie(0);
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
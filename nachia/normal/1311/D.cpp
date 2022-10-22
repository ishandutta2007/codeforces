#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    void Solve() {
        UL tc; scanf("%d", &tc);
        while (tc--) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            int dp[20001][3][2];
            rep(i, 20001) rep(j, 3) dp[i][j][0] = 100000;
            for (int i = 1; i <= 20000; i++) {
                dp[i][0][0] = abs(a - i);
                for (int j = i; j <= 20000; j += i) {
                    if (dp[j][1][0] > dp[i][0][0]) {
                        dp[j][1][0] = dp[i][0][0];
                        dp[j][1][1] = i;
                    }
                }
            }
            for (int i = 1; i <= 20000; i++) {
                dp[i][1][0] += abs(b - i);
                for (int j = i; j <= 20000; j += i) {
                    if (dp[j][2][0] > dp[i][1][0]) {
                        dp[j][2][0] = dp[i][1][0];
                        dp[j][2][1] = i;
                    }
                }
            }
            int p = 0;
            for (int i = 1; i <= 20000; i++) {
                dp[i][2][0] += abs(c - i);
                if (dp[p][2][0] > dp[i][2][0]) p = i;
            }
            printf("%d\n", dp[p][2][0]);
            int aa, bb, cc;
            cc = p; bb = dp[cc][2][1]; aa = dp[bb][1][1];
            printf("%d %d %d\n", aa, bb, cc);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
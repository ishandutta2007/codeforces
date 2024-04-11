#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
    vector<UL> prime_factor[100001];
    UL dp[100000] = {};
    UL dp2[100001] = {};

    void Solve() {
        UL N; scanf("%d", &N);
        for (UL i = 2; i <= 100000; i++) {
            if (!prime_factor[i].empty()) continue;
            for (UL j = i; j <= 100000; j += i) prime_factor[j].push_back(i);
        }
        rep(i, N) {
            UL A; scanf("%d", &A);
            for (UL f : prime_factor[A])
                dp[i] = max(dp[i], dp2[f]);
            dp[i]++;
            for (UL f : prime_factor[A])
                dp2[f] = max(dp[i], dp2[f]);
        }
        UL ans = 0; rep(i, N) ans = max(ans, dp[i]);
        cout << ans << endl;
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    //cout << fixed << setprecision(10);
    p->Solve();
    return 0;
}
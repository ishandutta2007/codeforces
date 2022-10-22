#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    LL A[200000];

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N; scanf("%d", &N);
            rep(i, N) scanf("%lld", A + i);
            pair<UL, LL> S[2] = { {0,0}, {0,0} };
            rep(i, N) {
                if (A[i] < 0) {
                    pair<UL, LL> tmp = { S[0].first + 1, S[0].second + A[i] };
                    S[1] = max(S[1], tmp);
                }
                else {
                    pair<UL, LL> tmp = { S[1].first + 1, S[1].second + A[i] };
                    S[0] = max(S[0], tmp);
                }
            }
            auto ans = max(S[0], S[1]);
            printf("%lld\n", ans.second);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
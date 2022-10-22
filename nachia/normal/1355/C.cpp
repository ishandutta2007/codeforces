#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL A[4]; rep(i, 4) scanf("%d", A + i);
        ULL ans = 0;
        for (UL z = A[2]; z <= A[3]; z++) {
            if (A[1] + A[2] < z) continue;
            if (A[0] + A[1] > z) {
                ans += (ULL)(A[1] - A[0] + 1) * (ULL)(A[2] - A[1] + 1);
                continue;
            }
            ULL d = A[1] + A[2] - z;
            ULL tmp = d * (d + 1) / 2;
            if (A[2] - A[1] < d) {
                ULL dd = d - (A[2] - A[1] + 1);
                tmp -= dd * (dd + 1) / 2;
            }
            if (A[1] - A[0] < d) {
                ULL dd = d - (A[1] - A[0] + 1);
                tmp -= dd * (dd + 1) / 2;
            }
            ans += tmp;
        }
        printf("%lld\n", ans);
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
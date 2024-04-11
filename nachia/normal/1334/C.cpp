#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    LL A[300001][2];

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N; scanf("%d", &N);
            rep(i, N) scanf("%lld%lld", &A[i][0], &A[i][1]);
            A[N][0] = A[0][0];
            LL S = 0;
            LL m = (LL)1e12;
            rep(i, N) {
                A[i][1] = min(A[i][1], A[i + 1][0]);
                S += (A[i][0] - A[i][1]);
                m = min(m, A[i][1]);
            }
            printf("%lld\n", S + m);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem{

    LL A[100000];

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            LL N, X; scanf("%lld%lld", &N, &X);
            rep(i, N) scanf("%lld", A + i);
            sort(A, A + N); reverse(A, A + N);
            UL ans = 0;
            LL S = 0;
            rep(i, N) {
                S += A[i];
                if (X * (i + 1) <= S) ans++;
            }
            printf("%d\n", ans);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
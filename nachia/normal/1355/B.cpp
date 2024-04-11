#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    UL A[200000];

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N; scanf("%d", &N);
            rep(i, N) scanf("%d", A + i);
            sort(A, A + N);
            UL ans = 0;
            UL p = 0;
            rep(i, N) {
                if (A[i] <= i - p + 1) { ans++; p = i + 1; }
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
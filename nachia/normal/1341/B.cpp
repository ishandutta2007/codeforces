#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    LL A[200000];
    UL P[200001];

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL K, N; scanf("%d%d", &N, &K);
            rep(i, N) scanf("%lld", A + i);
            for (int i = 1; i < N - 1; i++) {
                if (A[i - 1] < A[i] && A[i] > A[i + 1]) P[i] = 1;
                else P[i] = 0;
            }
            P[0] = P[N - 1] = 0;
            rep(i, N - 1) P[i + 1] += P[i];
            UL ans = 1;
            UL s = 0;
            for (UL i = 1; i <= N - K + 1; i++) {
                UL tmp = P[i + K - 3] - P[i - 1];
                if (s < tmp) { ans = i; s = tmp; }
            }
            printf("%d %d\n", s + 1, ans);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
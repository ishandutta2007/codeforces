#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL T; scanf("%d", &T);
        while (T--) {
            UL N, A[4];
            scanf("%d", &N);
            rep(i, 4) scanf("%d", A + i);
            A[0] *= N; A[1] *= N;
            A[1] += A[0];
            A[0] = A[0] + A[0] - A[1];
            A[3] += A[2];
            A[2] = A[2] + A[2] - A[3];
            if (A[0] <= A[3] && A[1] >= A[2])
                printf("Yes\n");
            else printf("No\n");
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

    void Solve() {
        UL N, S; scanf("%d%d", &N, &S);
        if (N * 2 > S) { printf("NO\n"); }
        else if (N * 2 == S) {
            printf("YES\n");
            rep(i, N - 1) printf("2 ");
            printf("2\n1\n");
        }
        else {
            printf("YES\n");
            rep(i, N - 1) printf("1 ");
            printf("%d\n%d\n", S - N + 1, N);
        }
    }
};
int main() {
    unique_ptr<Problem> p(new Problem());
    p->Solve();
    return 0;
}
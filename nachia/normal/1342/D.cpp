#include <stdio.h>
#include <memory>
#include <algorithm>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL M[200000];
    UL Z[200000];
    UL N, K; scanf("%d%d", &N, &K);
    rep(i, N)scanf("%d", M + i);
    rep(i, K)scanf("%d", Z + i);
    sort(M, M + N);
    reverse(M, M + N);
    UL MC = 0;
    rep(i, N) MC = max(MC, i / Z[M[i] - 1] + 1);
    printf("%d\n", MC);
    rep(i, MC) {
        printf("%d", (N - i - 1) / MC + 1);
        for (UL j = i; j < N; j += MC) {
            printf(" %d", M[j]);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
using UL = unsigned int;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL T; scanf("%d", &T);
    while (T--) {
        UL N, K; scanf("%d%d", &N, &K);
        UL D[100]; rep(i, N) D[i] = N;
        rep(i, N) { UL a; scanf("%d", &a); D[a - 1] = a - 1; }
        sort(D, D + N);
        rep(i, K) if (D[i] == N) D[i] = 0;
        if (K < N) if (D[K] != N) { printf("-1\n"); continue; }
        printf("%d\n", N * K);
        rep(i, N) {
            rep(j, K) {
                if (i || j) printf(" ");
                printf("%d", D[j] + 1);
            }
        }
        printf("\n");
    }
    return 0;
}
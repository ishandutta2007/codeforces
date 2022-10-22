#include <stdio.h>
using namespace std;
using UL = unsigned int;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL T; scanf("%d", &T);
    while (T--) {
        UL N; scanf("%d", &N);
        UL A[30]; rep(i, N) A[i] = 1u << (i + 1);
        UL L = 0; rep(i, N / 2 - 1) L += A[i];
        for (UL i = N / 2 - 1; i < N - 1; i++) L -= A[i];
        L += A[N - 1];
        printf("%d\n", L);
    }
    return 0;
}
#include <iostream>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

int main() {
    UL t; scanf("%d", &t);
    ULL S[40001];
    while (t--) {
        ULL a, b; scanf("%lld%lld", &a, &b);
        ULL N = a * b;
        S[0] = 0;
        rep(x, N) S[x + 1] = S[x] + ((x % a % b != x % b % a) ? 1 : 0);
        UL Q; scanf("%d", &Q);
        while (Q--) {
            ULL L, R; scanf("%lld%lld", &L, &R);
            ULL ans = 0; ans += S[N] * (R / N - L / N);
            ans += S[R % N + 1];
            ans -= S[L % N];
            printf("%lld", ans);
            if (Q) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
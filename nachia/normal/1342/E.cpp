#include <stdio.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

const ULL M = 998244353;

ULL F[200001];
ULL I[200001];
ULL iF[200001];
ULL D[200001];

ULL powm(ULL a, ULL i) {
    return i ? (powm(a * a % M, i >> 1) * ((i & 1) ? a : 1) % M) : 1;
}
ULL C(ULL n, ULL r) { return F[n] * iF[n - r] % M * iF[r] % M; }

int main() {
    ULL N, K; scanf("%lld%lld", &N, &K);
    if (N - 1 < K) { printf("0\n"); return 0; }
    F[0] = 1; for (UL i = 1; i <= N; i++) F[i] = F[i - 1] * i % M;
    I[1] = 1; for (UL i = 2; i <= N; i++) I[i] = M - M / i * I[M % i] % M;
    iF[0] = 1; for (UL i = 1; i <= N; i++) iF[i] = iF[i - 1] * I[i] % M;
    if (K == 0) { printf("%lld\n", F[N]); return 0; }
    ULL ans = 2;
    ans = ans * C(N, N - K) % M;
    D[0] = 0;
    for (UL i = 1; i <= N - K; i++)
        D[i] = (powm(i, N) * C(N - K, i) % M + (M - D[i - 1])) % M;
    ans = ans * D[N - K] % M;
    printf("%lld", ans);
    return 0;
}
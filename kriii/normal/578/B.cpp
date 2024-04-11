#include <stdio.h>

int N, K, X;
long long A[200002], L[200002], R[200002];

int main()
{
    scanf("%d %d %d", &N, &K, &X);
    for (int i = 1; i <= N; i++){
        scanf("%lld", &A[i]);
        L[i] = L[i - 1] | A[i];
    }
    for (int i = N; i >= 1; i--){
        R[i] = R[i + 1] | A[i];
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++){
        long long u = A[i];
        for (int j = 0; j<K; j++) u *= X;
        long long now = L[i - 1] | u | R[i + 1];
        if (ans < now)
            ans = now;
    }
    printf("%lld\n", ans);

    return 0;
}
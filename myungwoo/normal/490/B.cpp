#include <stdio.h>

#define MAXN 200005

int N, A[MAXN], B[MAXN], C[MAXN], P[1000006];
bool V[1000006];

int main()
{
    int i;
    scanf("%d", &N);
    for (i=1;i<=N;i++){
        scanf("%d%d", A+i, B+i), P[A[i]] = B[i];
        V[B[i]] = 1;
    }
    for (i=1;i<=N;i++) if (!V[A[i]]) C[1] = A[i];
    C[2] = P[0];
    for (i=3;i<=N;i++) C[i] = P[C[i-2]];
    for (i=1;i<=N;i++) printf("%d ", C[i]); puts("");
}
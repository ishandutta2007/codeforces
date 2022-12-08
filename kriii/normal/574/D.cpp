#include <stdio.h>

int N,A[100010],P[100010],Q[100010];

int main()
{
    int N; scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&A[i]);
    for (int i=1;i<=N;i++){
        P[i] = P[i-1] + 1;
        if (P[i] > A[i]) P[i] = A[i];
    }
    Q[N+1] = 0;
    for (int i=N;i>=1;i--){
        Q[i] = Q[i+1] + 1;
        if (Q[i] > A[i]) Q[i] = A[i];
    }
    int ans = 0;
    for (int i=1;i<=N;i++){
        int x = P[i] < Q[i] ? P[i] : Q[i];
        if (ans < x) ans = x;
    }
    printf ("%d\n",ans);

    return 0;
}
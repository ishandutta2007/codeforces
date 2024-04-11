#include <stdio.h>

int N, X, A[99], B[99];

int main()
{
        int i, j;
        scanf("%d%d", &N, &X);
        for (i=1;i<=N;i++) scanf("%d%d", A+i, B+i);
        int t = 1, ans = 0;
        for (i=1;i<=N;i++){
                int c = (A[i]-t)/X;
                t += X*c;
                ans += A[i]-t;
                t = A[i];
                ans += B[i]+1-t;
                t = B[i]+1;
        }
        printf("%d\n", ans);
}
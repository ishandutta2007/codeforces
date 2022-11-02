#include <stdio.h>

typedef long long lld;

int sx, sy, ex, ey;
int N, A[333], B[333], C[333];
lld D[333], E[333];

int main()
{
        int i, j, k;
        scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &N);
        for (i=1;i<=N;i++) scanf("%d%d%d", A+i, B+i, C+i);
        for (i=1;i<=N;i++){
                D[i] = (lld)A[i]*sx + (lld)B[i]*sy + C[i];
                E[i] = (lld)A[i]*ex + (lld)B[i]*ey + C[i];
                if (D[i] > 0) D[i] = 1;
                else D[i] = -1;
                if (E[i] > 0) E[i] = 1;
                else E[i] = -1;
        }
        int ans = 0;
        for (i=1;i<=N;i++) if (D[i]*E[i] < 0) ans++;
        printf("%d\n", ans);
}
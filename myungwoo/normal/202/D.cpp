#include <stdio.h>
#include <limits.h>

typedef long long lld;

int N,M,R[1001][1001],P,Q;
lld SX,SY,W,ans=LLONG_MAX;

int main()
{
    int i,j,k,l,x,y;
    lld v;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++){
        scanf("%d",R[i]+j);
        SX += R[i][j]*j;
        SY += R[i][j]*i;
        W += R[i][j];
    }
    if (!W){ puts("0\n0 0"); return 0; }
    x = SX/W, y = SY/W;
    for (i=y-1;i<y+2;i++) if (i >= 0 && i <= N){
        for (j=x-1;j<x+2;j++) if (j >= 0 && j <= M){
            v = 0;
            for (k=1;k<=N;k++) for (l=1;l<=M;l++){
                v += (lld(i*4-(k*4-2))*((i*4)-(k*4-2))+lld(j*4-(l*4-2))*(j*4-(l*4-2)))*R[k][l];
            }
            if (ans > v)
                ans = v, P = i, Q = j;
        }
    }
    printf("%I64d\n%d %d\n",ans,P,Q);
}
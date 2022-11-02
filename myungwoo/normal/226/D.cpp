#include <stdio.h>

int N,M,K;
int A[101][101],rsum[101],csum[101];
int rcnt[101],ccnt[101];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) scanf("%d",A[i]+j);
    for (i=1;i<=N;i++) for (j=1;j<=M;j++) rsum[i] += A[i][j];
    for (i=1;i<=M;i++) for (j=1;j<=N;j++) csum[i] += A[j][i];
    for (i=1;i<=N;i++) if (rsum[i] < 0) K++;
    for (i=1;i<=M;i++) if (csum[i] < 0) K++;
    while (K){
        for (i=1;i<=N;i++) if (rsum[i] < 0){
            rcnt[i]++;
            K--;
            for (j=1;j<=M;j++){
                if (csum[j] < 0) K--;
                csum[j] += ((rcnt[i]+ccnt[j])&1?-A[i][j]:A[i][j])*2;
                if (csum[j] < 0) K++;
            }
            rsum[i] *= -1;
        }
        for (i=1;i<=M;i++) if (csum[i] < 0){
            ccnt[i]++;
            K--;
            for (j=1;j<=N;j++){
                if (rsum[j] < 0) K--;
                rsum[j] += ((rcnt[j]+ccnt[i])&1?-A[j][i]:A[j][i])*2;
                if (rsum[j] < 0) K++;
            }
            csum[i] *= -1;
        }
    }
    k = 0;
    for (i=1;i<=N;i++) if (rcnt[i]&1) k++;
    printf("%d ",k);
    for (i=1;i<=N;i++) if (rcnt[i]&1) printf("%d ",i); puts("");
    k = 0;
    for (i=1;i<=M;i++) if (ccnt[i]&1) k++;
    printf("%d ",k);
    for (i=1;i<=M;i++) if (ccnt[i]&1) printf("%d ",i);
}
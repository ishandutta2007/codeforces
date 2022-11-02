#include <stdio.h>

typedef long long lld;

int N,A[51];
lld P[5],C[5];

int main()
{
    int i,j;
    lld c=0;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=0;i<5;i++) scanf("%d",P+i);
    for (i=1;i<=N;i++){
        c += A[i];
        for (j=5;j--;) if (c >= P[j]){
            C[j] += c/P[j];
            c %= P[j];
        }
    }
    for (i=0;i<5;i++) printf("%I64d ",C[i]);
    printf("\n%I64d",c);
}
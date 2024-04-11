#include <stdio.h>

int N,M,W[101],ans=1e9;
bool w[101][101];

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++) scanf("%d",W+i);
    for (i=1;i<=M;i++) scanf("%d%d",&j,&k), w[j][k] = w[k][j] = 1;
    for (i=1;i<N;i++) for (j=i+1;j<N;j++) for (k=j+1;k<=N;k++) if (w[i][j] && w[j][i] && w[i][k] && w[k][i] && w[j][k] && w[k][j]){
        if (ans > W[i]+W[j]+W[k]) ans = W[i]+W[j]+W[k];
    }
    printf("%d",ans==1e9?-1:ans);
}
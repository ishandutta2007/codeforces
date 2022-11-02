#include <stdio.h>

#define MAXN 100005

int N,M,K,A[MAXN],C[MAXN],num[MAXN],S[450][MAXN],ans;

int main()
{
    int i,j,k;
    scanf("%d%d",&N,&M);
    for (i=1;i<=N;i++){
        scanf("%d",A+i);
        if (A[i] > N) continue;
        if (++C[A[i]] == A[i]) num[++K] = A[i];
    }
    for (i=1;i<=K;i++){
        for (j=1;j<=N;j++) if (A[j] == num[i]) S[i][j] = 1;
        for (j=1;j<=N;j++) S[i][j] += S[i][j-1];
    }
    while (M--){
        scanf("%d%d",&j,&k); ans = 0;
        for (i=1;i<=K;i++) if (S[i][k]-S[i][j-1] == num[i]) ans++;
        printf("%d\n",ans);
    }
}
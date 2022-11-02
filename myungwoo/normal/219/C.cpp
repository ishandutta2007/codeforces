#include <stdio.h>

#define MAXN 500005

int N,K,D[MAXN][26],P[MAXN][26],ans=1e9;
char A[MAXN];

int main()
{
    int i,j,k;
    scanf("%d%d%s",&N,&K,A+1);
    for (i=1;i<=N;i++){
        for (j=0;j<K;j++){
            D[i][j] = 1e9;
            for (k=0;k<K;k++) if (j != k){
                if (D[i][j] > D[i-1][k]+(A[i]-'A'!=j))
                    D[i][j] = D[i-1][k]+(A[i]-'A'!=j),
                    P[i][j] = k;
            }
        }
    }
    for (i=0;i<K;i++)
        if (ans > D[N][i])
            ans = D[N][i], k = i;
    for (i=N;i;k=P[i][k],i--) A[i] = k+'A';
    printf("%d\n%s",ans,A+1);
}
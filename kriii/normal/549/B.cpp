#include <stdio.h>

int N,P[101],C[101];
char S[101][101];
int U;

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%s",S[i]);
    for (int i=0;i<N;i++) scanf ("%d",&P[i]);
    for (int k=0;k<N;k++){
        for (int i=0;i<N;i++) if (P[i] == 0 && C[i] == 0){
            for (int j=0;j<N;j++) if (S[i][j] == '1') P[j]--;
            C[i] = 1; U++;
        }
    }

    printf ("%d\n",U);
    for (int j=0;j<N;j++) if (C[j]) printf ("%d ",j+1); puts("");

    return 0;
}
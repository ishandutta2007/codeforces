#include <stdio.h>

int N,M; long long C[101],V[101];
char S[101][101];

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=0;i<N;i++) scanf ("%s",S[i]);

    int ans = 0;
    for (int i=N-1;i>=0;i--){
        for (int j=0;j<M;j++){
            V[j] = C[j];
            if (j) V[j] += V[j-1];
        }
        for (int j=M-1;j>=0;j--){
            int add;
            if (S[i][j] == 'W') add = 1 - V[j];
            else add = -1 - V[j];
            if (add == 0) continue;
            ans++;
            C[0] += add;
            C[j+1] -= add;
            for (int k=0;k<=j;k++) V[k] += add;
        }
    }

    printf ("%d\n",ans);

    return 0;
}
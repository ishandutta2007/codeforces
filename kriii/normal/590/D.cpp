#include <stdio.h>

const int non = 3e8;
int prv[150][20000],tmp[150][20000],nxt[150][20000];
int N,K,S,A[150];

int main()
{
    scanf ("%d %d %d",&N,&K,&S);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++) prv[i][j] = non;
        prv[i][i] = A[i];
    }

    int max = N;
    for (int k=1;k<K;k++){
        int nmax = max + N, rmax = 0;
        for (int i=k-1;i<N;i++) for (int j=0;j<nmax;j++) nxt[i][j] = tmp[i][j] = non;
        for (int i=k-1;i<N;i++) for (int j=0;j<max;j++){
            int u = j + N - k;
            if (tmp[i][u] > prv[i][j])
                tmp[i][u] = prv[i][j];
            if (i > k-1){
                if (tmp[i][u] > tmp[i-1][u]){
                    tmp[i][u] = tmp[i-1][u];
                }
            }
        }
        for (int i=k;i<N;i++) for (int j=0;j<nmax;j++) if (tmp[i-1][j] != non){
            if (nxt[i][j+i-N] > tmp[i-1][j] + A[i])
                nxt[i][j+i-N] = tmp[i-1][j] + A[i];
            if (rmax < j + i - N)
                rmax = j + i - N;
        }
        max = rmax + 1;
        for (int i=k;i<N;i++) for (int j=0;j<max;j++) prv[i][j] = nxt[i][j];
    }

    int ans = non;
    if (S >= 20000) S = 19999;
    if (S >= max) S = max - 1;
    for (int i=K-1;i<N;i++) for (int j=0;j<=S;j++){
        if (ans > prv[i][j])
            ans = prv[i][j];
    }
    printf ("%d\n",ans);

    return 0;
}
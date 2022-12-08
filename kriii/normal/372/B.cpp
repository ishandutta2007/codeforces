#include <stdio.h>

int N,M,Q; char B[44][44];
int A[41][41][41][41];
int S[41][41];

int main()
{
    int i,j,k,l,p,c,v;

    scanf ("%d %d %d",&N,&M,&Q);
    for (i=0;i<N;i++){
        scanf ("%s",B[i+1]+1);
    }

    for (i=1;i<=N;i++) for (j=1;j<=M;j++) S[i][j] = B[i][j] - '0' + S[i-1][j] + S[i][j-1] - S[i-1][j-1];

    for (p=1;p<=N;p++) for (i=1,k=p;k<=N;i++,k++){
        for (j=1;j<=M;j++){
            c = v = 0;
            for (l=j;l<=M;l++){
                if (S[k][l] - S[i-1][l] - S[k][l-1] + S[i-1][l-1] == 0) v++;
                else v = 0;
                c += v;
                if (p == 1) A[i][j][k][l] = c;
                else{
                    A[i][j][k][l] = A[i+1][j][k][l] + A[i][j][k-1][l] - A[i+1][j][k-1][l] + c;
                }
            }
        }
    }

    while (Q--){
        scanf ("%d %d %d %d",&i,&j,&k,&l);
        printf ("%d\n",A[i][j][k][l]);
    }

    return 0;
}
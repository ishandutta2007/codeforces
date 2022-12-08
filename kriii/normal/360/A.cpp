#include <stdio.h>

int N,M,V[5050],L[5050],O[5050],X[5050],Y[5050],D[5050];

int main()
{
    int i,j,o,x,y,d;

    scanf ("%d %d",&N,&M);
    for (j=1;j<=N;j++) L[j] = 200000000;
    for (i=0;i<M;i++){
        scanf ("%d %d %d %d",&o,&x,&y,&d);
        O[i] = o; X[i] = x; Y[i] = y; D[i] = d;
        if (o == 1){
            for (j=x;j<=y;j++) V[j] += d;
        }
        else{
            for (j=x;j<=y;j++){
                if (L[j] + V[j] > d)
                    L[j] = d - V[j];
            }
        }
    }

    for (j=1;j<=N;j++) V[j] = L[j];
    for (i=0;i<M;i++){
        o = O[i]; x = X[i]; y = Y[i]; d = D[i];
        if (o == 1){
            for (j=x;j<=y;j++) V[j] += d;
        }
        else{
            int m = V[x];
            for (j=x;j<=y;j++){
                if (m < V[j])
                    m = V[j];
            }
            if (m != d) break;
        }
    }

    if (i == M){
        puts("YES");
        for (i=1;i<=N;i++) printf ("%d ",L[i]);
    }
    else puts("NO");

    return 0;
}
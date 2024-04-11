#include <stdio.h>

int N,K,F,I[1010],C[1010],P[1010];

void go(int a)
{
    if (F) return;

    int i,j;

    if (a <= N){
        for (i=1;i<=N;i++){
            if (I[i] == 0 && C[i] == 0){
                for (j=i-K;j>=0;j--) I[j]--;
                C[i]++; P[a] = i; go(a+1); C[i]--;
                for (j=i-K;j>=0;j--) I[j]++;
            }
        }
    }
    else{
        for (i=1;i<=N;i++) printf ("%d ",P[i]);
        F = 1;
    }
}

int main()
{
    int i;

    scanf ("%d %d",&N,&K);
    for (i=1;i<=N;i++) scanf ("%d",&I[i]);
    go(1);

    return 0;
}
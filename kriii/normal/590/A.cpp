#include <stdio.h>

int N, A[500050];

int main()
{
    scanf ("%d",&N);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);
    int s = 0, c = 1, ans = 0;

    A[N] = A[N-1];
    for (int i=1;i<=N;i++){
        if (A[i] != A[i-1]) c++;
        else{
            int v = (c - 1) / 2;
            if (ans < v) ans = v;
            if (c % 2){
                for (int j=s+1;j<i;j++) A[j] = A[s];
            }
            else{
                for (int j=s+1;j<s+c/2;j++) A[j] = A[s];
                for (int j=s+c/2;j<i;j++) A[j] = !A[s];
            }
            s = i; c = 1;
        }
    }

    printf ("%d\n",ans);
    for (int i=0;i<N;i++) printf ("%d ",A[i]);
    puts("");

    return 0;
}
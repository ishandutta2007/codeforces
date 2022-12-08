#include <stdio.h>

int C[1000],S,A;

int abs(int x){return x < 0 ? -x : x;}

int main()
{
    int N,i,x,y,u;

    scanf ("%d",&N);
    for (i=0;i<N*2;i++){
        scanf ("%d.%d",&x,&y);
        C[y]++; S += y;
    }

    A = 0x7fffffff;
    u = N - C[0];
    if (u < 0) u = 0;
    for (y=N;y>=u;y--){
        if (A > abs(S - y*1000))
            A = abs(S - y*1000);
    }
    printf ("%d.%03d",A/1000,A%1000);

    return 0;
}
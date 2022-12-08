#include <stdio.h>

int N,M,W[100100]; long long V,y;


int main()
{
    int i,x,w,h;

    scanf ("%d",&N);

    for (i=1;i<=N;i++){
        scanf ("%d",&W[i]);
    }
    V = W[0];

    scanf ("%d",&M);
    for (i=1;i<=M;i++){
        scanf ("%d %d",&w,&h);
        x = w;
        if (x > N) x = N;
        y = V;
        if (y < W[x]) y = W[x];

        printf ("%lld\n",y);
        V = y + h;
    }

    return 0;
}
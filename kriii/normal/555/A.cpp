#include <stdio.h>

int N,M,C;

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=0;i<M;i++){
        int o; scanf ("%d",&o);
        int f = 1, c = 0;
        while (o--){
            int x; scanf ("%d",&x);
            if (x == f) f++, c++;
        }
        if (C < c) C = c;
    }

    printf ("%d\n",N-M-C+1+N-C);

    return 0;
}
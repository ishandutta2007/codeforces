#include <stdio.h>

int A,B,C;

int main()
{
    int i,j,d;
    scanf("%d%d%d",&A,&B,&C);
    for (i=0;;i++){
        d = B*i;
        for (j=1;j<=C;j++){
            d += B;
            if (d < j*A) break;
        }
        if (j > C) break;
    }
    printf("%d",i);
}
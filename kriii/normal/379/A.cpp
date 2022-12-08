#include <stdio.h>

int A,B,C,D;

int main()
{
    scanf ("%d %d",&A,&B);
    while (A >= B){
        D = A / B;
        A %= B;
        C += D * B;
        A += D;
    }
    printf ("%d",C+A);

    return 0;
}
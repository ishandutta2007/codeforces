#include <stdio.h>

int N;

int main()
{
    int a,b;
    scanf("%d",&N);
    a = N/36; b = (N-a*36+1)/3;
    if (b == 12) a++, b = 0;
    printf("%d %d",a,b);
}
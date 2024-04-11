#include <stdio.h>

int A,B,R;

int main()
{
    scanf("%d%d%d",&A,&B,&R);
    if (A >= R+R && B >= R+R) puts("First");
    else puts("Second");
}
#include<stdio.h>
int main(void)
{
    int a,b,c,t=0;
    scanf("%d%d",&a,&b);
    for(;;)
    {
        t+=a;
        
        c+=a;
        if(c<b) break;
        a=c/b;
        c%=b;
    }
    printf("%d",t);
}
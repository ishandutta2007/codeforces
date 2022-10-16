#include<stdio.h>
int main(void)
{
    long int a,x,y;
    scanf("%ld%ld%ld",&a,&x,&y);
    if(x>=a||x<=-a) printf("-1");
    else if(y%a==0) printf("-1");
    else if(y<a){if(x<(a+1)/2&&x>-(a+1)/2) printf("1"); else printf("-1");}
    else if((y/a)%2==1)
    {
        if(x<(a+1)/2&&x>-(a+1)/2) printf("%ld",(y/a)*3/2+1);
        else printf("-1");
    }
    else if((y/a)%2==0)
    {
        if(x>=a||x<=-a||x==0) printf("-1");
        else if(x>0) printf("%ld",(y/a)*3/2+1);
        else if(x<0) printf("%ld",(y/a)*3/2);
    }
}
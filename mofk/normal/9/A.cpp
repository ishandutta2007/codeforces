#include<stdio.h>
int main(void)
{
    int y,w,d,t;
    scanf("%d%d",&y,&w);
    if(w>y)
    {
        t=y;y=w;w=t;
    }
    if(y==1) printf("1/1");
    else if(y==2) printf("5/6");
    else if(y==3) printf("2/3");
    else if(y==4) printf("1/2");
    else if(y==5) printf("1/3");
    else printf("1/6");
}
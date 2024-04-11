#include<stdio.h>
int abso(int a)
{
    if(a>0) return a;
    else return -a;
}
int main(void)
{
    int xa,ya,xb,yb,t;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    if(xa==xb)
    {
        if(ya>yb) t=ya-yb;else t=yb-ya;
        printf("%d %d %d %d",xa+t,ya,xa+t,yb);
    }
    else if(ya==yb)
    {
        if(xa>xb) t=xa-xb;else t=xb-xa;
        printf("%d %d %d %d",xa,ya+t,xb,ya+t);
    }
    else{
        if(abso(ya-yb)!=abso(xa-xb)) printf("-1");
        else printf("%d %d %d %d",xa,yb,xb,ya);
    }
}
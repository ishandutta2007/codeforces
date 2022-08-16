//learned from pearfish16

#include<cstdio>

int main()
{
    int x1,x2,a,b;
    scanf("%d%d%d%d",&x1,&x2,&a,&b);
    if (x2-x1>=a&&x2-x1<=b)
    {
        puts("FIRST");
        printf("%d\n",x2);
        return 0;
    }
    int flag=0;
    if (x1>x2)
    {
        int tmp=x1;
        x1=x2;
        x2=tmp;
        flag=1;
        tmp=a;
        a=-b;
        b=-tmp;
    }
    if (a<=0)
    {
        puts("DRAW");
        return 0;
    }
    int tmp=x2-x1;
    int c=tmp%(a+b);
    if (!c)
    {
        puts("SECOND");
        return 0;
    }
    if (c>0&&c<a||c>b&&c-b<a)
    {
        puts("DRAW");
        return 0;
    }
    puts("FIRST");
    printf("%d\n",(flag)?x2-c:x1+c);
    return 0;
}
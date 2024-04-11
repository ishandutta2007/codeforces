#include<stdio.h>
int t(int a,int b,int c)
{
    if(a+b>c&&b+c>a&&c+a>b) return 2;
    else if(a+b<c||b+c<a||c+a<b) return 0;
    else return 1;
}
int main(void)
{
    int a,b,c,d,tri=0,deg=0,no=0;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(t(a,b,c)==0&&t(b,c,d)==0&&t(c,d,a)==0&&t(d,a,b)==0) printf("IMPOSSIBLE");
    else if(t(a,b,c)==2||t(b,c,d)==2||t(c,d,a)==2||t(d,a,b)==2) printf("TRIANGLE");
    else printf("SEGMENT");
}
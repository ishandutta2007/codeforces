#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a00,a01,a10,a11,c0=-1,c1=-1,n;
char ans[1000010];
int main()
{
    scanf("%d%d%d%d",&a00,&a01,&a10,&a11);
    for(int i=0;i<=46340;i++) if(i*(i-1)/2==a00) c0=i;
    for(int i=0;i<=46340;i++) if(i*(i-1)/2==a11) c1=i;
    if(c0==-1||c1==-1) {puts("Impossible");return 0;}
    if(a01+a10!=c0*c1)
    {
        if(a01+a10==0&&(c0==1||c1==1))
        {
            if(c0==1) c0=0;
            else if(c1==1) c1=0;
        }
        else {puts("Impossible");return 0;}
    }
    n=c0+c1;
    while(n)
    {
        while(a01>=c0&&c1)
            c1--,a01-=c0,ans[--n]='1';
        if(c0) c0--,ans[--n]='0';
        else if(c1) c1--,ans[--n]='1';
    }
    puts(ans);
    return 0;
}
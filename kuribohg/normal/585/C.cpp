#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
LL x,y;
int main()
{
    scanf("%I64d%I64d",&x,&y);
    if(gcd(x,y)!=1) {puts("Impossible");return 0;}
    while(x!=y)
    {
        if(x>y)
        {
            LL t,r;
            if(x%y==0) t=x/y-1,r=y;
            else t=x/y,r=x%y;
            printf("%I64d",t);
            putchar('A');
            x=r;
        }
        else
        {
            LL t,r;
            if(y%x==0) t=y/x-1,r=x;
            else t=y/x,r=y%x;
            printf("%I64d",t);
            putchar('B');
            y=r;
        }
    }
    puts("");
    return 0;
}
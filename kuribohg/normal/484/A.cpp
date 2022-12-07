#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T;
LL l,r;
LL Solve(LL l,LL r)
{
    int len1=0,len2=0;
    LL con=1,L=l,R=r;
    while(L) len1++,L>>=1;
    while(R) len2++,R>>=1;
    if(len1==0&&len2==0) return 0;
    if(len1==len2) return Solve(l-(1LL<<(len1-1)),r-(1LL<<(len1-1)))+(1LL<<(len1-1));
    int x=max(len1,len2);
    while((1LL<<x)-1>r) x--;
    return (1LL<<x)-1;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d%I64d",&l,&r);
        printf("%I64d\n",Solve(l,r));
    }
    return 0;
}
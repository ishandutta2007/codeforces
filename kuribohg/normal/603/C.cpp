#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
int calc1(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 0;
    if(n==3) return 1;
    if(n==4) return 2;
    if(n&1) return 0;
    int x=calc1(n>>1);
    if(x==1) return 2;
    return 1;
}
int calc2(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    if(n&1) return 0;
    return 1;
}
int n,k,a[MAXN],SG;
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(k&1) SG^=calc1(a[i]);
        else SG^=calc2(a[i]);
    if(SG==0) puts("Nicky");
    else puts("Kevin");
    return 0;
}
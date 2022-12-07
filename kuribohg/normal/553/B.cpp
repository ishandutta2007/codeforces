#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INF=1000000000000000001LL;
int n,ans[51],tot;
LL Fib[51],k;
int main()
{
    scanf("%d%I64d",&n,&k);
    Fib[0]=Fib[1]=1;
    for(int i=2;i<=50;i++) Fib[i]=Fib[i-1]+Fib[i-2];
    while(tot<n)
    {
        if(k<=Fib[n-tot-1]) ++tot,ans[tot]=tot;
        else
        {
            k-=Fib[n-tot-1];
            ++tot,ans[tot]=tot+1;
            ++tot,ans[tot]=tot-1;
        }
    }
    for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    return 0;
}
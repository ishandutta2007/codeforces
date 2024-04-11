#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,a,b,f[5010],ans=2e9;
int main()
{
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i=1;i<=n+m+3;i++) f[i]=2e9;
    for(int i=1;i<=n+m+3;i++)
    {
        f[i]=min(f[i],f[i-1]+a);
        if(i-m>=0) f[i]=min(f[i],f[i-m]+b);
    }
    for(int i=n;i<=n+m+3;i++) ans=min(ans,f[i]);
    printf("%d\n",ans);
    return 0;
}
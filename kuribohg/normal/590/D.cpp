#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1000000000;
int n,k,s,a[151],ans=INF;
int f[2][151][12000];
int main()
{
    scanf("%d%d%d",&n,&k,&s);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=k;i++)
        for(int j=0;j<=n*(n-1)/2;j++)
            f[0][i][j]=INF;
    f[0][0][0]=0;
    for(int i=1;i<=n;i++)
    {
        int now=i&1,pre=now^1;
        for(int j=0;j<=k;j++)
            for(int k=0;k<=n*(n-1)/2;k++)
                f[now][j][k]=f[pre][j][k];
        for(int j=0;j<min(i,k);j++)
            for(int k=0;k<=(i-1)*(i-2)/2;k++)
                f[now][j+1][k+i-1]=min(f[now][j+1][k+i-1],f[pre][j][k]+a[i]);
    }
    for(int i=0;i<=min(n*(n-1)/2,s+k*(k-1)/2);i++)
        ans=min(ans,f[n&1][k][i]);
    printf("%d\n",ans);
    return 0;
}
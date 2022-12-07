#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INF=1000000000000000000LL;
int n,m,K,c[110];
LL ans=INF;
LL f[110][110][110],p[110][110];
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%I64d",&p[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<=K;k++)
                f[i][j][k]=INF;
    for(int i=1;i<=m;i++)
        if(c[1]==i||c[1]==0) f[1][i][1]=p[1][i];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            if(j==c[i]||c[i]==0)
            {
                for(int pre=1;pre<=m;pre++)
                    for(int k=0;k<=K;k++)
                    {
                        if(pre!=j&&k!=K) f[i][j][k+1]=min(f[i][j][k+1],f[i-1][pre][k]+p[i][j]);
                        if(pre==j) f[i][j][k]=min(f[i][j][k],f[i-1][pre][k]+p[i][j]);
                    }
            }
    }
    for(int i=1;i<=m;i++) ans=min(ans,f[n][i][K]);
    if(ans==INF) puts("-1");
    else
    {
        for(int i=1;i<=n;i++)
            if(c[i]!=0) ans-=p[i][c[i]];
        printf("%I64d\n",ans);
    }
    return 0;
}
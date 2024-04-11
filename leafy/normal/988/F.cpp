#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2005,inf=0x3f3f3f3f;
int a,n,m;
int rain[N],x[N],p[N];
int b[N],k[N];
int f[N][N];
int main()
{
    scanf("%d%d%d",&a,&n,&m);
    int l,r;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&l,&r);
        for(int j=l;j<r;j++) rain[j]=1;
    }
    memset(b,0x3f,sizeof(b));
    memset(f,0x3f,sizeof(f));
    for(int i=0;i<m;i++) 
    {
        scanf("%d%d",&x[i],&p[i]);
        if(p[i]<b[x[i]]) b[x[i]]=p[i],k[x[i]]=i;
    }

    f[0][m]=0;
    for(int i=0;i<a;i++)
        for(int j=0;j<=m;j++)
        {
            if(f[i][j]==inf) continue;
            if(rain[i]==0) f[i+1][m]=min(f[i+1][m],f[i][j]);
            if(j<m) f[i+1][j]=min(f[i+1][j],f[i][j]+p[j]);
            if(b[i]!=inf) f[i+1][k[i]]=min(f[i+1][k[i]],f[i][j]+b[i]);
        }
    int ans=inf;
    for(int i=0;i<=m;i++) ans=min(f[a][i],ans);
    if(ans==inf) printf("-1");
    else printf("%d",ans);
    return 0;
}
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a,b,g[2010][2010];
double f[2010][2010],p[2010],q[2010];
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<=n;i++) scanf("%lf",&p[i]);
    for(int i=1;i<=n;i++) scanf("%lf",&q[i]);
    double L=-1e9,R=1e9;
    for(int T=1;T<=100;T++)
    {
        double mid=(L+R)/2;
        f[0][0]=0;
        for(int i=1;i<=a;i++) f[0][i]=-1e18;
        for(int i=1;i<=n;i++)
            for(int j=0;j<=min(i,a);j++)
            {
                f[i][j]=f[i-1][j],g[i][j]=g[i-1][j];
                if(f[i-1][j]+q[i]-mid>f[i][j])
                    f[i][j]=f[i-1][j]+q[i]-mid,g[i][j]=g[i-1][j]+1;
                if(j!=0&&f[i-1][j-1]+p[i]+q[i]-p[i]*q[i]-mid>f[i][j])
                    f[i][j]=f[i-1][j-1]+p[i]+q[i]-p[i]*q[i]-mid,g[i][j]=g[i-1][j-1]+1;
                if(j!=0&&f[i-1][j-1]+p[i]>f[i][j])
                    f[i][j]=f[i-1][j-1]+p[i],g[i][j]=g[i-1][j-1];
            }
        if(g[n][a]<=b) R=mid;
        else L=mid;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=min(i,a);j++)
        {
            f[i][j]=f[i-1][j];
            f[i][j]=max(f[i][j],f[i-1][j]+q[i]-L);
            if(j!=0) f[i][j]=max(f[i][j],f[i-1][j-1]+p[i]+q[i]-p[i]*q[i]-L);
            if(j!=0) f[i][j]=max(f[i][j],f[i-1][j-1]+p[i]);
        }
    printf("%.010lf\n",f[n][a]+L*b);
    return 0;
}
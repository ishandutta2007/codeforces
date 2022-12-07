#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const LL INF=1000000000000000000LL;
int T,n,m,k;
LL f[31][31][51];
LL getf(int n,int m,int k)
{
    if(f[n][m][k]!=-1) return f[n][m][k];
    if(k==n*m||k==0) return f[n][m][k]=0;
    f[n][m][k]=INF;
    for(int i=1;i<n;i++)
        for(int o=0;o<=k;o++)
            if(o<=i*m&&o<=(n-i)*m)
                f[n][m][k]=min(f[n][m][k],m*m+getf(i,m,o)+getf(n-i,m,k-o));
    for(int i=1;i<m;i++)
        for(int o=0;o<=k;o++)
            if(o<=n*i&&o<=n*(m-i))
                f[n][m][k]=min(f[n][m][k],n*n+getf(n,i,o)+getf(n,m-i,k-o));
    return f[n][m][k];
}
int main()
{
    scanf("%d",&T);
    memset(f,-1,sizeof(f));
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        printf("%I64d\n",getf(n,m,k));
    }
    return 0;
}
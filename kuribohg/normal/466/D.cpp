#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MOD=1000000007;
typedef long long LL;
int n,m,a[2010],b[2010];
LL f[2010][2010],ans;
int main()
{
    f[0][0]=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) a[i]=b[i]-b[i-1];
    a[1]=m-a[1];for(int i=2;i<=n;i++) a[i]=-a[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<=n;j++)
            if(f[i][j]!=0)
            {
                if(a[i+1]==1) f[i+1][j+1]=(f[i][j]+f[i+1][j+1])%MOD;
                if(a[i+1]==-1&&j>0) f[i+1][j-1]=(j*f[i][j]+f[i+1][j-1])%MOD;
                if(a[i+1]==0)
                {
                    f[i+1][j]=(f[i+1][j]+f[i][j])%MOD;
                    if(j>0) f[i+1][j]=(f[i+1][j]+j*f[i][j])%MOD;
                }
            }
    ans=(f[n][0]+f[n][1])%MOD;
    printf("%d\n",ans);
    return 0;
}
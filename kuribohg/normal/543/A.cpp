#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,B,MOD,f[2][510][510],a[510],ans;
int main()
{
    scanf("%d%d%d%d",&n,&m,&B,&MOD);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0][0][0]=1;
    for(int i=1;i<=n;i++)
    {
        int cur=i&1,pre=cur^1;
        for(int j=0;j<=m;j++)
            for(int k=0;k<=B;k++)
            {
                f[cur][j][k]=f[pre][j][k];
                if(j>=1&&k>=a[i])
                    f[cur][j][k]=(f[cur][j][k]+f[cur][j-1][k-a[i]])%MOD;
            }
    }
    for(int i=0;i<=B;i++) ans=(ans+f[n&1][m][i])%MOD;
    printf("%d\n",ans);
    return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
const int mod=998244353;
int n,k;
long long f[1005][4][2005];
int main()
{
    scanf("%d%d",&n,&k);
    f[1][0][1]=f[1][1][2]=f[1][2][2]=f[1][3][1]=1;
    /*for(int i=1;i<=n;i++)
        for(int j=0;j<=3;j++)
            f[i][j][0]=1;*/
    for(int i=2;i<=n;i++)
        for(int j=0;j<=3;j++)
            for(int l=1;l<=k;l++)
            {
                if(j==0) f[i][j][l]=(f[i-1][3][l-1]+f[i-1][2][l]+f[i-1][1][l]+f[i-1][0][l])%mod;
                else if(j==3) f[i][j][l]=(f[i-1][0][l-1]+f[i-1][2][l]+f[i-1][1][l]+f[i-1][3][l])%mod;
                else
                {
                    f[i][j][l]=(f[i-1][0][l-1]+f[i-1][3][l-1]+f[i-1][j][l])%mod;
                    if(l>=2) f[i][j][l]=f[i][j][l]+f[i-1][3-j][l-2];
                }
            }
    cout<<(f[n][0][k]+f[n][1][k]+f[n][2][k]+f[n][3][k])%mod;
    return 0;
}
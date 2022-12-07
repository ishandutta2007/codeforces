#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
int n,c[1010],sum[1010];
LL C[1010][1010],f[1010][1010];
int main()
{
    C[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+c[i];
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        LL S=0;
        for(int j=1;j<=sum[n];j++)
        {
            S=(S+f[i-1][j-1])%MOD;
            if(j-sum[i-1]-1>=0) f[i][j]=(S*C[j-sum[i-1]-1][c[i]-1])%MOD;
        }
    }
    printf("%I64d\n",f[n][sum[n]]);
    return 0;
}
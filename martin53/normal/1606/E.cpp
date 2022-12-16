#include<bits/stdc++.h>
using namespace std;

const int nmax=542,mod=998244353;

long long pwr[nmax][nmax],c[nmax][nmax],dp[nmax][nmax];

int rec(int n,int x)
{
    if(n==0)return 1;
    if(n==1)return 0;
    if(x==0)return 0;

    if(x<=n-1)return pwr[x][n];

    if(dp[n][x]!=-1)return dp[n][x];

    long long ret=0;

    for(int i=0;i<=n;i++)
    {
        long long cur=rec(n-i,x-(n-1));
        cur=cur*c[n][i]%mod;
        cur=cur*pwr[n-1][i]%mod;

        ret=(ret+cur)%mod;
    }

    dp[n][x]=ret;
    return ret;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    int n,x;
    scanf("%i%i",&n,&x);

    for(int i=0;i<nmax;i++)
    {
        pwr[i][0]=1;
        c[i][0]=1;

        for(int j=1;j<nmax;j++)
        {
            pwr[i][j]=pwr[i][j-1]*i%mod;

            if(j<=i)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
        }
    }

    printf("%i\n",rec(n,x));

    return 0;
}
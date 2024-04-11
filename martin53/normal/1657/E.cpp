#include<bits/stdc++.h>
using namespace std;

const int nmax=250+42,mod=998244353;

int n,k;

int dp[nmax][nmax];

long long c[nmax][nmax];

long long pwr(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;

        a=a*a%mod;

        b=b/2;
    }

    return ret;
}

int solve(int connected,int k_remain)
{
    if(connected==n)return 1;

    if(k_remain==0)return 0;

    if(dp[connected][k_remain]!=-1)return dp[connected][k_remain];

    long long ret=solve(connected,k_remain-1);

    for(int add_now=1;add_now+connected<=n;add_now++)
    {
        ret=(ret+solve(connected+add_now,k_remain-1)*pwr(k_remain,(connected-1)*add_now+add_now*(add_now-1)/2)%mod*c[n-connected][add_now])%mod;
    }

    //cout<<connected<<" "<<k_remain<<" -> "<<ret<<endl;

    dp[connected][k_remain]=ret;

    return ret;
}

int main()
{
    for(int i=0;i<nmax;i++)
        for(int j=0;j<=i;j++)
            if(j==0||j==i)c[i][j]=1;
            else c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;

    memset(dp,-1,sizeof(dp));

    scanf("%i%i",&n,&k);

    printf("%i\n",solve(1,k));

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,kmax=50,mod=1e9+7;
int dp[nmax][nmax][kmax];
int fact[nmax],inv[nmax];
long long my_pow(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}
int rec(int sum,int mx,int numbers)
{
    if(sum<0)return 0;
    if(numbers==0&&sum==0)return 1;
    if(sum==0)return 0;
    if(mx==0)return 0;
    if(dp[sum][mx][numbers]!=-1)return dp[sum][mx][numbers];
    dp[sum][mx][numbers]=rec(sum-mx,mx-1,numbers-1)+rec(sum,mx-1,numbers);
    dp[sum][mx][numbers]%=mod;

    //cout<<sum<<" "<<mx<<" "<<numbers<<" -> "<<dp[sum][mx][numbers]<<endl;

    return dp[sum][mx][numbers];
}
int main()
{
fact[0]=1;
for(int i=1;i<nmax;i++)fact[i]=1LL*i*fact[i-1]%mod;
for(int i=0;i<nmax;i++)inv[i]=my_pow(fact[i],mod-2);

int t,n,k;
scanf("%i",&t);
memset(dp,-1,sizeof(dp));
for(int i=1;i<=t;i++)
{
    scanf("%i%i",&n,&k);
    if(k>=kmax)printf("0\n");
    else
    //printf("%i\n",1LL*rec(n,n,k)%mod);
    {
        long long ret=0;
        for(int j=1;j<=n;j++)
            {
            ret=(ret+1LL*rec(j,j,k)*fact[n-j+k]%mod*inv[n-j])%mod;
            //cout<<fact[n-j+k]<<" "<<inv[n-j]<<endl;
            }
        printf("%lld\n",ret);
    }
}
return 0;
}
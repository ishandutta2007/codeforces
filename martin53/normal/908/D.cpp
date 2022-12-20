#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42,mod=1e9+7;
int my_pow(int a,int b)
{
    if(b==0)return 1;
    int c=my_pow(a,b/2);
    if(b%2)return 1LL*c*c%mod*a%mod;
    return 1LL*c*c%mod;
}
int dp[nmax][nmax];
int pa,pb;
long long ca,cb;
int rec(int a,int k)
{
    if(dp[a][k]!=-1)return dp[a][k];
    long long ans=0;
    if(a>=k)
    {
        ans=1LL*a*pb+pa;
        ans=ans%mod;
        ans=ans*my_pow(pb,mod-2)%mod;
    }
    else
    {
    ans=ans+ca*rec(a+1,k);
    ans=ans+cb*(a+rec(a,k-a));
    ans=ans%mod;
    dp[a][k]=ans;
    }
    return ans;
}
int k;
int main()
{
memset(dp,-1,sizeof(dp));
scanf("%i%i%i",&k,&pa,&pb);
ca=1LL*pa*my_pow(pa+pb,mod-2)%mod;
cb=1LL*pb*my_pow(pa+pb,mod-2)%mod;
printf("%i\n",rec(1,k));
return 0;
}
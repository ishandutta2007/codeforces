#include<bits/stdc++.h>
using namespace std;
const int kmax=5e3+42,mod=1e9+7;
int n,k;
int dp[kmax][kmax];
int my_pow(long long a,int b)
{
    long long ret=1;
    while(b)
    {
        if(b%2==1)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }
    return ret;
}
int main()
{
cin>>n>>k;
dp[0][0]=1;
for(int letters=1;letters<=k;letters++)
    for(int different=1;different<=letters;different++)
    dp[letters][different]=(1LL*different*dp[letters-1][different]+1LL*(n-different+1)*dp[letters-1][different-1])%mod;

int sum=0;
for(int i=1;i<=k&&i<=n;i++)
    sum=(sum+1LL*dp[k][i]*my_pow(2,n-i))%mod;
cout<<sum<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,mod=1e9+7,LIM=1e3+42;
int n,k,a[nmax];
map<int,int> lucky_numbers;
bool lucky(int x)
{
while(x)
{
    if(x%10!=4&&x%10!=7)return 0;
    x=x/10;
}
return 1;
}
int arr[LIM];
long long fact[nmax];
long long dp[LIM][LIM];
long long my_pow(long long a,long long b)
{
if(b==0)return 1;
long long c=my_pow(a,b/2);
if(b%2==0)return c*c%mod;
return c*c%mod*a%mod;
}
long long inv(long long x)
{
return my_pow(x,mod-2);
}
long long comb(int p,int q)
{
if(q<0)return 0;
if(p<q)return 0;
return fact[p]*inv(fact[q])%mod*inv(fact[p-q])%mod;
}
int main()
{
cin>>n>>k;
int luck=0;
for(int i=1;i<=n;i++)
{
cin>>a[i];
    if(lucky(a[i]))
    {
    lucky_numbers[a[i]]++;
    luck++;
    }
}
int m=0;
for(auto k:lucky_numbers)
{
    m++;
    arr[m]=k.second;
}

fact[0]=1;
for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;

dp[0][0]=1;
for(int pos=1;pos<=m;pos++)
    for(int numbers=0;numbers<=pos;numbers++)
    {
        if(numbers==0)dp[pos][numbers]=1;
        else
        {
        dp[pos][numbers]=(dp[pos-1][numbers]+dp[pos-1][numbers-1]*arr[pos])%mod;
        }
    }

long long ans=0;
for(int a=0;a<=k&&a<=m;a++)
{
    long long now=dp[m][a];
    now=now*comb(n-luck,k-a)%mod;
    ans=(ans+now)%mod;
}
cout<<ans<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,mod=1e9+7,lim=2*1e5+7;
int n,h,w;
pair<int,int> inp[nmax];
bool cmp(pair<int,int> a,pair<int,int> b)
{
if(a.first!=b.first)return a.first<b.first;
return a.second<b.second;
}
long long my_pow(long long a,long long b)
{
    if(b==0)return 1;
    long long c=my_pow(a,b/2);
    if(b%2==0)return c*c%mod;
    return c*c%mod*a%mod;
}
long long fact[lim],inv[lim],dp[nmax];
long long C(int p,int q)
{
    if(p<q)return 0;
    return fact[p]*inv[q]%mod*inv[p-q]%mod;
}
long long paths(int x1,int y1,int x2,int y2)
{
    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    return C(x2-x1+y2-y1,x2-x1);
}
int main()
{
cin>>h>>w>>n;
for(int j=1;j<=n;j++)cin>>inp[j].first>>inp[j].second;
inp[0]={1,1};
n++;
inp[n]={h,w};
sort(inp+1,inp+n+1,cmp);

dp[0]=1;

fact[0]=1;
for(int i=1;i<lim;i++)fact[i]=(fact[i-1]*i)%mod;
for(int i=0;i<lim;i++)
{
    inv[i]=my_pow(fact[i],mod-2);
}

for(int i=1;i<=n;i++)
{
    dp[i]=paths(1,1,inp[i].first,inp[i].second);
        for(int j=1;j<i;j++)//meet first black
        {
        dp[i]=(dp[i]-dp[j]*paths(inp[j].first,inp[j].second,inp[i].first,inp[i].second))%mod;
        if(dp[i]<0)dp[i]=dp[i]+mod;
        }
}

cout<<dp[n]<<endl;
return 0;
}
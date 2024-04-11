#include<bits/stdc++.h>
using namespace std;
const int nmax=24,mod=1e9+7;
int n;
long long arr[nmax];
int k;
long long special[nmax];
int dp[1<<nmax];//0->not used
int main()
{
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
cin>>k;
for(int i=1;i<=k;i++)cin>>special[i];

long long s=0;
for(int i=0;i<n;i++)s=s+arr[i];

for(int i=1;i<=k;i++)
    if(s==special[i])
    {
    cout<<0<<endl;
    return 0;
    }

dp[(1<<n)-1]=1;
for(int state=(1<<n)-2;state>=0;state--)
{
    s=0;
    for(int j=0;j<n;j++)
        if((state&(1<<j)))s=s+arr[j];
        else
        {
        dp[state]=dp[state]+dp[state+(1<<j)];
        if(dp[state]>=mod)dp[state]=dp[state]-mod;
        }
    for(int j=1;j<=k;j++)
        if(s==special[j])
        dp[state]=0;
}

cout<<dp[0]<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,mod=1e9+7;
int n,arr[nmax];
long long fact[nmax];
long long dp[nmax][nmax];
long long rec(int numbers,int free)
{
    //cout<<numbers<<" "<<free<<endl;
    if(numbers==free)return fact[numbers];
    if(dp[numbers][free]!=-1)return dp[numbers][free];
    long long ans=0;
    int taken=numbers-free;
    /*
    if(free)ans=ans+free*rec(numbers-1,free-1);//free->free
    if(free)ans=ans+taken*rec(numbers-1,free);//free->taken
    */
    if(taken)ans=ans+free*rec(numbers-1,free);//taken->free
    if(taken>1)ans=ans+(taken-1)*rec(numbers-1,free+1);//taken->taken
    ans=ans%mod;
    //ans=ans/numbers;
    dp[numbers][free]=ans;
    //cout<<numbers<<" "<<free<<" -> "<<dp[numbers][free]<<endl;
    return ans;
}
bool block[nmax],blocked[nmax];
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];

int numbers=0,free=0;
for(int i=1;i<=n;i++)
    if(arr[i]!=-1)
    {
    block[i]=1;
    blocked[arr[i]]=1;
    }
    else numbers++;
for(int j=1;j<=n;j++)
    if(blocked[j]==0&&block[j])free++;

fact[0]=1;
for(int i=1;i<=n;i++)fact[i]=(fact[i-1]*i)%mod;

memset(dp,-1,sizeof(dp));
cout<<rec(numbers,free)<<endl;
return 0;
}
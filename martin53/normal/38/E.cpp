#include<bits/stdc++.h>
using namespace std;
const int nmax=3e3+42;
int n;
pair<int/*x*/,int/*c*/> inp[nmax];
long long dp[nmax];
bool cmp(pair<int,int> a,pair<int,int> b)
{
return a.first<b.first;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
    cin>>inp[i].first>>inp[i].second;
sort(inp+1,inp+n+1,cmp);
dp[0]=0;
for(int i=1;i<=n;i++)
{
    long long sum=0;
    dp[i]=1e18;
    for(int j=i;j>=1;j--)
    {
        dp[i]=min(dp[i],dp[j-1]+inp[j].second+sum-1LL*(i-j)*inp[j].first);
        sum=sum+inp[j].first;
    }
    //cout<<i<<" -> "<<dp[i]<<endl;
}

cout<<dp[n]<<endl;
return 0;
}
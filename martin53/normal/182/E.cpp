#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+5,lmax=3e3+42,mod=1e9+7;
int n,l;
int dp[lmax][nmax][2];
pair<int,int> inp[nmax];
int add(int v)
{
    if(v>=mod)return v-mod;
    return v;
}

int rec(int len,int ind,bool rot)
{
    //cout<<len<<" "<<ind<<" "<<rot<<endl;
    if(len<0)return 0;
    if(len==0)return 1;
    if(dp[len][ind][rot]!=-1)return dp[len][ind][rot];
    int sum=0;
    for(int i=1;i<=n;i++)
    if(i!=ind)
    {
        if(rot==0)
        {
            if(inp[ind].second==inp[i].first)sum=add(sum+rec(len-inp[i].first,i,0));
            if(inp[ind].second==inp[i].second&&inp[i].first!=inp[i].second)sum=add(sum+rec(len-inp[i].second,i,1));
        }
        else//rot=1
        {
            if(inp[ind].first==inp[i].first)sum=add(sum+rec(len-inp[i].first,i,0));
            if(inp[ind].first==inp[i].second&&inp[i].first!=inp[i].second)sum=add(sum+rec(len-inp[i].second,i,1));
        }
    }
    dp[len][ind][rot]=sum;
    return sum;
}
int main()
{
memset(dp,-1,sizeof(dp));
cin>>n>>l;
for(int i=1;i<=n;i++)cin>>inp[i].first>>inp[i].second;
int ans=0;
for(int i=1;i<=n;i++)
{
    ans=(ans+rec(l-inp[i].first,i,0))%mod;
    if(inp[i].first!=inp[i].second)ans=(ans+rec(l-inp[i].second,i,1))%mod;
}
cout<<ans<<endl;
return 0;
}
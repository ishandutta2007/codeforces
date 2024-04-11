#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,q;
int value[nmax],colour[nmax];
long long dp[nmax];
long long query()
{
int a,b;
cin>>a>>b;
for(int i=1;i<=n;i++)
    dp[i]=-1e18;
long long ans=0,now=0;
pair<long long/*value*/,int/*colour*/> best={-1e18,0},second_best={-1e18,0};
for(int i=1;i<=n;i++)
{

    long long now=dp[colour[i]]+1LL*value[i]*a;//take the a
    now=max(now,1LL*value[i]*b);//alone

    if(best.second!=colour[i])now=max(now,best.first+1LL*value[i]*b);
    else now=max(now,second_best.first+1LL*value[i]*b);

    dp[colour[i]]=max(dp[colour[i]],now);
    ans=max(ans,now);

    if(best.first<=now)
    {
        if(best.second==colour[i])best.first=now;
        else
        {
        second_best=best;
        best={now,colour[i]};
        }
    }
    else if(second_best.first<=now&&colour[i]!=best.second)
    {
        second_best={now,colour[i]};
    }

    /*
    long long now=1LL*value[i]*b;
    for(int j=1;j<=n;j++)
        if(j==colour[i])now=max(now,dp[j]+1LL*value[i]*a);
        else now=max(now,dp[j]+1LL*value[i]*b);

    dp[colour[i]]=max(dp[colour[i]],now);
    ans=max(now,ans);
    */
}
return ans;
}
int main()
{
cin>>n>>q;
for(int i=1;i<=n;i++)cin>>value[i];
for(int i=1;i<=n;i++)cin>>colour[i];
for(int i=1;i<=q;i++)
    cout<<query()<<endl;
return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int nmax=150+5,inf=1e9;
int n,k,s;
int inp[nmax];
int dp[2][nmax*nmax/2][nmax];
int take(int pos,int sum,int taken)
{
    if(sum<0||taken<0)return inf;
    return dp[pos][sum][taken];
}
int main()
{
scanf("%i%i%i",&n,&k,&s);
for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

for(int i=0;i<nmax*nmax/2;i++)
    for(int j=0;j<nmax;j++)
    dp[0][i][j]=dp[1][i][j]=inf;

dp[0][0][0]=0;
int ans=inf;
for(int pos=1;pos<=n;pos++)
    for(int sum=0;sum<=n*(n+1)/2&&sum<=s;sum++)
        for(int taken=0;taken<=k;taken++)
        {
            dp[pos&1][sum][taken]=take(!(pos&1),sum,taken);
            dp[pos&1][sum][taken]=min(dp[pos&1][sum][taken],take(!(pos&1),sum-pos+taken,taken-1)+inp[pos]);
            if(taken==k)ans=min(ans,dp[pos&1][sum][taken]);
        }
    printf("%i\n",ans);
return 0;
}
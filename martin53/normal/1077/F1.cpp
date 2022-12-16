#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42;
int n,k,x;
int arr[nmax];
long long dp[nmax][nmax];
int main()
{
scanf("%i%i%i",&n,&k,&x);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
memset(dp,-1,sizeof(dp));
dp[0][0]=0;
for(int pick=1;pick<=x;pick++)
{
    deque< pair<long long/*value*/,int/*index*/> > q={};
    for(int j=0;j<=n;j++)
    {
        while(q.size()>0&&j-q.front().second-1>=k)q.pop_front();
        if(q.size())
        {
            dp[pick][j]=q.front().first+arr[j];
        }
        if(dp[pick-1][j]!=-1)
        {
            while(q.size()>0&&q.back().first<=dp[pick-1][j])q.pop_back();
            q.push_back({dp[pick-1][j],j});
        }
        //cout<<j<<" "<<pick<<" -> "<<dp[pick][j]<<" "<<q.size()<<endl;
    }
}
long long ret=-1;
for(int j=1;j<=n;j++)
    if(j+k-1>=n)ret=max(ret,dp[x][j]);
printf("%lld\n",ret);
return 0;
}
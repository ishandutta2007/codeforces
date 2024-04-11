#include<bits/stdc++.h>
using namespace std;
const int nmax=25;
int n;
long long dp[nmax][5][5][nmax/2][nmax/2];
long long rec(int pos,int x1,int x2,int up,int down)
{
    //cout<<pos<<" "<<x1<<" "<<x2<<" "<<up<<" "<<down<<endl;
    if(up<0||down<0)return 0;
    if(pos==n+1)return up==0&&down==0;
    if(dp[pos][x1][x2][up][down]!=-1)return dp[pos][x1][x2][up][down];
    long long s=0;
    for(int x3=1;x3<=4;x3++)
    {
        if(x2==x3)continue;

        if(x1<x2&&x2>x3)s=s+rec(pos+1,x2,x3,up-1,down);
        else if(x1>x2&&x2<x3)s=s+rec(pos+1,x2,x3,up,down-1);
        else s=s+rec(pos+1,x2,x3,up,down);
    }
    dp[pos][x1][x2][up][down]=s;
    return s;
}
int main()
{
int t;
cin>>n>>t;

memset(dp,-1,sizeof(dp));
long long ans=0;
for(int x1=1;x1<=4;x1++)
    for(int x2=1;x2<=4;x2++)
        if(x1!=x2)ans=ans+rec(3,x1,x2,t,t-1);
cout<<ans<<endl;
return 0;
}
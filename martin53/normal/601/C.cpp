#include<bits/stdc++.h>
using namespace std;
const int LIM=1e5+1e3+42,MX=1e5+5;
int n,m;
double dp[LIM];
double add[LIM];
void go(int x)
{
    for(int i=0;i<LIM;i++)
        add[i]=0;

    for(int i=0;i<MX;i++)
    {
        add[i+1]+=dp[i]/(m-1);
        add[i+m+1]-=dp[i]/(m-1);

        add[i+x]-=dp[i]/(m-1);
        add[i+x+1]+=dp[i]/(m-1);
    }
    dp[0]=0;
    for(int j=1;j<LIM;j++)
        dp[j]=dp[j-1]+add[j];
}
int main()
{
cin>>n>>m;
if(m==1)
{
    cout<<1<<endl;
    return 0;
}
dp[0]=m-1;
int s=0,x;
for(int i=1;i<=n;i++)
{
    cin>>x;
    go(x);
    s=s+x;
    /*
    for(int j=1;j<=m*i;j++)
        cout<<j<<" -> "<<dp[j]<<endl;
    */
}
double ans=1;
for(int i=1;i<s;i++)
    ans=ans+dp[i];
printf("%.18f\n",ans);
return 0;
}
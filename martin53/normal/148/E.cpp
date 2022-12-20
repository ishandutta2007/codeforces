#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+5,inf=1e9;
int n,m;
vector<int> values[nmax];
int sz[nmax],arr[nmax];
int dp[nmax][nmax*nmax];
int rec(int position,int take)
{
if(position==0)
{
    if(take==0)dp[position][take]=0;
    else dp[position][take]=-inf;
}
if(dp[position][take]!=-1)return dp[position][take];
int ans=0;
for(int i=0;i<=sz[position]&&i<=take;i++)
    ans=max(ans,values[position][i]+rec(position-1,take-i));
dp[position][take]=ans;
return ans;
}
int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>sz[i];
    for(int j=1;j<=sz[i];j++)cin>>arr[j];
    for(int j=0;j<=sz[i];j++)values[i].push_back(0);

    int sum=0;
    for(int j=1;j<=sz[i];j++)sum=sum+arr[j];

    values[i][sz[i]]=sum;
    //cout<<"---"<<endl;
    for(int j=1;j<=sz[i];j++)
    {
    int now=0;
        for(int k=j;k<=sz[i];k++)
        {
        now=now+arr[k];
        //cout<<j<<" "<<k<<" "<<now<<" "<<sum<<endl;
        values[i][sz[i]-(k-j+1)]=max(values[i][sz[i]-(k-j+1)],sum-now);
        }
    }
    //cout<<"values: ";for(int j=0;j<=sz[i];j++)cout<<values[i][j]<<" ";cout<<endl;
}
memset(dp,-1,sizeof(dp));
cout<<rec(n,m)<<endl;

return 0;
}
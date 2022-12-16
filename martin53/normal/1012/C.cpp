#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42;
int n,arr[nmax];
int dp[nmax][nmax/2][2];
int maxi(int a,int b)
{
    if(a>b)return a;
    return b;
}
int mini(int a,int b)
{
    if(a<b)return a;
    return b;
}
int rec(int pos,int build,bool made)
{
    if(build==0)return 0;
    if(pos>n)return 1e9;
    if(dp[pos][build][made]!=-1)return dp[pos][build][made];
    int ans=rec(pos+1,build,0);//do not build
    //build
    if(made==0)
    {
        ans=mini(ans,rec(pos+2,build-1,1)+maxi(0,arr[pos-1]-arr[pos]+1)+maxi(0,arr[pos+1]-arr[pos]+1));
    }
    else
    {
        if(arr[pos-2]<=arr[pos])ans=mini(ans,rec(pos+2,build-1,1)+maxi(0,arr[pos+1]-arr[pos]+1));
        else ans=mini(ans,rec(pos+2,build-1,1)+maxi(0,arr[pos+1]-arr[pos]+1)+maxi(0,mini(arr[pos-2]-1,arr[pos-1])-arr[pos]+1));
    }
    //cout<<pos<<" "<<build<<" "<<made<<" -> "<<ans<<endl;
    dp[pos][build][made]=ans;
    return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];

memset(dp,-1,sizeof(dp));
/*
for(int pos=1;pos<=n;pos++)
{
    int STOP=(pos+1)/2;
    for(int built=0;built<=(pos+1)/2;built++)
    {
        //do not build the pos
        dp[pos][built][0][0]=min(dp[pos-1][built][0])
    }
}
*/
for(int i=1;i<=(n+1)/2;i++)
{
    cout<<rec(1,i,0)<<" ";
}
cout<<endl;
return 0;
}
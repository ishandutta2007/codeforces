#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+1];
    a[0]=0;
    for(int x=1;x<=n;x++)
    cin>>a[x],a[x]+=a[x-1];
    int dp[n+1][m+1];
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int y=m;y>=0;y--)
    for(int x=1;x<=n;x++)
    for(int z=y;z<=m;z++)
    dp[x][z]=min(dp[x][z],dp[x-1][z-y]+abs(z-a[x]));
    cout<<dp[n][m]<<endl;
}
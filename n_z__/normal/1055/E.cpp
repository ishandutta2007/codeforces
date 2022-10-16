#include<bits/stdc++.h>
using namespace std;
int n,m,s,k,a[10001],l[10001],r[10001],dp[5001][5001];
bool chk(int x)
{
	memset(dp,0,sizeof(dp));
	for(int y=1;y<=n;y++)
	{
		int lst=y+1,sum=0;
		for(int z=1;z<=m;z++)if(l[z]<=y&&y<=r[z])lst=min(lst,l[z]);
		for(int z=lst;z<=y;z++)sum+=(a[z]<=x);
		for(int z=1;z<=s;z++)dp[y][z]=max(dp[y-1][z],dp[lst-1][z-1]+sum); 
	}
    /*cout<<x<<":"<<dp[n][s]<<endl;
    for(int y=1;y<=n;y++){for(int z=1;z<=s;z++)cout<<dp[y][z]<<' ';cout<<endl;}*/
	return (dp[n][s]>=k);
}
int main()
{
	cin>>n>>m>>s>>k;
	for(int x=1;x<=n;x++)
    cin>>a[x];
	for(int x=1;x<=m;x++)
    cin>>l[x]>>r[x];
	int l=1,r=1e9,mid,ans=-1;
	while(l<=r)
    {
        mid=(l+r)/2;
        if(chk(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
	cout<<ans<<endl;
}
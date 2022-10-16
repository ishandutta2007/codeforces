#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,k;
}o[501];
int dp[501];
signed main(){
	int n;
	cin>>n;
	for(int x=1;x<=n;x++)
	cin>>o[x].a>>o[x].b>>o[x].k;
	sort(o+1,o+n+1,[](node x,node y){return x.b>y.b;});
	for(int x=1;x<=n;x++)
	for(int y=n-1;y>=0;y--)
	dp[y+1]=max(dp[y+1],dp[y]+o[x].a-o[x].b*y),dp[y]=max(dp[y],dp[y]+o[x].a-o[x].k*o[x].b);
	int ans=0;
	for(int x=0;x<=n;x++)
	ans=max(ans,dp[x]);
	cout<<ans<<endl;
}
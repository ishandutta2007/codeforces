#include<bits/stdc++.h>
using namespace std;
int n,res,maxn,dp[100005],a[100005],tot=0,ans[100005],p[100005],vis[100005];
vector<int>v[100005];
int main()
{
	scanf("%d",&n),maxn=0,memset(vis,0,sizeof(vis)),tot=0,res=0;
	for(int i=1;i<=n;i++) scanf("%d",a+i),maxn=max(maxn,a[i]),dp[i]=1;
	for(int i=2;i<=maxn;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;j<=tot&&i*p[j]<=maxn;j++) {vis[i*p[j]]=1;if(i%p[j]==0) break;}
	}
	for(int i=1;i<=tot;i++) for(int j=p[i];j<=maxn;j+=p[i]) v[j].push_back(p[i]);
	for(int i=1,rans=0;i<=n;i++,rans=0)
	{
		for(int j=0;j<(int)v[a[i]].size();j++) rans=max(rans,ans[v[a[i]][j]]);
		dp[i]=max(dp[i],rans+1);
		for(int j=0;j<(int)v[a[i]].size();j++) ans[v[a[i]][j]]=max(ans[v[a[i]][j]],dp[i]);
		res=max(res,dp[i]);
	}
	return printf("%d\n",res),0;
}
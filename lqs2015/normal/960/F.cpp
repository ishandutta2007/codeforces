#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
int x[111111],y[111111],z[111111];
int n,m,sz,dp[111111],ans;
map<pair<int,int>,int> mp;
int query(int r,int x)
{
	int res=0;
	while(x>=1)
	{
		if (mp.find(make_pair(r,x))!=mp.end()) res=max(res,mp[make_pair(r,x)]);
		x-=x&(-x);
	}
	return res;
}
void update(int r,int x,int w)
{
	while(x<=sz)
	{
		if(mp.find(make_pair(r,x))==mp.end()) mp[make_pair(r,x)]=w;
		else mp[make_pair(r,x)]=max(mp[make_pair(r,x)],w);
		x+=x&(-x);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		z[i]++;
	}
	sz=1<<17;
	for (int i=1;i<=m;i++)
	{
		dp[i]=query(x[i],z[i]-1)+1;
		ans=max(ans,dp[i]);
		update(y[i],z[i],dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
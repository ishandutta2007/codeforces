#include<bits/stdc++.h>
using namespace std;
int n,k,dp[444444][2][2],x,ans,a,b,c,d,wa,la,wc,lc,cr,w;
bool f[222222];
void dfs(int l,int r,int node)
{
	if (l+1==r)
	{
		if (f[l]|f[r])
		{
			dp[node][f[l]][f[r]]=dp[node][f[r]][f[l]]=1;
		}
		else
		{
			dp[node][f[l]][f[r]]=0;
		}
		return;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,node<<1);
	dfs(mid+1,r,(node<<1)|1);
	for (int i=0;i<128;i++)
	{
		a=(i&1);b=(i&2)>>1;c=(i&4)>>2;d=(i&8)>>3;
		cr=dp[node<<1][a][c]+dp[(node<<1)|1][b][d]+(a|b)+(c|d);
		if (i&16) 
		{
			wa=a;
			la=b;
		}
		else 
		{
			wa=b;
			la=a;
		}
		if (i&32)
		{
			wc=c;
			lc=d;
		}
		else
		{
			wc=d;
			lc=c;
		}
		if (la|wc) cr++;
		if (i&64) w=la;
		else w=wc;
		dp[node][wa][w]=max(dp[node][wa][w],cr);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&x);
		f[x]=1;
	}
	for (int i=0;i<(1<<(n+1));i++) 
	{
		dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=-1e9;
	}
	dfs(1,(1<<n),1);
	ans=max(dp[1][0][0],max(max(dp[1][1][1],dp[1][0][1]),dp[1][1][0])+1);
	printf("%d\n",ans);
	return 0;
}
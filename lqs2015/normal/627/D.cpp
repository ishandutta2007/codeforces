#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,sub,dp,rev;
	bool can;
}cur[222222];
vector<node> g[222222];
int n,K,a[222222],x,y,DP[222222],l,r,mid,cnt,id[222222];
struct xnode
{
	bool can;
	int sub,dp,mx;
}pre[222222],suf[222222];
void dfs(int i,int k)
{
	if (~k) 
	{
		g[i][k].sub=1;g[i][k].can=(a[i]>=mid);
	}
	int mx=0;
	for (int j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		dfs(g[i][j].to,g[i][j].rev);
		if (~k)
		{
			g[i][k].sub+=g[g[i][j].to][g[i][j].rev].sub;
			g[i][k].can&=g[g[i][j].to][g[i][j].rev].can;
			if (g[g[i][j].to][g[i][j].rev].can) g[i][k].dp+=g[g[i][j].to][g[i][j].rev].sub;
			else mx=max(mx,g[g[i][j].to][g[i][j].rev].dp);
		}
	}
	if (~k)
	{
	    g[i][k].dp+=(mx+1);
	    if (a[i]<mid) g[i][k].dp=0;
	}
}
void proc(int i,int k)
{
	cnt=0;
	for (int j=0;j<g[i].size();j++)
	{
		if (j!=k) 
		{
			cur[++cnt]=g[g[i][j].to][g[i][j].rev];
			id[cnt]=j;
		}
	}
	if (~k) 
	{
		cur[++cnt]=g[g[i][k].to][g[i][k].rev];
		id[cnt]=k;
	}
	pre[0].sub=pre[0].dp=pre[0].mx=0;pre[0].can=1;
	pre[cnt+1].sub=pre[cnt+1].dp=pre[cnt+1].mx=0;pre[cnt+1].can=1;
	suf[0].sub=suf[0].dp=suf[0].mx=0;suf[0].can=1;
	suf[cnt+1].sub=suf[cnt+1].dp=suf[cnt+1].mx=0;suf[cnt+1].can=1;
	for (int j=1;j<=cnt;j++)
	{
		pre[j].can=pre[j-1].can&cur[j].can;
		pre[j].sub=pre[j-1].sub+cur[j].sub;
		pre[j].dp=pre[j-1].dp+(cur[j].can ? cur[j].sub : 0);
		pre[j].mx=max(pre[j-1].mx,(cur[j].can ? 0 : cur[j].dp));
	}
	for (int j=cnt;j>=1;j--)
	{
		suf[j].can=suf[j+1].can&cur[j].can;
		suf[j].sub=suf[j+1].sub+cur[j].sub;
		suf[j].dp=suf[j+1].dp+(cur[j].can ? cur[j].sub : 0);
		suf[j].mx=max(suf[j+1].mx,(cur[j].can ? 0 : cur[j].dp));
	}
	for (int j=1;j<=cnt;j++)
	{
		g[i][id[j]].sub=1+pre[j-1].sub+suf[j+1].sub;
		g[i][id[j]].can=pre[j-1].can&suf[j+1].can&(a[i]>=mid);
		g[i][id[j]].dp=pre[j-1].dp+suf[j+1].dp+max(pre[j-1].mx,suf[j+1].mx)+1;
		if (a[i]<mid) g[i][id[j]].dp=0;
	}
	DP[i]=pre[cnt].dp+pre[cnt].mx+1;
	if (a[i]<mid) DP[i]=0;
	for (int j=0;j<g[i].size();j++)
	{
		if (j==k) continue;
		proc(g[i][j].to,g[i][j].rev);
	}
}
bool check()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<g[i].size();j++)
		{
			g[i][j].sub=g[i][j].dp=g[i][j].can=0;
		}
	}
	dfs(1,-1);
	proc(1,-1);
	/*if (mid==3)
	{
		for (int i=1;i<=n;i++) cout<<DP[i]<<" ";
		cout<<endl;
	}*/
	for (int i=1;i<=n;i++)
	{
		if (DP[i]>=K) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&K);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back((node){y,0,0,(int)g[y].size(),0});
		g[y].push_back((node){x,0,0,(int)g[x].size()-1,0});  
	}
	l=0;r=1e6;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if (check()) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,x,u,v,w,beg[555],en[555],sub[555],cnt,cur,d[555];
vector<pair<int,int> > g[555];
long long dist[555][555];
vector<short> dp[555][555];
short fuck[555][555],dick[555][555],ans,mn;
void upd(short &x,short y)
{
	if (x>y) x=y;
}
void dfs(int i,int fa,int rt)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa) continue;
		dist[rt][to]=dist[rt][i]+val;
		dfs(to,i,rt);
	}
}
void dft(int i,int fa)
{
	sub[i]=1;beg[i]=++cnt;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		dft(to,i);
		sub[i]+=sub[to];
	}
	en[i]=cnt;
}
void treedp(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		treedp(to,i);
	}
	for (int j=0;j<=sub[i];j++)
	{
		for (int k=1;k<=n;k++)
		fuck[k][j]=10000;
	}
	for (int j=1;j<=n;j++)
	{
		if (dist[i][j]<=x)
		{
			if (!d[i])
			{
				if (i!=j) fuck[j][0]=0;
				else fuck[j][1]=1;
			}
			else
			{
				if (i!=j) fuck[j][0]=1;
				else fuck[j][1]=0;
			}
		}
	}
	cur=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first;
		if (to==fa) continue;
		for (int k=0;k<=cur+sub[to];k++)
		{
			for (int h=1;h<=n;h++) 
			dick[h][k]=10000;
		}
		for (int k=0;k<=cur;k++)
		{
			for (int h=0;h<=sub[to];h++)
			{
				short mn=1e4;
				for (int p=1;p<=n;p++)
				{
					if (dist[p][i]<=x) 
					{
						upd(dick[p][k+h],fuck[p][k]+dp[to][p][h]);
					}
					if (beg[p]>=beg[to] && beg[p]<=en[to]) 
					{
						upd(mn,dp[to][p][h]);
					}
				}
				for (int p=1;p<=n;p++)
				{
					if (!(beg[p]>=beg[to] && beg[p]<=en[to]) && dist[p][i]<=x) 
					{
						upd(dick[p][k+h],fuck[p][k]+mn);
					}
				}
			}
		}
		cur+=sub[to];
		for (int k=0;k<=cur;k++)
		{
			for (int h=1;h<=n;h++)
			{
				fuck[h][k]=dick[h][k];
			}
		}
	}
	for (int j=1;j<=n;j++)
	{
		for (int k=0;k<=cur;k++)
		{
			dp[i][j][k]=fuck[j][k];
		}
	}
}
int main()
{
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&d[i]);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	for (int i=1;i<=n;i++)
	{
		dfs(i,0,i);
	}
	dft(1,0);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			dp[i][j].resize(sub[i]+1);
		}
	}
	treedp(1,0);
	cnt=0;
	for (int i=1;i<=n;i++) cnt+=d[i];
	mn=10000;
	for (int i=1;i<=n;i++)
	{
		upd(mn,dp[1][i][cnt]);
	}
	if (mn>2000) printf("-1\n");
	else printf("%d\n",(int)mn/2);
	return 0;
}
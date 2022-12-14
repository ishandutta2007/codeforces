#include<bits/stdc++.h>
using namespace std;
long long n,w[333333],x,y,w1,w2,tree[2222222],an[333333][22],ct,dep[333333],deep1[333333],deep2[333333],beg[333333],en[333333],a[333333];
vector<pair<long long,pair<long long,long long> > > g[333333];
long long dist[333333],lazy[2222222],f[333333][22][2][2],dp[2][2],q,xp,yp;
void dfs(long long i,long long fa)
{
	an[i][0]=fa;
	for (long long j=1;j<=18;j++) an[i][j]=an[an[i][j-1]][j-1];
	dep[i]=dep[fa]+1;
	beg[i]=++ct;
	dist[i]=w[i];
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,val1=g[i][j].second.first,val2=g[i][j].second.second;
		if (to==fa) continue;
		deep1[to]=deep1[i]+val1;deep2[to]=deep2[i]+val2;
		dfs(to,i);
		dist[i]=min(dist[i],dist[to]+val1+val2);
	}
	en[i]=ct;
}
void dft(int i,int fa)
{
	for (int j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,w1=g[i][j].second.first,w2=g[i][j].second.second;
		if (to==fa) continue;
		dist[to]=min(dist[to],dist[i]+w1+w2);
		dft(to,i);
	}
}
void pre(long long i,long long fa,long long w0,long long w1)
{
	f[i][0][0][0]=w0;f[i][0][1][1]=w1;f[i][0][0][1]=min(w0+dist[an[i][0]],w1+dist[i]);
	f[i][0][1][0]=min(w0+dist[i],w1+dist[an[i][0]]);
	for (long long j=1;j<=18;j++)
	{
		f[i][j][0][0]=min(f[i][j-1][0][1]+f[an[i][j-1]][j-1][1][0],f[i][j-1][0][0]+f[an[i][j-1]][j-1][0][0]);
		f[i][j][0][1]=min(f[i][j-1][0][1]+f[an[i][j-1]][j-1][1][1],f[i][j-1][0][0]+f[an[i][j-1]][j-1][0][1]);
		f[i][j][1][0]=min(f[i][j-1][1][1]+f[an[i][j-1]][j-1][1][0],f[i][j-1][1][0]+f[an[i][j-1]][j-1][0][0]);
		f[i][j][1][1]=min(f[i][j-1][1][1]+f[an[i][j-1]][j-1][1][1],f[i][j-1][1][0]+f[an[i][j-1]][j-1][0][1]);
	}
	for (long long j=0;j<g[i].size();j++)
	{
		long long to=g[i][j].first,W1=g[i][j].second.first,W2=g[i][j].second.second;
		if (to==fa) continue;
		pre(to,i,W1,W2);
	}
}
void go(long long i,long long f[2][2])
{
	long long g[2][2];
	g[i][0]=min(dp[i][0]+f[0][0],dp[i][1]+f[1][0]);
	g[i][1]=min(dp[i][0]+f[0][1],dp[i][1]+f[1][1]);
	dp[i][0]=g[i][0];dp[i][1]=g[i][1];
}
int main()
{
	scanf("%lld",&n);
	for (long long i=1;i<=n;i++) scanf("%lld",&w[i]);
	for (long long i=1;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x,&y,&w1,&w2);
		g[x].push_back(make_pair(y,make_pair(w1,w2)));
		g[y].push_back(make_pair(x,make_pair(w1,w2)));  
	}
	dfs(1,0);
	dft(1,0);
	pre(1,0,0,0);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld",&x,&y);
		if (dep[(x+1)/2]<dep[(y+1)/2]) swap(x,y);
		if (x&1)
		{
			xp=(x+1)/2;
			dp[0][0]=0;dp[0][1]=dist[xp];
		}
		else
		{
			xp=(x+1)/2;
			dp[0][0]=dist[xp];dp[0][1]=0;
		}
		if (y&1)
		{
			yp=(y+1)/2;
			dp[1][0]=0;dp[1][1]=dist[yp];
		}
		else
		{
			yp=(y+1)/2;
			dp[1][0]=dist[yp];dp[1][1]=0;
		}
		for (long long i=18;i>=0;i--)
		{
			if (dep[an[xp][i]]>=dep[yp])
			{
				go(0,f[xp][i]);
				xp=an[xp][i];
			}
		}
		for (long long i=18;i>=0;i--)
		{
			if (an[xp][i]!=an[yp][i])
			{
				go(0,f[xp][i]);
				go(1,f[yp][i]);
				xp=an[xp][i];
				yp=an[yp][i];
			}
		}
		if (xp!=yp)
		{
			go(0,f[xp][0]);
			go(1,f[yp][0]);
		}
		
		printf("%lld\n",min(dp[0][0]+dp[1][0],dp[0][1]+dp[1][1]));
	}
	return 0;
}
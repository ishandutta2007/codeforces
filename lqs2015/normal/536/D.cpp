//why I use segtree!!!!I'm really sb!!!!
#include<bits/stdc++.h>
using namespace std;
long long sum[2222][2222],P[2222][2222],dist[2222],sufa[4444][2222],sufb[2222][4444],dp[2222][2222][2];
int n,m,s,t,p[2222],A[2222][2222],a[2222],b[2222],x,y,z,pre,pos,cnta,cntb;
int l,r,mid;
vector<pair<int,int> > g[2222];
int orz[2222][2222];
pair<long long,int> c[2222];
void dijk(int s)
{
	priority_queue<pair<long long,int> > pq;
	for (int i=1;i<=n;i++) dist[i]=1e18;
	dist[s]=0;
	pq.push(make_pair(0,s));
	while(!pq.empty())
	{
		int x=pq.top().second;long long y=-pq.top().first;pq.pop();
		if (dist[x]!=y) continue;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	}
}
int main()
{
//	freopen("data.in","r",stdin);
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for (int i=1;i<=n;i++) scanf("%d",&p[i]);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	dijk(s);
	for (int i=1;i<=n;i++) c[i]=make_pair(dist[i],i);
	sort(c+1,c+n+1);
	pos=1;
	while(pos<=n)
	{
		pre=pos;
		while(pos<=n && c[pre].first==c[pos].first) pos++;
		cnta++;
		for (int i=pre;i<pos;i++) 
		{
			a[c[i].second]=cnta;
		}
	}
	dijk(t);
	for (int i=1;i<=n;i++) c[i]=make_pair(dist[i],i);
	sort(c+1,c+n+1);
	pos=1;
	while(pos<=n)
	{
		pre=pos;
		while(pos<=n && c[pre].first==c[pos].first) pos++;
		cntb++;
		for (int i=pre;i<pos;i++) 
		{
			b[c[i].second]=cntb;
		}
	}
	for (int i=1;i<=n;i++)
	{
		P[a[i]][b[i]]+=p[i];
		orz[a[i]][b[i]]++;
	}
	for (int i=1;i<=cnta;i++)
	{
		for (int j=1;j<=cntb;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+P[i][j];
			A[i][j]=(A[i-1][j]+A[i][j-1]-A[i-1][j-1]+orz[i][j]);
		}
	}
	for (int i=0;i<=n+1;i++)
	{
		for (int j=0;j<=n+1;j++)
		{
			sufa[i][j]=-1e18;
			sufb[i][j]=1e18;
		}
	}
	for (int i=0;i<=cnta;i++)
	{
		for (int j=0;j<=cntb;j++)
		{
			if (A[cnta][cntb]-A[cnta][j]-A[i][cntb]+A[i][j]==0) 
			{
				dp[i][j][0]=dp[i][j][1]=0;
				if (i) sufa[i][j]=max(sufa[i+1][j],dp[i][j][1]+sum[i][cntb]-sum[i][j]);
				if (j) sufb[i][j]=min(sufb[i][j+1],dp[i][j][0]-sum[cnta][j]+sum[i][j]);
			}
		}
	}
	for (int i=cnta;i>=0;i--)
	{
		for (int j=cntb;j>=0;j--)
		{
			int cur=A[cnta][cntb]-A[i][cntb]-A[cnta][j]+A[i][j];
			if (!cur) continue;
			l=i+1,r=cnta;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (A[mid][cntb]-A[mid][j]-A[i][cntb]+A[i][j]>0) r=mid-1;
				else l=mid+1;
			}
			dp[i][j][0]=sufa[l][j]-sum[i][cntb]+sum[i][j];
			l=j+1,r=cntb;
			while(l<=r)
			{
				mid=(l+r)>>1;
				if (A[cnta][mid]-A[i][mid]-A[cnta][j]+A[i][j]>0) r=mid-1;
				else l=mid+1;
			}
			dp[i][j][1]=sufb[i][l]+sum[cnta][j]-sum[i][j];
			if (i) sufa[i][j]=max(sufa[i+1][j],dp[i][j][1]+sum[i][cntb]-sum[i][j]);
			if (j) sufb[i][j]=min(sufb[i][j+1],dp[i][j][0]-sum[cnta][j]+sum[i][j]);
		}
	}
	if (dp[0][0][0]<0) printf("Cry\n");
	else if (dp[0][0][0]>0) printf("Break a heart\n");
	else printf("Flowers\n");
	return 0;
}
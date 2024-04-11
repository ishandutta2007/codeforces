#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int dist[111111],n,k,x,y,z,r,ans,pre[111111],sum[111111],cnt,mx,id[111111],pp,len,mxlen[111111];
vector<pair<int,int> > g[111111];
multiset<int> s;
int bfs(int s)
{
	queue<int> q;
	q.push(s);
	for (int i=1;i<=n;i++)
	{
		dist[i]=1e9;
		pre[i]=-1;
	} 
	dist[s]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i].first,val=g[x][i].second;
			if (dist[to]>dist[x]+val)
			{
				dist[to]=dist[x]+val;
				pre[to]=x;
				q.push(to); 
			}
		}
	}
	int mxi=1;
	for (int i=2;i<=n;i++)
	{
		if (dist[i]>dist[mxi]) mxi=i;
	}
	return mxi;
}
void dfs(int i,int fa,int len)
{
	mx=max(mx,len);
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j].first,val=g[i][j].second;
		if (to==fa || val==-1) continue;
		dfs(to,i,len+val); 
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	x=bfs(1);
	y=bfs(x);
	len=dist[y];
	for (int i=y;i!=x;i=pre[i])
	{
		id[++cnt]=i;
		sum[cnt]=sum[cnt-1]+pp;
		for (int j=0;j<g[pre[i]].size();j++)
		{
			if (g[pre[i]][j].first==i) 
			{
				pp=g[pre[i]][j].second;
				g[pre[i]][j].second=-1;
			}
		}
		for (int j=0;j<g[i].size();j++)
		{
			if (g[i][j].first==pre[i]) g[i][j].second=-1;
		}
	}
	id[++cnt]=x;
	sum[cnt]=sum[cnt-1]+pp;
	for (int i=y;i!=x;i=pre[i])
	{
		mx=0;
		dfs(i,0,0);
		mxlen[i]=mx;
	}
	for (int i=1;i<=k && i<=cnt;i++)
	{
		s.insert(mxlen[id[i]]); 
	}
	ans=2e9;
	for (int i=1;i<=cnt;i++)
	{
		r=min(cnt,i+k-1);
		ans=min(ans,max(max(*s.rbegin(),sum[i]),len-sum[r]));
		s.erase(s.find(mxlen[id[i]]));
		if (i+k<=cnt) s.insert(mxlen[id[i+k]]);
	}
	printf("%d\n",ans);
	return 0;
}
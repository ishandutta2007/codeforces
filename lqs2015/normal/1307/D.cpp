#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,k,a[222222],x,y,dist[222222],mx,d2[222222],cm,ps,l,r;
bool can[222222];
vector<int> g[222222],ng[222222];
pair<int,int> b[222222],c[222222];
int mx1,mx2,id1,id2;
bool flag;
void bfs()
{
	memset(dist,-1,sizeof(dist));
	dist[1]=0;
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!~dist[to])
			{
				dist[to]=dist[x]+1;
				q.push(to);
				ng[x].push_back(to);
				ng[to].push_back(x);
			}
		}
	}
}
void bfs2()
{
	memset(d2,-1,sizeof(d2));
	d2[n]=0;
	queue<int> q;
	q.push(n);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i];
			if (!~d2[to])
			{
				d2[to]=d2[x]+1;
				q.push(to);
				ng[x].push_back(to);
				ng[to].push_back(x);
			}
		}
	}
}
void add(int x)
{
	if (dist[c[x].second]>mx1)
	{
		mx2=mx1;id2=id1;
		mx1=dist[c[x].second];id1=c[x].second;
	}
	else if (dist[c[x].second]>mx2)
	{
		mx2=dist[c[x].second];id2=c[x].second;
	}
}
bool check(int mid)
{
	ps=k;mx1=mx2=-1e9;id1=id2=-1;mx=0;
	for (int i=1;i<=k;i++)
	{
		while(ps>=1 && c[ps].first+1+b[i].first>=mid) 
		{
			add(ps);
			ps--;
		} 
		if (id1==b[i].second) 
		{
			mx=max(mx,mx2+1+d2[b[i].second]);
		}
		else
		{
			mx=max(mx1+1+d2[b[i].second],mx);
		}
	}
	return (mx>=mid);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		scanf("%d",&a[i]);
		can[a[i]]=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	bfs();
	for (int i=1;i<=k;i++)
	{
		b[i]=make_pair(dist[a[i]],a[i]);
	}
	sort(b+1,b+k+1);
	mx=-1e9;
	bfs2();
	for (int i=1;i<=k;i++) c[i]=make_pair(d2[a[i]],a[i]);
	sort(c+1,c+k+1);
	l=1;r=dist[n];
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return Accepted;
}
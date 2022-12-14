#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct number
{
	int a,b;//2^a+b
	bool operator > (const number &u) const
	{
		if (a>22 || u.a>22)
		{
			if (a!=u.a) return a<u.a;
			return b<u.b;
		}
		return ((1<<a)+b<(1<<u.a)+u.b);
	}
	bool operator < (const number &u) const
	{
		if (a>22 || u.a>22)
		{
			if (a!=u.a) return a>u.a;
			return b>u.b;
		}
		return ((1<<a)+b>(1<<u.a)+u.b);
	}
}dist[222222][25][2],c,nw;
priority_queue<pair<pair<number,int>,pair<int,int> > > q;
int n,m,x,y,ans,d;
vector<int> g[2][222222];
pair<pair<number,int>,pair<int,int> > cur;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[0][x].push_back(y);
		g[1][y].push_back(x);
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=20;j++)
		{
			dist[i][j][0].a=dist[i][j][1].a=1e9;
			dist[i][j][0].b=dist[i][j][1].b=0;
		}
	}
	dist[1][0][0].a=0;dist[1][0][0].b=0;
	q.push(make_pair(make_pair(dist[1][0][0],0),make_pair(1,0)));
	while(!q.empty())
	{
		cur=q.top();q.pop();
		x=cur.second.first;y=cur.second.second;c=cur.first.first;d=cur.first.second;
		if (dist[x][d][y]>c || c>dist[x][d][y]) continue;
		nw=c;nw.a++;
		if (dist[x][min(d+1,20)][!y]<nw)
		{
			dist[x][min(d+1,20)][!y]=nw;
			q.push(make_pair(make_pair(dist[x][min(d+1,20)][!y],min(d+1,20)),make_pair(x,!y)));
		}
		for (int i=0;i<g[y][x].size();i++)
		{
			int to=g[y][x][i];
			nw=c;nw.b++;
			if (dist[to][d][y]<nw)
			{
				dist[to][d][y]=nw;
				q.push(make_pair(make_pair(dist[to][d][y],d),make_pair(to,y)));
			}
		}
	}
	nw.a=1e9;
	for (int i=0;i<=20;i++)
	{
		if (nw<dist[n][i][0]) nw=dist[n][i][0];
		if (nw<dist[n][i][1]) nw=dist[n][i][1];
	}
	ans=1;
	for (int i=1;i<=nw.a;i++) ans=(ans+ans)%mod;
	ans=(ans+nw.b)%mod;ans=(ans+mod-1)%mod;
	printf("%d\n",ans);
	return 0;
}
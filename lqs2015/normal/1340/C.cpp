#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int inf=1500000000;
int test,n,m,d[11111],g,r,dist[11111][1111],cur,cnt,x,y,c,ans;
struct item
{
	int x,d;
	bool operator < (const item &u) const
	{
		return d>u.d;
	}
}nw;
priority_queue<item> pq;
void dijk()
{
	for (int i=1;i<=m;i++)
	{
		for (int j=0;j<=g;j++)
		{
			dist[i][j]=2e9;
		}
	}
	dist[1][g]=0;
	pq.push((item){g+1+g,0});
	while(!pq.empty())
	{
		nw=pq.top();pq.pop();
		x=nw.x/(g+1);y=nw.x%(g+1);
		if (dist[x][y]!=nw.d) continue;
		c=d[x+1]-d[x];
		if (x<m && y>=c)
		{
			if (dist[x+1][y-c]>dist[x][y]+c)
			{
				dist[x+1][y-c]=dist[x][y]+c;
				pq.push((item){(x+1)*(g+1)+y-c,dist[x][y]+c});
			}
		}
		c=d[x]-d[x-1];
		if (x>1 && y>=c)
		{
			if (dist[x-1][y-c]>dist[x][y]+c)
			{
				dist[x-1][y-c]=dist[x][y]+c;
				pq.push((item){(x-1)*(g+1)+y-c,dist[x][y]+c});
			}
		}
		if (!y)
		{
			if (dist[x][g]>dist[x][y]+r)
			{
				dist[x][g]=dist[x][y]+r;
				pq.push((item){x*(g+1)+g,dist[x][y]+r});
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d",&d[i]);
	sort(d+1,d+m+1);
	m=unique(d+1,d+m+1)-d-1;
	scanf("%d%d",&g,&r);
	dijk();ans=2e9;
	for (int i=0;i<=g;i++)
	{
		ans=min(ans,dist[m][i]);
	}
	if (ans>inf) printf("-1\n");
	else printf("%d\n",ans);
	return Accepted;
}
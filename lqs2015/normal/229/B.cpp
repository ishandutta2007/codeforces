#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,m,dist[111111],x,y,z,pos,pre;
vector<pair<int,int> > g[111111],gg[111111];
vector<int> t[111111];
priority_queue<pair<int,int> > pq;
int process(int x,int tim)
{
	int cur=lower_bound(gg[x].begin(),gg[x].end(),make_pair(tim,0))-gg[x].begin();
	if (cur>=gg[x].size()) return tim;
	if (gg[x][cur].first==tim) return gg[x][cur].second;
	return tim;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));  
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			t[i].push_back(y); 
		}
		pos=0;
		while(pos<x)
		{
			pre=pos;
			pos++;
			while(pos<x && t[i][pos]-t[i][pos-1]==1) pos++;
			for (int j=pre;j<pos;j++)
			{
				gg[i].push_back(make_pair(t[i][j],t[i][pos-1]+1)); 
			}
		}
	}
	for (int i=1;i<=n;i++) dist[i]=2e9;
	dist[1]=0;
	pq.push(make_pair(-dist[1],1));
	while(!pq.empty())
	{
		int x=pq.top().second,y=pq.top().first;pq.pop();
		if (dist[x]!=-y) continue;
		for (int i=0;i<g[x].size();i++)
		{
			int to=g[x][i].first,val=g[x][i].second;
			int cur=process(x,dist[x])+val;
			if (dist[to]>cur)
			{
				dist[to]=cur;
				pq.push(make_pair(-dist[to],to)); 
			}
		}
	} 
	if (dist[n]>=2e9) printf("-1\n");
	else printf("%d\n",dist[n]);
}
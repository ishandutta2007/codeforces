#include <bits/stdc++.h>
using namespace std;
bool off[2005];
int n,m,k,q;
vector<pair<int,int> > g[2005],v[2005];
pair<int,int> inv[2005][2005];
long long cum[2005][2005];
char t[8];
long long f(int x,int y)
{
	for (int i=1;i<=k;i++)
	v[i].clear();
	for (int i=1;i<=y;i++)
	{
		if (inv[x][i].first)
		v[inv[x][i].first].push_back({inv[x][i].second,1});
	}
	for (int i=1;i<x;i++)
	{
		if (inv[i][y].first)
		v[inv[i][y].first].push_back({inv[i][y].second,1});
	}
	for (int i=1;i<=y+1;i++)
	{
		if (inv[x+1][i].first)
		v[inv[x+1][i].first].push_back({inv[x+1][i].second,0});
	}
	for (int i=1;i<=x;i++)
	{
		if (inv[i][y+1].first)
		v[inv[i][y+1].first].push_back({inv[i][y+1].second,0});
	}
	long long ret=0;
	for (int i=1;i<=k;i++)
	{
		if (off[i])
		continue;
		sort(v[i].begin(),v[i].end());
		v[i].push_back({g[i].size()+1,0});
		int cur=1;
		bool s=(g[i][0].first<=x && g[i][0].second<=y);
		for (auto p:v[i])
		{
			if (s)
			ret+=cum[i][p.first-1]-cum[i][cur-1];
			cur=p.first;
			s=p.second;
		}
	}
	return ret;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++)
	{
		int l;
		scanf("%d",&l);
		for (int j=1;j<=l;j++)
		{
			int x,y,w;
			scanf("%d%d%d",&x,&y,&w);
			cum[i][j]=cum[i][j-1]+w;
			g[i].push_back({x,y});
			inv[x][y]={i,j};
		}
	}
	scanf("%d",&q);
	while (q--)
	{
		scanf(" %s",t);
		if (t[0]=='S')
		{
			int i;
			scanf("%d",&i);
			off[i]^=1;
		}
		else
		{
			int x1,x2,y1,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%I64d\n",f(x2,y2)-f(x1-1,y2)-f(x2,y1-1)+f(x1-1,y1-1));
		}
	}
}
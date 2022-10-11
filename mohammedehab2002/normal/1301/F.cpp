#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > d[45];
int arr[1005][1005],dist[45][1005][1005];
bool c[45][45];
int main()
{
	int n,m,k,q;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&arr[i][j]);
			d[arr[i][j]].push_back({i,j});
		}
	}
	memset(dist,-1,sizeof(dist));
	for (int i=1;i<=k;i++)
	{
		queue<pair<int,int> > q;
		for (auto p:d[i])
		{
			q.push(p);
			dist[i][p.first][p.second]=0;
		}
		while (!q.empty())
		{
			auto p=q.front();
			q.pop();
			int x=p.first,y=p.second;
			if (!c[i][arr[x][y]])
			{
				for (auto np:d[arr[x][y]])
				{
					if (dist[i][np.first][np.second]==-1)
					{
						dist[i][np.first][np.second]=dist[i][x][y]+1;
						q.push(np);
					}
				}
				c[i][arr[x][y]]=1;
			}
			for (int dx=-1;dx<=1;dx++)
			{
				for (int dy=-1;dy<=1;dy++)
				{
					if (abs(dx)+abs(dy)==1 && x+dx && x+dx<=n && y+dy && y+dy<=m && dist[i][x+dx][y+dy]==-1)
					{
						dist[i][x+dx][y+dy]=dist[i][x][y]+1;
						q.push({x+dx,y+dy});
					}
				}
			}
		}
	}
	k*=2;
	scanf("%d",&q);
	while (q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=abs(x1-x2)+abs(y1-y2);
		for (int x=max(x1-k,1);x<=min(x1+k,n);x++)
		{
			for (int y=max(y1-(k-abs(x1-x)),1);y<=min(y1+(k-abs(x1-x)),m);y++)
			ans=min(ans,abs(x1-x)+abs(y1-y)+dist[arr[x][y]][x2][y2]+1);
		}
		printf("%d\n",ans);
	}
}
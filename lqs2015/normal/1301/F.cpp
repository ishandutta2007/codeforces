#include<bits/stdc++.h>
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int n,m,k,col[1111][1111],dist[44][1111][1111],d[1111][1111],x,y,z,dd[44][44],res;
int ax,ay,bx,by,q;
bool In(int x,int y)
{
	return (x>=1 && x<=n && y>=1 && y<=m);
}
void bfs(int c)
{
	memset(d,-1,sizeof(d));
	queue<pair<int,int> > q;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (col[i][j]==c) 
			{
				d[i][j]=0;
				q.push(make_pair(i,j));
			}
		}
	}
	while(!q.empty())
	{
		x=q.front().first;y=q.front().second;
		q.pop();
		for (int j=0;j<4;j++)
		{
			int xx=x+dx[j],yy=y+dy[j];
			if (!In(xx,yy) || ~d[xx][yy]) continue;
			d[xx][yy]=d[x][y]+1;
			q.push(make_pair(xx,yy));
		}
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dist[c][i][j]=d[i][j];
			dd[c][col[i][j]]=min(dd[c][col[i][j]],d[i][j]+1);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%d",&col[i][j]);
		}
	}
	for (int i=1;i<=k;i++)
	{
		for (int j=1;j<=k;j++)
		{
			if (i==j) dd[i][j]=0;
			else dd[i][j]=1e8;
		}
	}
	for (int i=1;i<=k;i++) 
	{
		bfs(i);
	}
	for (int h=1;h<=k;h++)
	{
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=k;j++)
			{
				dd[i][j]=min(dd[i][j],dd[i][h]+dd[h][j]);
			}
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&ax,&ay,&bx,&by);
		res=abs(ax-bx)+abs(ay-by);
		for (int i=1;i<=k;i++)
		{
			for (int j=1;j<=k;j++)
			{
				res=min(res,dist[i][ax][ay]+dist[j][bx][by]+dd[i][j]+1);
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
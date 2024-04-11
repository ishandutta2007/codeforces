#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
int test,n,m,Q,dist[1111][1111],sz[2222222],pa[2222222],x,y,cur;
char s[1111][1111];
long long z;
deque<pair<int,int> > q;
bool flg;
int root(int x)
{
	if (pa[x]!=x) pa[x]=root(pa[x]);
	return pa[x];
}
void Union(int x,int y)
{
	int rx=root(x),ry=root(y);
	if (rx==ry) return;
	pa[rx]=ry;sz[ry]+=sz[rx];
}
bool In(int x,int y)
{
	return (x>=0 && x<n && y>=0 && y<m);
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for (int i=0;i<n;i++)
	{
		scanf("%s",s[i]);
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			pa[i*m+j]=i*m+j;
			sz[i*m+j]=1;
		}
	}
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<m;j++)
		{
			for (int k=0;k<4;k++)
			{
				int xx=i+dx[k],yy=j+dy[k];
				if (!In(xx,yy)) continue;
				if (s[i][j]==s[xx][yy]) Union(i*m+j,xx*m+yy);
			}
		}
	}
	for (int i=0;i<n*m;i++)
	{
		if (sz[i]>1)
		{
			flg=1;
			break;
		}
	}
	if (!flg)
	{
		while(Q--)
		{
			scanf("%d%d%lld",&x,&y,&z);
			printf("%d\n",s[x-1][y-1]-'0');
		}
	}
	else
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<m;j++)
			{
				dist[i][j]=1e9;
				if (sz[root(i*m+j)]>1)
				{
					dist[i][j]=0;
					q.push_back(make_pair(i,j));
				}
			}
		}
		while(!q.empty())
		{
			x=q.front().first;y=q.front().second;q.pop_front();
			for (int i=0;i<4;i++)
			{
				int xx=x+dx[i],yy=y+dy[i];
				if (!In(xx,yy)) continue;
				if (s[x][y]==s[xx][yy])
				{
					if (dist[xx][yy]>dist[x][y])
					{
						dist[xx][yy]=dist[x][y];
						q.push_front(make_pair(xx,yy));
					}
				}
				else
				{
					if (dist[xx][yy]>dist[x][y]+1)
					{
						dist[xx][yy]=dist[x][y]+1;
						q.push_back(make_pair(xx,yy));
					}
				}
			}
		}
		while(Q--)
		{
			scanf("%d%d%lld",&x,&y,&z);
			x--;y--;
			cur=s[x][y]-'0';
			if (z<=dist[x][y]) printf("%d\n",cur);
			else 
			{
				cur^=((z-dist[x][y])&1);
				printf("%d\n",cur);
			}
		}
	}
	return Accepted;
}
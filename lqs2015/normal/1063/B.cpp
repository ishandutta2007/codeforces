#include<bits/stdc++.h>
using namespace std;
int n,m,r,c,x,y,mp[2222][2222],dist[2222][2222],cur,ans;
char s[11111];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
void bfs(int x,int y)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		dist[i][j]=-1;
	}
	dist[x][y]=0;
	deque<pair<int,int> > q;
	q.push_back(make_pair(x,y));
	int curx,cury;
	while(!q.empty())
	{
		curx=q.front().first;cury=q.front().second;q.pop_front();
		for (int i=0;i<4;i++)
		{
			int xxx=dx[i]+curx,yyy=dy[i]+cury;
			if (xxx<1 || xxx>n || yyy<1 || yyy>m || !mp[xxx][yyy]) continue;
			if (i==2) cur=dist[curx][cury]+1;
			else cur=dist[curx][cury];
			if (!~dist[xxx][yyy] || dist[xxx][yyy]>cur)
			{
				dist[xxx][yyy]=cur;
				if (dist[xxx][yyy]==dist[curx][cury]) q.push_front(make_pair(xxx,yyy)); 
				else q.push_back(make_pair(xxx,yyy)); 
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for (int j=0;j<m;j++)
		{
			if (s[j]=='.') mp[i][j+1]=1;
		}
	}
	bfs(r,c);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (!~dist[i][j]) continue;
			if (dist[i][j]>x) continue;
			if (j<c) 
			{
				if (dist[i][j]-c+j<=y) ans++;
 			}
			else
			{
				if (dist[i][j]-c+j<=y) ans++;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
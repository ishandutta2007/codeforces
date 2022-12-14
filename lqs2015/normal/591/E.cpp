#include<iostream>
#include<queue>
#include<cstring>
#define pnt pair<int,int>
#define mp make_pair 
using namespace std;
const int Inf=1e8;
deque<pnt> q;
int n,m,ans,cur;
char a[1111][1111];
int dist[4][1111][1111];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool notable(int x,int y)
{
	return !(x>=1 && x<=n && y>=1 && y<=m && a[x][y]!='#');
}
void bfs(int t)
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			if (a[i][j]=='0'+t)
			{
				q.push_front(mp(i,j));
				dist[t][i][j]=0; 
			}
		}
	}
	int cost;
	while(!q.empty())
	{
		pnt x=q.front();
		q.pop_front();
		for (int i=0;i<4;i++)
		{
			int xx=x.first+dx[i];
			int yy=x.second+dy[i];
			if (notable(xx,yy)) continue;
			if (dist[t][xx][yy]!=Inf) continue;
			cost=(a[xx][yy]=='.');
			dist[t][xx][yy]=dist[t][x.first][x.second]+cost;
			if (cost) q.push_back(mp(xx,yy));
			else q.push_front(mp(xx,yy));   
		}
	}
}
int main()
{
	cin>>n>>m;
	ans=Inf;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		cin>>a[i][j];
	}
	for (int i=1;i<=3;i++)
	{
		for (int j=1;j<=n;j++)
		{
			for (int k=1;k<=m;k++)
			dist[i][j][k]=Inf;
		}
	}
	for (int i=1;i<=3;i++) bfs(i);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			cur=dist[1][i][j]+dist[2][i][j]+dist[3][i][j];
			if (a[i][j]=='.') cur-=2;
			ans=min(ans,cur);
		}
	}
	if (ans==Inf) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}
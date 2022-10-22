//codeforces 590C
#include <iostream>
#include <deque>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=100000000;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
void bfs(int);
char a[1005][1005];
int co[1005][1005];
int n,m;
int visit[3][1005][1005];

void print()
{
	for(int k=0;k<3;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<visit[k][i][j]<<"  ";
			}
			cout<<endl;
		}
		cout<<endl<<endl<<endl;
	}
}

void bfs(int t)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			visit[t][i][j]=inf;
		}
	}
	deque <pair<int,int> >que;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='1'+t)
			{
				que.push_back(make_pair<int,int>(i,j));
				visit[t][i][j]=0;
			}
		}
		while(!que.empty())
		{
			int x=que.front().first;
			int y=que.front().second;
			que.pop_front();
			for(int i=0;i<4;i++)
			{
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(nx<0 || ny<0 || nx>=n || ny>=m)
				{
					continue;
				}
				if(a[nx][ny]=='#' || visit[t][nx][ny]!=inf)
				{
					continue;
				}
				int $=(a[nx][ny]=='.');
				visit[t][nx][ny]=visit[t][x][y]+$;
				if($) que.push_back(make_pair<int,int>(nx,ny));else que.push_front(make_pair<int,int>(nx,ny));
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	string c;
	for(int i=0;i<n;i++)
	{
		cin>>c;
		for(int j=0;j<m;j++)
		{
			a[i][j]=c.at(j);
		}
	}
	for(int i=0;i<3;i++)
	{
		bfs(i);
	}
	int s=inf;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int ss=visit[0][i][j]+visit[1][i][j]+visit[2][i][j];
			if(a[i][j]=='.') ss-=2;
			s=min(s,ss);
//			if(ss>s)
//			{
//				cout<<i<<"  "<<j<<"   "<<s<<endl;
//			}
		}
	}
//	print();
	if(s>=inf) cout<<-1<<endl;else cout<<s<<endl;
	return 0;
}
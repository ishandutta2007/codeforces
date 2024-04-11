#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int n,m;
char map[55][55];
bool visit[55][55],use[55][55];

bool in(int x,int y)
{
	return (x>-1 && y>-1 && x<n && y<m);
}

void dfs(int x,int y,int px,int py,char *c)
{
	visit[x][y]=true;
	use[x][y]=true;
	rep(4)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(in(nx,ny))
		{
			if(map[nx][ny]==c[0])
			{
				if(nx==px && ny==py) continue;
				if(use[nx][ny])
				{
					cout<<"Yes"<<endl;
					exit(0);
				}
				else
				{
					if(!visit[nx][ny])
					{
						dfs(nx,ny,x,y,c);
					}
				}
			}
		}
	}
	use[x][y]=false;
}

int main()
{
	cin>>n>>m;
	rep(n)
	{
		scanf("%s",map[i]);
	}
	rep(n)
	{
		repj(m)
		{
			if(!visit[i][j])
			{
				dfs(i,j,-1,-1,&map[i][j]);
			}
		}
	}
	cout<<"No"<<endl; 
	return 0;
}
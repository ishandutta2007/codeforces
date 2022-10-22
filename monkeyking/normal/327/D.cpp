#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <set>
#include <string>
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define For(I,N) for(int I=0;I<N;I++)
typedef unsigned long long ull;
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int vec[3][1000000],s=0;
int n,m;
char map[505][505];
bool visit[505][505];

bool in(int x,int y)
{
	return (x>-1 && y>-1 && x<n && y<m);
}

void dfs(int x,int y,bool f)
{
//	cout<<x<<' '<<y<<endl;
//	string s="B "+change(x,y);
	vec[0][s]=0;
	vec[1][s]=x+1;
	vec[2][s]=y+1;
	s++;
	visit[x][y]=true;
	rep(4)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(in(nx,ny))
		{
			if(!visit[nx][ny] && map[nx][ny]=='.')
			{
				dfs(nx,ny,0);
			}
		}
	}
	if(!f)
	{
		vec[0][s]=2;
		vec[1][s]=x+1;
		vec[2][s]=y+1;
		s++;
		vec[0][s]=1;
		vec[1][s]=x+1;
		vec[2][s]=y+1;
		s++;
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	rep(n)
	{
		scanf("%s",map[i]);
	}
	rep(n)
	{
		repj(m)
		{
			if(!visit[i][j] && map[i][j]=='.')
			{
				dfs(i,j,1);
			}
		}
	}
	cout<<s<<endl;
	rep(s)
	{
		if(vec[0][i]==0)
		{
			printf("B ");
		}
		else if(vec[0][i]==1)
		{
			printf("R ");
		}
		else
		{
			printf("D ");
		}
		printf("%d %d\n",vec[1][i],vec[2][i]);
	}
	return 0;
}
//another
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,m;
int gx,gy;
char map[505][505];

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(out(nx,ny)) continue;
		if(map[nx][ny]=='X' && nx==gx && ny==gy)
		{
			cout<<"YES\n";
			exit(0);
		}
		if(map[nx][ny]=='X') continue;
		map[nx][ny]='X';
		dfs(nx,ny);
//		map[nx][ny]='.';
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
	}
	int sx,sy;
	cin>>sx>>sy>>gx>>gy;
	--sx;--sy;
	--gx;--gy;
	if(map[sx][sy]=='.')
	{
		rep(4)
		{
			int nx=sx+dx[i];
			int ny=sy+dy[i];
			if(out(nx,ny)) continue;
			if(map[nx][ny]=='X' && nx==sx && ny==sy)
			{
				cout<<"YES\n";
				return 0;
			}
			if(map[nx][ny]=='X') continue;
			map[nx][ny]='X';
			dfs(sx,sy);
			map[nx][ny]='.';
		}
	}
	else
	{
		dfs(sx,sy);
	}
	cout<<"NO\n";
	return 0;
}
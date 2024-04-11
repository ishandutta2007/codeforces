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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
const int dx[]={-1,1,-1,0,0,0,1,1,-1};
const int dy[]={1,0,-1,-1,0,1,1,0,-1};
char map[10][10];
bool can[25][10][10];

bool in(int x,int y)
{
	return (x>=1 && x<=8 && y>=1 && y<=8);
}

int main()
{
//	freopen("input.txt","r",stdin);
	for(int i=1;i<=8;i++)
	{
		scanf("%s",map[i]+1);
	}
	can[0][8][1]=2;
	for(int t=0;t<25;t++)
	{
		for(int i=1;i<=8;i++)
		{
			for(int j=1;j<=8;j++)
			{
				if(!can[t][i][j]) continue;
				for(int k=0;k<9;k++)
				{
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(!in(nx,ny)) continue;
					if(nx-t>=1 && map[nx-t][ny]=='S') continue;
					if(nx-t>=2 && map[nx-t-1][ny]=='S') continue;
					can[t+1][nx][ny]=true;
				}
			}
		}
	}
	for(int i=0;i<25;i++)
	{
		if(can[i][1][8])
		{
			cout<<"WIN\n";
			return 0;
		}
	}
	cout<<"LOSE\n";
	return 0;
}
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
char map[9][9];
int x,y;

int main()
{
//	freopen("input.txt","r",stdin);
	string t;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<3;j++)
		{
			cin>>t;
			for(int k=0;k<3;k++)
			{
				map[i][k+j*3]=t[k];
			}
		}
	}
//	for(int i=0;i<9;i++)
//	{
//		for(int j=0;j<9;j++)
//		{
//			cout<<map[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	cin>>x>>y;
	x--;
	y--;
	int nx=x%3,ny=y%3;
	bool f=true;
	for(int i=nx*3;i<nx*3+3;i++)
	{
		for(int j=ny*3;j<ny*3+3;j++)
		{
//			cout<<i<<' '<<j<<Endl;
			if(map[i][j]=='.')
			{
				map[i][j]='!';
				f=false;
			}
		}
	}
	if(f)
	{
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(map[i][j]=='.') map[i][j]='!';
			}
		}
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<map[i][j];
			if(j%3==2) cout<<' ';
		}
		cout<<endl;
		if(i%3==2) cout<<endl;
	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
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
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
char c[1005][1005];
char g[1005][1005];
int n,m;
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};

bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

bool ok(int x,int y)
{
//	if(c[x][y]=='#') return false;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(out(nx,ny)) return false;
		if(c[nx][ny]=='.') return false;
	}
	return true;
}

bool color(int x,int y)
{
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		g[nx][ny]='#';
	}
	return true;
}

int main()
{	
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			g[i][j]='.';
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!ok(i,j)) continue;
//			cout<<i<<' '<<j<<endl;
			color(i,j);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(c[i][j]!=g[i][j]) over("NO\n");
		}
	}
	cout<<"YES\n";
	return 0;
}
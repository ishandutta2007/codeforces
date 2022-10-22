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
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n,m;
const int dx[4][5]={{0,0,0,1,2},{0,0,0,-1,-2},{0,1,2,1,1},{0,-1,-2,-1,-1}};
const int dy[4][5]={{0,1,2,1,1},{0,1,2,1,1},{0,0,0,1,2},{0,0,0,-1,-2}};
//const int rx[]={1,-1};
//const int ry[]={1,-1};
char c[18][18];
int best;
char ans[18][18];

inline bool out(int x,int y)
{
	return (x<0 || y<0 || x>=n || y>=m);
}

inline bool can(int x,int y,int d,const int dx[],const int dy[])
{
	for(int i=0;i<5;i++)
	{
		int nx=x+dx[i];//*rx[d];
		int ny=y+dy[i];//*ry[d];
		if(out(nx,ny)) return false;
		if(c[nx][ny]!='.') return false;
	}
	return true;
}

void add(int x,int y,int d,int now,const int dx[],const int dy[])
{
	for(int i=0;i<5;i++)
	{
		int nx=x+dx[i];//*rx[d];
		int ny=y+dy[i];//*ry[d];
		c[nx][ny]='A'+now;
	}
}

void del(int x,int y,int d,const int dx[],const int dy[])
{
	for(int i=0;i<5;i++)
	{
		int nx=x+dx[i];//*rx[d];
		int ny=y+dy[i];//*ry[d];
		c[nx][ny]='.';
	}
}

void dfs(int x,int y,int now)
{
//	cout<<x<<' '<<y<<' '<<now<<endl;
	if(0.1805*(double)(n*m-((x)*m+y))+now<=best) return;
	int nx=x,ny=y;
	ny++;
	if(ny==m)
	{
		nx++;
		ny=0;
	}
	if(nx==n)
	{
		if(now>best)
		{
			best=now;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					ans[i][j]=c[i][j];
				}
			}
		}
		return;
	}
	for(int d=0;d<4;d++)
	{
		if(can(x,y,d,dx[d],dy[d]))
		{
			add(x,y,d,now,dx[d],dy[d]);
			dfs(nx,ny,now+1);
			del(x,y,d,dx[d],dy[d]);
		}
	}
	dfs(nx,ny,now);
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			c[i][j]='.';
		}
	}
//	add(2,2,0,0,dx[3],dy[3]);
//	c[0][0]='A';
//	c[0][1]='A';
//	c[0][2]='A';
//	c[1][1]='A';
//	c[2][1]='A';
//	cout<<can(2,2,1)<<endl;
//	return 0;
//	cout<<can(1,2,3)<<endl;
//	return 0;
	best=-1;
	dfs(0,0,0);
	cout<<best<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}
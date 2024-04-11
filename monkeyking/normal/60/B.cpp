#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <vector>
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
int n,m,h,sx,sy;
char map[15][15][15];
bool visit[15][15][15];

bool in(int a,int b,int c)
{
	if(a>-1 && b>-1 && c>-1 && a<n && b<m && c<h)
	{
		return (map[a][b][c]=='.' && !visit[a][b][c]);
	}
	else
	{
		return false;
	}
}

int dfs(int a,int b,int c)
{
//	cout<<a<<' '<<b<<' '<<c<<endl;
	visit[a][b][c]=true;
	int s=1;
	if(in(a+1,b,c))
	{
		s+=dfs(a+1,b,c);
	}
	if(in(a-1,b,c))
	{
		s+=dfs(a-1,b,c);
	}
	if(in(a,b+1,c))
	{
		s+=dfs(a,b+1,c);
	}
	if(in(a,b-1,c))
	{
		s+=dfs(a,b-1,c);
	}
	if(in(a,b,c+1))
	{
		s+=dfs(a,b,c+1);
	}
	if(in(a,b,c-1))
	{
		s+=dfs(a,b,c-1);
	}
	return s;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>h;
	rep(n)
	{
		repj(m)
		{
			scanf("%s",map[i][j]);
		}
	}
	cin>>sx>>sy;
	sx--;
	sy--;
	cout<<dfs(0,sx,sy);
	return 0;
}
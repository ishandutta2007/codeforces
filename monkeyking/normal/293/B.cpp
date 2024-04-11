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
int n,m,k;
int a[15][15];
int use[15][15];
int appear;
const int mod=1e9+7;
int never[15][15];

int dfs(int x,int y)
{
	if(x==n+1 && y==1)
	{
		return 1;
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//			{
//				cout<<a[i][j]<<' ';
//			}
//			cout<<endl;
//		}
	}
	use[x][y]=use[x-1][y] | use[x][y-1];
	int nx=x,ny=y;
	if(ny==m)
	{
		nx++;
		ny=1;
	}
	else
	{
		ny++;
	}
	if(a[x][y]!=0)
	{
		if(use[x][y] & (1<<a[x][y]))
		{
			return 0;
		}
		else
		{
			use[x][y]|=(1<<a[x][y]);
			int t=dfs(nx,ny);
			use[x][y]^=(1<<a[x][y]);
			return t%mod;
		}
	}
	int s=-1;
	int res=0;
	for(int i=1;i<=k;i++)
	{
		if(use[x][y] & (1<<i)) continue;
		if(never[x][y] & (1<<i)) continue;
		a[x][y]=i;
		if(appear & (1<<i))
		{
			use[x][y]|=(1<<i);
			res+=dfs(nx,ny);
			use[x][y]^=(1<<i);
			res%=mod;
		}
		else if(s==-1)
		{
			use[x][y]|=(1<<i);
			appear|=(1<<i);
			s=dfs(nx,ny);
			res+=s;
			res%=mod;
			appear^=(1<<i);
			use[x][y]^=(1<<i);
		}
		else
		{
			res+=s;
			res%=mod;
		}
		a[x][y]=0;
	}
//	cout<<x<<' '<<y<<endl;
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	if(n+m-1>k) over(0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i+1][j+1];
			appear|=(1<<a[i+1][j+1]);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			never[i][j]=never[i+1][j] | never[i][j+1] | (1<<a[i][j]);
			if(never[i][j] & 1) never[i][j]--;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<never[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	appear|=1;
	cout<<dfs(1,1)<<endl;
	return 0;
}
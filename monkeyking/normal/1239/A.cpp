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
int res;
int a[15][15];
int calc[15][15];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
ll f[100005];
const int mod=1e9+7;

bool check()
{
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<a[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int s=0;
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<0 || y<0 || x>=n || y>=m) continue;
				s+=(a[x][y]==a[i][j]);
			}
//			cout<<i<<' '<<j<<' '<<s<<endl;
			if(s>1) return false;
		}
	}
//	cout<<"GOOD\n";
	return true;
}

void dfs(int x,int y)
{
	if(x==n)
	{
		res+=check();
		return;
	}
	int nx=x,ny=y;
	ny++;
	if(ny==m) nx++,ny=0;
	for(int i=0;i<2;i++)
	{
		a[x][y]=i;
		dfs(nx,ny);
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
//	cin>>n>>m;
//	for(int n=1;n<=10;n++)
//	{
//		for(int m=1;m*n<=20;m++)
//		{
//			::n=n;
//			::m=m;
//			res=0;
//			dfs(0,0);
//			cout<<n<<'-'<<m<<' '<<res<<endl;
//		}
//		cout<<endl;
//	}
//	dfs(0,0);
//	cout<<res<<endl;
	cin>>n>>m;
	f[1]=2;
	f[2]=4;
	for(int i=3;i<=100000;i++)
	{
		f[i]=f[i-2]+f[i-1];
		f[i]%=mod;
	}
	cout<<(f[n]+f[m]-2+mod)%mod<<endl;
	return 0;
}
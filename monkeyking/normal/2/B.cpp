//why
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
#define over(A) {cout<<A<<endl;exit(0);}
typedef unsigned long long ull;
const int inf=103974182;
using namespace std;
int n;
int map[1005][1005];
int a[1005][1005];
int t[1005][1005];
char road[1005][1005];
int res=inf;
string ans;

void make_road(int k)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			t[i][j]=map[i][j];
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(t[i][j]==0)
			{
				a[i][j]=inf;
				continue;
			}
			while(t[i][j]%k==0)
			{
				t[i][j]/=k;
				a[i][j]++;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		a[i][0]=inf;
		a[0][i]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1][j]>a[i][j-1])
			{
				a[i][j]+=a[i][j-1];
				road[i][j]='R';
			}
			else
			{
				a[i][j]+=a[i-1][j];
				road[i][j]='D';
			}
		}
	}
	if(a[n][n]<res)
	{
		res=a[n][n];
		ans.clear();
		int x=n,y=n;
		while(1)
		{
			ans.push_back(road[x][y]);
			if(road[x][y]=='R')
			{
				y--;
			}
			else
			{
				x--;
			}
			if(x==1 && y==1) break;
		}
		reverse(ans.begin(),ans.end());
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	make_road(5);
	make_road(2);
	if(res>1)
	{
		int x=-1,y=-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(map[i][j]==0)
				{
					x=i;
					y=j;
				}
			}
		}
		if(x!=-1)
		{
			ans.clear();
			res=1;
			for(int i=1;i<x;i++)
			{
				ans+='D';
			}
			for(int i=1;i<n;i++)
			{
				ans+='R';
			}
			for(int i=x;i<n;i++)
			{
				ans+='D';
			}
		}
	}
	cout<<res<<endl;
	cout<<ans<<endl;
	return 0;
}
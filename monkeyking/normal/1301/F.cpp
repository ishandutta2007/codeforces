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
#include <assert.h>
#include <bitset>
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
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
int n,m;
int a[1005][1005];
int k;
int q;
int dist[45][45];
short dis[1001][1001][40];
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

bool out(int x,int y)
{
	if(x<0 || y<0 || x>=n || y>=m);
}

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("1.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",a[i]+j);
			a[i][j]--;
		}
	}
	memset(dist,0x3f,sizeof(dist));
	memset(dis,0x3f,sizeof(dis));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			dis[i][j][a[i][j]]=0;
			for(int c=0;c<k;c++)
			{
				chmin(dis[i+1][j][c],dis[i][j][c]+1);
				chmin(dis[i][j+1][c],dis[i][j][c]+1);
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			dis[i][j][a[i][j]]=0;
			for(int c=0;c<k;c++)
			{
				if(i) chmin(dis[i-1][j][c],dis[i][j][c]+1);
				if(j) chmin(dis[i][j-1][c],dis[i][j][c]+1);
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{
			dis[i][j][a[i][j]]=0;
			for(int c=0;c<k;c++)
			{
				if(i) chmin(dis[i-1][j][c],dis[i][j][c]+1);
				chmin(dis[i][j+1][c],dis[i][j][c]+1);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			dis[i][j][a[i][j]]=0;
			for(int c=0;c<k;c++)
			{
				chmin(dis[i+1][j][c],dis[i][j][c]+1);
				if(j) chmin(dis[i][j-1][c],dis[i][j][c]+1);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int c=0;c<k;c++)
			{
				chmin(dis[i][j][c],dis[i][j][c]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int c=0;c<k;c++)
			{
				chmin(dist[a[i][j]][c],dis[i][j][c]);
				chmin(dist[c][a[i][j]],dis[i][j][c]);
			}
		}
	}
	for(int l=0;l<k;l++)
	{
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				chmin(dist[i][j],dist[i][l]+dist[l][j]+1);
			}
		}
	}
	int q;
	cin>>q;
	int sx,sy,ex,ey;
	while(q--)
	{
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		sx--;
		sy--;
		ex--;
		ey--;
		short *ms=dis[sx][sy];
		short *me=dis[ex][ey];
		int res=inf;
		for(int i=0;i<k;i++)
		{
			for(int j=0;j<k;j++)
			{
				if(i!=j) chmin(res,ms[i]+me[j]+dist[i][j]+2);else chmin(res,ms[i]+me[j]+dist[i][j]+1);
			}
		}
		chmin(res,abs(sx-ex)+abs(sy-ey));
		printf("%d\n",res);
	}
	return 0;
}
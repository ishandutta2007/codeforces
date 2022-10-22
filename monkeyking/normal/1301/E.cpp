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
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int sum[4][505][505];
int cen[505][505];
char c[505][505];
int n,m,q;
char id[256];
int st[9][9][505][505];

inline bool out(int x,int y)
{
	return (x<0 || y<0 || x>n || y>m);
}

inline bool check(int sx,int sy,int ex,int ey,int k,int ch)
{
	if(out(sx,sy)) return false;
	if(out(ex,ey)) return false;
	assert((ex-sx+1)==k);
	assert((ey-sy+1)==k);
	return (sum[ch][ex][ey]-sum[ch][sx-1][ey]-sum[ch][ex][sy-1]+sum[ch][sx-1][sy-1]==k*k);
}

inline bool check(int x,int y,int k,bool debug=false)
{
	return (check(x-k+1,y-k+1,x,y,k,0) & check(x-k+1,y+1,x,y+k,k,1) & check(x+1,y-k+1,x+k,y,k,2) & check(x+1,y+1,x+k,y+k,k,3));
}

int max2d(int sx,int sy,int ex,int ey)
{
	if(sx>ex) return -1;
	if(sy>ey) return -1;
	int lx,ly;
	for(int i=0;i<=9;i++)
	{
		if((1<<i)>ex-sx+1)
		{
			lx=i;
			break;
		}
	}
	for(int i=0;i<=9;i++)
	{
		if((1<<i)>ey-sy+1)
		{
			ly=i;
			break;
		}
	}
	lx--;
	ly--;
	return max({st[lx][ly][sx][sy],st[lx][ly][ex-(1<<lx)+1][ey-(1<<ly)+1],st[lx][ly][ex-(1<<lx)+1][sy],st[lx][ly][sx][ey-(1<<ly)+1]});
}

bool qcheck(int k,int sx,int sy,int ex,int ey)
{
	return (max2d(sx+k-1,sy+k-1,ex-k+1,ey-k+1)>=k);
}

int main()
{
// 	freopen("input.txt","r",stdin);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
	}
	id['R']=0;
	id['G']=1;
	id['Y']=2;
	id['B']=3;
	for(int k=0;k<4;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				sum[k][i][j]=sum[k][i-1][j]+sum[k][i][j-1]-sum[k][i-1][j-1]+(id[c[i][j]]==k);
			}
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int l=1,r=min(n,m),m,res=-1;
			while(l<=r)
			{
				m=l+r>>1;
				if(check(i,j,m))
				{
					res=m;
					l=m+1;
				}
				else
				{
					r=m-1;
				}
			}
			cen[i][j]=res;
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			st[0][0][i][j]=cen[i][j];
		}
	}
	for(int k1=0;k1<8;k1++)
	{
		for(int i=1;i<n;i++)
		{
			if(i+(1<<k1)>=n) break;
			for(int j=1;j<m;j++)
			{
				st[k1+1][0][i][j]=max({st[k1][0][i][j],st[k1][0][i+(1<<k1)][j]});
			}
		}
	}
	for(int k1=0;k1<=8;k1++)
	{
		for(int k2=0;k2<8;k2++)
		{
			for(int i=1;i<n;i++)
			{
				for(int j=1;j<m;j++)
				{
					if(j+(1<<k2)>=m) break;
					st[k1][k2+1][i][j]=max(st[k1][k2][i][j],st[k1][k2][i][j+(1<<k2)]);
				}
			}
		}
	}
	int sx,sy,ex,ey;
	int l,r,mid,res;
	while(q--)
	{
		scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
		ex--;
		ey--;
		l=1;
		r=min(n,m);
		res=0;
		while(l<=r)
		{
			mid=l+r>>1;
			if(qcheck(mid,sx,sy,ex,ey))
			{
				res=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		printf("%d\n",res*res*4);
	}
	return 0;
}
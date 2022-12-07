#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=1005;

int a[maxn][maxn],dp[maxn][maxn];
int st[maxn][maxn][10][10];
int lg[1005];
int i,j,m,n,t;

int pd(int x1,int y1,int x2,int y2)
{
	int p=lg[x2-x1+1],q=lg[y2-y1+1];
	int m1=max(st[x1][y1][p][q],st[x2-(1<<p)+1][y2-(1<<q)+1][p][q]);
	int m2=max(st[x2-(1<<p)+1][y1][p][q],st[x1][y2-(1<<q)+1][p][q]);
	return max(m1,m2);
}

int find(int x1,int y1,int x2,int y2)
{
	int l=0;
	int r=min(y2-y1+1,x2-x1+1);
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(pd(x1+mid-1,y1+mid-1,x2,y2)>=mid)l=mid;else r=mid;
	}
	if(pd(x1+r-1,y1+r-1,x2,y2)>=r)return r;else return l;
}

int main()
{
	scan2(n,m);
	lg[1]=0;
	for(i=2;i<=1000;i++)lg[i]=lg[i/2]+1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)dp[i][1]=a[i][1];
	for(i=1;i<=m;i++)dp[1][i]=a[1][i];
	for(i=2;i<=n;i++)
		for(j=2;j<=m;j++)if(a[i][j])dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)st[i][j][0][0]=dp[i][j];
	for(i=1;i<=n;i++)
		for(int y=1;y<10;y++)
			for(j=1;j<=m-(1<<y)+1;j++)
				st[i][j][0][y]=max(st[i][j][0][y-1],st[i][j+(1<<(y-1))][0][y-1]);
	for(j=1;j<=m;j++)
		for(int x=1;x<10;x++)
			for(i=1;i<=n-(1<<x)+1;i++)
				st[i][j][x][0]=max(st[i][j][x-1][0],st[i+(1<<(x-1))][j][x-1][0]);
	for(int x=1;x<10;x++)
	for(i=1;i<=n-(1<<x)+1;i++)
		for(int y=1;y<10;y++)
		for(j=1;j<=m-(1<<y)+1;j++)
		{
			st[i][j][x][y]=st[i][j][x-1][y-1];
			st[i][j][x][y]=max(st[i][j][x][y],st[i+(1<<(x-1))][j][x-1][y-1]);
			st[i][j][x][y]=max(st[i][j][x][y],st[i][j+(1<<(y-1))][x-1][y-1]);
			st[i][j][x][y]=max(st[i][j][x][y],st[i+(1<<(x-1))][j+(1<<(y-1))][x-1][y-1]);
		}
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",find(x1,y1,x2,y2));
	}
    return 0;
}
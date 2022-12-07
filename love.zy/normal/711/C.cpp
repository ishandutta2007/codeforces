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
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
  
LL dp[105][105][105];
LL cost[105][105];
int a[105];
int i,j,k,l,m,n,t;
const LL inf=1e12;
LL mi1,mi2;

int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)scanf("%lld",&cost[i][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<=t;j++)
			for(k=1;k<=m;k++)dp[i][j][k]=inf;
	if(a[1]==0)
	{
		for(i=1;i<=m;i++)dp[1][1][i]=cost[1][i];
	}else dp[1][1][a[1]]=0;
	for(i=2;i<=n;i++)
	{
		if(a[i]!=0)
		{
			if(a[i-1]!=0)dp[i][1][a[i]]=((a[i]==a[i-1])?dp[i-1][1][a[i-1]]:inf);
			else dp[i][1][a[i]]=dp[i-1][1][a[i]];
		}else
		{
			if(a[i-1]!=0)dp[i][1][a[i-1]]=dp[i-1][1][a[i-1]]+cost[i][a[i-1]];
			else for(l=1;l<=m;l++)dp[i][1][l]=dp[i-1][1][l]+cost[i][l];
		}
		for(j=2;j<=t;j++)
		{
			if(j>i)break;
			if(a[i]!=0)//a[i]!=0
			{
				if(a[i-1]!=0){dp[i][j][a[i]]=((a[i]!=a[i-1])?dp[i-1][j-1][a[i-1]]:dp[i-1][j][a[i-1]]);continue;}//a[i-1]!=0
				mi1=inf,mi2=inf;//a[i-1]==0
				for(k=1;k<=m;k++)
				{
					LL p=dp[i-1][j-1][k];
					if(p<=mi1){mi2=mi1;mi1=p;continue;}
					if(p<=mi2)mi2=p;
				}
				dp[i][j][a[i]]=min(dp[i-1][j][a[i]],dp[i-1][j-1][a[i]]==mi1?mi2:mi1);
				continue;
			}
			//a[i]==0
			if(a[i-1]!=0)
			{
				dp[i][j][a[i-1]]=dp[i-1][j][a[i-1]]+cost[i][a[i-1]];
				for(k=1;k<=m;k++)
				{
					if(k==a[i-1])continue;
					dp[i][j][k]=dp[i-1][j-1][a[i-1]]+cost[i][k];
				}
				continue;
			}
			//a[i]==0 && a[i-1]==0
			mi1=inf,mi2=inf;
			for(k=1;k<=m;k++)
			{
				LL p=dp[i-1][j-1][k];
				if(p<=mi1){mi2=mi1;mi1=p;continue;}
				if(p<=mi2)mi2=p;
			}
			for(k=1;k<=m;k++)dp[i][j][k]=min(dp[i-1][j][k],((dp[i-1][j-1][k]==mi1)?mi2:mi1))+cost[i][k];
		}
	}
	LL mmm=inf;
	if(a[n]!=0)mmm=dp[n][t][a[n]];
	else for(i=1;i<=m;i++)mmm=min(mmm,dp[n][t][i]);
	printf("%lld",((mmm==inf)?-1:mmm));
    return 0;
}
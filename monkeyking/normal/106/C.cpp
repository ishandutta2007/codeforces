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
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cingroup(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfgroup(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
typedef unsigned long long ull;
using namespace std;
int dp[1005][15];

struct form
{
	int sum;
	int cost;
	int money;
};

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,0,sizeof(dp));
	int n,m;
	int a,b,c,d;
	cin>>n>>m>>a>>b;
	form date[15];
	date[0].sum=1000;
	date[0].money=b;
	date[0].cost=a;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c>>d;
		date[i].sum=(int)(a/b);
		date[i].money=d;
		date[i].cost=c;
	}
	m++;
//	for(int i=0;i<m;i++)
//	{
//		printf("%d%d,%d,%d\n",i,date[i].sum,date[i].cost,date[i].money);
//	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<=date[j].sum && date[j].cost*k<=(n-i);k++)
			{
				if(dp[i+k*date[j].cost][j]<dp[i][j-1]+date[j].money*k) dp[i+k*date[j].cost][j]=dp[i][j-1]+date[j].money*k;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
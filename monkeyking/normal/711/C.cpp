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
using namespace std;
ll dp[105][105][105];
int n,m,k;
int a[105];
int cost[105][105];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		a[i]--;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",cost[i]+j);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	ll inf=dp[0][0][0];
	dp[0][0][m]=0;
	for(int i=0;i<n;i++)
	{
		for(int block=0;block<=min(i,k);block++)
		{
			for(int pre=0;pre<=m;pre++)
			{
				if(dp[i][block][pre]==inf) continue;
				for(int cur=0;cur<m;cur++)
				{
					if(a[i]!=-1 && a[i]!=cur) continue;
					dp[i+1][block+(cur!=pre)][cur]=min(dp[i+1][block+(cur!=pre)][cur],dp[i][block][pre]+(cost[i][cur])*(a[i]==-1));
				}
			}
		}
	}
	ll res=inf;
	for(int last=0;last<m;last++)
	{
		res=min(res,dp[n][k][last]);
	}
	if(res==inf) cout<<-1<<endl;else cout<<res<<endl;
	return 0;
}
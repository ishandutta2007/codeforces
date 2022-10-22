#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <assert.h>
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
int n;
int a[400005];
ll dp[(1<<20)];
ll cost[20][20];
ll sum[400005][20];
ll tsum[20];
ll cc[(1<<20)][20];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		a[i]--;
	}
	for(int i=0;i<20;i++)
	{
		memset(tsum,0,sizeof(tsum));
		for(int j=0;j<n;j++)
		{
			tsum[a[j]]++;
			if(a[j]==i)
			{
				for(int t=0;t<20;t++)
				{
					cost[t][i]+=tsum[t];
				}
			}
		}
	}
	for(int i=0;i<20;i++)
	{
		cc[0][i]=0;
		for(int mask=1;mask<(1<<20);mask++)
		{
			cc[mask][i]=cc[mask&(mask-1)][i]+cost[__builtin_ctz(mask)][i];
		}
	}
//	cout<<cc[(1<<3)+(1<<18)+(1<<19)][4]<<endl;
//	cout<<cost[3][4]<<endl;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	int U=(1<<20)-1;
	for(int mask=0;mask<(1<<20);mask++)
	{
		for(int i=0;i<20;i++)
		{
			if(!((1<<i) && mask)) continue;
			dp[mask]=min(dp[mask],dp[mask^(1<<i)]+cc[U^(mask)][i]);
		}
	}
//	cout<<cost[U-(1<<1)][1]<<endl;
//	cout<<dp[1]<<endl;
	cout<<dp[(1<<20)-1]<<endl;
	return 0;
}
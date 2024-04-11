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
int n;
int dp[(1<<24)];
int sx,sy;
int x[25],y[25];
int cost[25][25];
int co[25];
pair<short,short> trace[(1<<24)];

int calc(int x1,int y1,int x2,int y2)
{
	return ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() 
{
//	freopen("input.txt","r",stdin);
	cin>>sx>>sy;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cost[i][j]=calc(sx,sy,x[i],y[i])+calc(x[i],y[i],x[j],y[j])+calc(x[j],y[j],sx,sy);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int mask=1;mask<(1<<n);mask++)
	{
		int low=__builtin_ctz(mask);
		for(int i=0;i<n;i++)
		{
			if(!((1<<i) & mask)) continue;
			if(dp[mask^((1<<i)|(1<<low))]+cost[i][low]<=dp[mask])
			{
				dp[mask]=dp[mask^((1<<i)|(1<<low))]+cost[i][low];
				trace[mask]=mp(i,low);
			}
		}
	}
	int mask=(1<<n)-1;
	cout<<dp[mask]<<endl;
	while(mask)
	{
		pair<short,short> t=trace[mask];
		cout<<0<<' '<<t.first+1<<' ';
		if(t.first!=t.second) cout<<t.second+1<<' ';
		mask^=((1<<t.first) | (1<<t.second));
	}
	cout<<0<<endl;
	return 0;
}
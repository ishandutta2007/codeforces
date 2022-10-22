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
int dp[45][90][90];
int n,m;

int occ(int mask)
{
	return mask | (mask>>1) | (mask<<1 & ((1<<m)-1));
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	if(n<m) swap(n,m);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int pre=0;pre<(1<<m);pre++)
		{
			for(int now=0;now<(1<<m);now++)
			{
				for(int pp=0;pp<(1<<m);pp++)
				{
//					if(i==2 && (pp!=0 || pre!=0)) continue;
//					if(i==3 && pp!=0) continue;
					if((i!=1) && (occ(pre) | now | pp) != (1<<m)-1) continue;
					dp[i][pre][now]=min(dp[i][pre][now],dp[i-1][pp][pre]+__builtin_popcount(now));
				}
			}
		}
	}
	int res=inf;
//	cout<<dp[2][2][8]<<endl;
//	cout<<dp[3][8][1]<<endl;
//	cout<<dp[4][1][4]<<endl;
//for(int fuck=0;fuck<n;fuck++)
//{
	for(int i=0;i<(1<<m);i++)
	{
		for(int j=0;j<(1<<m);j++)
		{
			if((i | occ(j)) != (1<<m)-1) continue;
//			cout<<dp[fuck][i][j]<<' ';
			res=min(res,dp[n][i][j]);
		}
//		cout<<endl;
	}
//	cout<<endl;
//}
	cout<<n*m-res<<endl;
	return 0;
}
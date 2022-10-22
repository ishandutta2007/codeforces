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
const int base=105;
using namespace std;
int n,k;
char c[105];
int dp[105][55][base*2+5][2];

inline int go(int dir)
{
	if(dir==0) return 1;else return -1;
}

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	n=strlen(c);
	cin>>k;
	dp[0][0][0+base][0]=true;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int d=0;d<base*2+5;d++)
			{
				for(int use=0;use<=k;use++)
				{
					for(int dir=0;dir<=1;dir++)
					{
						if(j+use>k) continue;
						if(!dp[i][j][d][dir]) continue;
						if(c[i]=='F')
						{
							if(!(use&1)) dp[i+1][j+use][d+go(dir)][dir]=true;
							else dp[i+1][j+use][d][!dir]=true;
						}
						else
						{
							if(!(use &1)) dp[i+1][j+use][d][!dir]=true;
							else dp[i+1][j+use][d+go(dir)][dir]=true;
						}
	//					cout<<i<<' '<<j<<' '<<d<<' '<<dir<<endl;
					}
				}
			}
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<=k;j++)
//		{
//			for(int k=base-2;k<base+2;k++)
//			{
//				for(int d=0;d<2;d++)
//				{
//					cout<<dp[i][j][k][d]<<'-';
//				}
//				cout<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	int res=0;
	for(int i=0;i<base*2+5;i++)
	{
		if(!dp[n][k][i][0] && !dp[n][k][i][1]) continue;
		res=max(res,abs(i-base));
	}
	cout<<res<<endl;
	return 0;
}
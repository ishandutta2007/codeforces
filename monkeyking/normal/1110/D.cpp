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
int dp[1000005][5][5];
int n,m;
int a[1000005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	int x;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		a[x]++;
	}
	for(int i=0;i<m;i++)
	{
		for(int p1=0;p1<=4;p1++)
		{
			for(int p2=0;p2<=4;p2++)
			{
				dp[i][p1][p2]=-inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(int i=0;i<m;i++)
	{
		for(int p1=0;p1<=4;p1++)
		{
			for(int p2=0;p2<=4;p2++)
			{
				for(int use=0;use<=min(p2,p1);use++)
				{
					if(a[i+1]<use) continue;
					int num=(a[i+1]-use)/3;
					int rem=(a[i+1]-use)%3;
					dp[i+1][rem][p1-use]=max(dp[i+1][rem][p1-use],dp[i][p1][p2]+num+use);
					if(num) dp[i+1][min(4,rem+3)][p1-use]=max(dp[i+1][min(4,rem+3)][p1-use],dp[i][p1][p2]+num-1+use);
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<=4;j++)
		{
			res=max(dp[m][i][j],res);
		}
	}
	cout<<res<<endl;
	return 0;
}
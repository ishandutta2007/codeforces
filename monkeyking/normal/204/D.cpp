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
const int mod=1e9+7;
using namespace std;
char c[1000005];
int n,k;
bool pB[1000005],pW[1000005];
int dp[1000005][3][2];//0->B, 1->W

void add(int &a,const int b)
{
	a+=b;
	a%=mod;
}

int mut(const int a,const int b)
{
	return (1LL*a*b)%mod;
}

int sub(int &a,const int b)
{
	a-=b;
	if(a<0) a+=mod;
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
	int lastB=-1,lastW=-1;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='B')
		{
			if(i-lastB>=k) pB[i]=true;
			lastW=i;
		}
		if(c[i]=='W')
		{
			if(i-lastW>=k) pW[i]=true;
			lastB=i;
		}
		if(c[i]=='X')
		{
			if(i-lastB>=k) pB[i]=true;
			if(i-lastW>=k) pW[i]=true;
		}
	}
	dp[0][0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(c[i]=='X')
			{
				add(dp[i+1][j][1],dp[i][j][0]);
				add(dp[i+1][j][1],dp[i][j][1]);
				add(dp[i+1][j][0],dp[i][j][0]);
				add(dp[i+1][j][0],dp[i][j][1]);
			}
			else if(c[i]=='B')
			{
				add(dp[i+1][j][0],dp[i][j][0]);
				add(dp[i+1][j][0],dp[i][j][1]);
			}
			else
			{
				add(dp[i+1][j][1],dp[i][j][0]);
				add(dp[i+1][j][1],dp[i][j][1]);
			}
//			if(c[i]=='X') add(dp[i+1][j],mut(dp[i][j],2));
//			else add(dp[i+1][j],dp[i][j]);
		}
		if(pB[i])
		{
			sub(dp[i+1][0][0],dp[i-k+1][0][1]);
			add(dp[i+1][1][0],dp[i-k+1][0][1]);
		}
		if(pW[i])
		{
			sub(dp[i+1][1][1],dp[i-k+1][1][0]);
			add(dp[i+1][2][1],dp[i-k+1][1][0]);
		}
	}
//	int i=n;
//	if(i && pB[i-1])
//	{
//		sub(dp[i][0],(i-k-1<0?0:dp[i-k-1][0]));
//		add(dp[i][1],(i-k-1<0?0:dp[i-k-1][0]));
//	}
//	if(i && pW[i-1])
//	{
//		sub(dp[i][1],(i-k-1<0?0:dp[i-k-1][1]));
//		add(dp[i][2],(i-k-1<0?0:dp[i-k-1][1]));
//	}
//	cout<<pB[1]<<endl;
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<3;j++)
//		{
//			cout<<dp[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	cout<<(dp[n][2][0]+dp[n][2][1])%mod<<endl;
	return 0;
}
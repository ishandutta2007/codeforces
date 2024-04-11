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
const int basic=200;
using namespace std;
int n,k,init;
long double dp[205][405][205];
long double p[205];
int a[205];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k>>init;
	dp[0][min(n+basic,init+basic)][0]=1;
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		p[i]=((double)x)/100;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=basic-n;j<=basic+n;j++)
		{
			for(int l=0;l<=i;l++)
			{
//				if(i==2 && a[i]==2 && j+a[i]==basic+2) cout<<dp[3][basic+2][1]<<endl;
				dp[i+1][min(basic+n,j+a[i])][l+1]+=dp[i][j][l]*p[i];
				dp[i+1][j][l]+=dp[i][j][l]*(1-p[i]);
			}
		}
	}
	double res=0;
	cout.precision(10);
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=basic-n;j<=basic+n;j++)
//		{
//			for(int l=0;l<=n;l++)
//			{
//				cout<<dp[i][j][l]<<' ';
//			}
//			cout<<endl;
//		}
//		cout<<endl;
//	}
//	cout<<endl;
//	cout<<dp[3][basic+2][1]<<endl;
	for(int i=basic;i<=basic+n;i++)
	{
		for(int j=k;j<=n;j++)
		{
			res+=dp[n][i][j];
		}
	}
	cout<<res<<endl;
	return 0;
}
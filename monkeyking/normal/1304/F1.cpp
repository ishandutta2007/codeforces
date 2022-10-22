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
int n,m,k;
int a[55][20005];
int dp[55][20005];
int sum[55][20005];
int ml[20005];
int mr[20005];

inline int getsum(int i,int x,int k)
{
	return sum[i][x+k-1]-(x?sum[i][x-1]:0);
}

inline int getsumlr(int i,int l,int r)
{
	if(l>r) return 0;
	return sum[i][r]-(l?sum[i][l-1]:0);
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			sum[i][j]=(j?sum[i][j-1]:0)+a[i][j];
		}
	}
	for(int i=0;i<m;i++)
	{
		if(i+k>m) break;
		dp[0][i]=getsum(0,i,k)+getsum(1,i,k);
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ml[j]=max((j?ml[j-1]:-1),dp[i-1][j]);
		}
		for(int j=m-1;j>=0;j--)
		{
			mr[j]=max((j==m-1?-1:mr[j+1]),dp[i-1][j]);
		}
		for(int j=0;j<m;j++)
		{
			if(j+k>m) break;
			int s=getsum(i,j,k)+getsum(i+1,j,k);
			int nbl=max(-1,j-k),nbr=min(m,j+k);
			if(nbl!=-1) dp[i][j]=max(dp[i][j],ml[nbl]+s);
			if(nbr!=m) dp[i][j]=max(dp[i][j],mr[nbr]+s);
			for(int lj=nbl+1;lj<nbr;lj++)
			{
				if(lj+k>m) break;
				int t=s+(i?dp[i-1][lj]:0);
				int l=max(j,lj);
				int r=min(j+k-1,lj+k-1);
				t-=getsumlr(i,l,r);
				dp[i][j]=max(dp[i][j],t);
			}
		}
	}
	int res=0;
	for(int i=0;i<m;i++)
	{
		if(i+k>m) break;
		res=max(res,dp[n-1][i]);
	}
	cout<<res<<endl;
	return 0;
}
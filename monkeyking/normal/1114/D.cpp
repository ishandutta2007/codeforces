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
#define abs(a) (a>0?a:-a)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int dp[5005][5005];
int n;
int a[5005];
int tor[5005];
int tol[5005];

int dfs(int l,int r)
{
	if(dp[l][r]!=-1) return dp[l][r];
	if(tor[l]==r) return dp[l][r]=0;
	if(a[l]==a[r]) return dp[l][r]=dfs(tor[l]+1,tol[r]-1)+1;
	else return dp[l][r]=min(dfs(tor[l]+1,r),dfs(l,tol[r]-1))+1;
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int now=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]==a[now])
		{
			tor[i]=now;
		}
		else
		{
			tor[i]=i;
			now=i;
		}
	}
	now=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==a[now])
		{
			tol[i]=now;
		}
		else
		{
			tol[i]=i;
			now=i;
		}
	}
	cout<<dfs(0,n-1)<<endl;
	return 0;
}
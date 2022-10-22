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
const int basic=300000;
using namespace std;
int n;
int bot[300005];
int dp[300005];
vector <int> vec[300005];
int leaves;

//int go(int x)
//{
//	size[x]=1;
//	for(int i=0;i<vec[x].size();i++)
//	{
//		size[x]+=go(vec[x][i]);
//	}
//	return size[x];
//}

int dfs(int x)
{
	if(dp[x]!=-1) return dp[x];
	if(vec[x].size()==0)
	{
		leaves++;
		return dp[x]=1;
	}
	if(bot[x]==1)
	{
		dp[x]=inf;
		for(int i=0;i<vec[x].size();i++)
		{
			dp[x]=min(dp[x],dfs(vec[x][i]));
		}
	}
	else
	{
		dp[x]=0;
		int t=0;
		for(int i=0;i<vec[x].size();i++)
		{
			dp[x]+=dfs(vec[x][i]);
			t=max(t,dfs(vec[x][i]));
		}
//		dp[x]-=t;
	}
	return dp[x];
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d",bot+i);
	}
	int x;
	for(int i=1;i<n;i++)
	{
		scanf("%d",&x);
		x--;
		vec[x].push_back(i);
	}
	dfs(0);
	cout<<-dfs(0)+leaves+1<<endl;
	return 0;
}
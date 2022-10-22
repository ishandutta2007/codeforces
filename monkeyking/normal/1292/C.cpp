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
vector <int> vec[3005];
ll best=0;
ll now;
pair<int,int> edge[3005];
int par[3005][3005];
ll dp[3005][3005];
ll son[3005][3005];

int go(int x,int p,int root)
{
	par[x][root]=p;
	son[x][root]=1;
	for(auto u:vec[x])
	{
		if(u==p) continue;
		son[x][root]+=go(u,x,root);
	}
	return son[x][root];
}

ll dfs(int x,int y)
{
	if(dp[x][y]!=-1) return dp[x][y];
	ll &res=dp[x][y];
	ll cost=1LL*son[x][y]*son[y][x];
	if(par[x][y]==y) return res=cost;
	return res=max(dfs(par[x][y],y),dfs(x,par[y][x]))+cost;
}

int main()
{
//	freopen("input.txt","r",stdin);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
		edge[i]=mp(x,y);
	}
	for(int i=0;i<n;i++)
	{
		go(i,-1,i);
	}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			res=max(res,dfs(i,j));
		}
	}
	cout<<res<<endl;
	return 0;
}
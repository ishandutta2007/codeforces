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
int son[200005];
vector <int> vec[200005];
int n;
ll dp[200005];
ll res;

int GetSon(int x,int p=-1)
{
	son[x]=1;
	for(auto u:vec[x])
	{
		if(u==p) continue;
		son[x]+=GetSon(u,x);
	}
	return son[x];
}

ll dfs(int x,int p=-1)
{
	dp[x]=son[x];
	for(auto u:vec[x])
	{
		if(u==p) continue;
		dp[x]+=dfs(u,x);
	}
	return dp[x];
}

void go(int x,int p=-1)
{
	res=max(res,dp[x]);
	for(auto u:vec[x])
	{
		if(u==p) continue;
		dp[x]-=dp[u];
		dp[x]-=son[u];
		son[x]-=son[u];
		int temp=son[u];
		son[u]=n;
		dp[u]+=dp[x];
		dp[u]+=son[x];
		go(u,x);
		dp[u]-=son[x];
		dp[u]-=dp[x];
		son[u]=temp;
		son[x]+=son[u];
		dp[x]+=dp[u];
		dp[x]+=son[u];
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int x,y;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vec[x].push_back(y);
		vec[y].push_back(x);
	}
	GetSon(0);
	res=dfs(0);
	go(0);
	cout<<res<<endl;
	return 0;
}
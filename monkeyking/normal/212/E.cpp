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
int n;
vector <int> vec[5005];
int dp[5005];
bool ok[5005];
bool dp2[5005];
int fa[5005];

int dfs(int x,int p)
{
	fa[x]=p;
	dp[x]=1;
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==p)
		{
			continue;
		}
		dp[x]+=dfs(vec[x][i],x);
	}
	return dp[x];
}

void ks(vector <int> vec)
{
	memset(dp2,0,sizeof(dp2));
	dp2[0]=true;
	for(int i=0;i<vec.size();i++)
	{
		for(int j=n;j>=vec[i];j--)
		{
			dp2[j]|=dp2[j-vec[i]];
		}
	}
	for(int i=0;i<=n;i++)
	{
		ok[i]|=dp2[i];
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
	dp[0]=dfs(0,-1);
//	for(int i=0;i<n;i++)
//	{
//		cout<<dp[i]<<' ';
//	}
//	cout<<endl;
	for(int i=1;i<n;i++)
	{
		vector <int> t;
		int sum=0;
		for(int j=0;j<vec[i].size();j++)
		{
			if(vec[i][j]==fa[i]) continue;
			sum+=dp[vec[i][j]];
//			cout<<vec[i][j]<<' '<<dp[vec[i][j]]<<endl;
			t.push_back(dp[vec[i][j]]);
		}
		t.push_back(n-sum-1);
		ks(t);
	}
	vector <int> t;
	for(int i=0;i<vec[0].size();i++)
	{
		t.push_back(dp[vec[0][i]]);
	}
	ks(t);
	vector <pii> res;
	for(int i=1;i<n-1;i++)
	{
		if(ok[i]) res.push_back(mp(i,n-i-1));
	}
	cout<<res.size()<<endl;
	for(auto x:res)
	{
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}
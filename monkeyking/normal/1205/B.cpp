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
vector <int> bit[65];
int n;
ll a[100005];
vector <int> vec[100005];
bool visit[100005];
int res;
map <ll,int> tb;

void dfs(int x,int depth,int par)
{
	visit[x]=1;
	for(auto u:vec[x])
	{
		if(u==par) continue;
		if(visit[u]) res=min(res,depth);
		else dfs(u,depth+1,x);
	}
	visit[x]=0;
}

int main()
{
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>n;
	ll x,t;
	for(ll i=0;i<=60;i++)
	{
		tb[(1LL<<i)]=i;
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a[i]=x;
		t=x;
		while(x)
		{
			bit[tb[(x&-x)]].push_back(i);
			x&=(x-1);
		}
	}
//	for(auto x:bit[4])
//	{
//		cout<<x<<endl;
//	}
	for(int i=0;i<65;i++)
	{
		if(bit[i].size()>=3)
		{
			cout<<3<<endl;
			return 0;
		}
		else
		{
			if(bit[i].size()==2)
			{
				vec[bit[i][0]].push_back(bit[i][1]);
				vec[bit[i][1]].push_back(bit[i][0]);
			}
		}
	}
//	for(int i=0;i<4;i++)
//	{
//		for(auto x:vec[i])
//		{
//			cout<<i<<' '<<x<<endl;
//		}
//	}
	res=inf;
	for(int i=0;i<n;i++)
	{
		dfs(i,1,-1);
	}
	if(res==inf)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<res<<endl;
	}
	return 0;
}
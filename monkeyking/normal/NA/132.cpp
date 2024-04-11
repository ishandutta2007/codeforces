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
int dp[(1<<20)];
vector <pair<int,int> > vec[25];//mask cost.
char c[25][25];
int a[25][25];
int n,m;
map <int,int> exptobit;

int main()
{
//	freopen("input.txt","r",stdin);
	int nn=1;
	for(int i=0;i<=20;i++)
	{
		exptobit[nn]=i;
		nn<<=1;
	}
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			vec[i].push_back(mp(1<<i,a[i][j]));
			vector <int> v;
			int mask=0;
			for(int k=0;k<n;k++)
			{
				if(c[i][j]!=c[k][j]) continue;
				mask|=(1<<k);
				v.push_back(a[k][j]);
			}
			sort(all(v));
			int cost=0;
			for(int k=0;k<v.size()-1;k++)
			{
				cost+=v[k];
			}
			vec[i].push_back(mp(mask,cost));
		}
		sort(all(vec[i]));
		vec[i].erase(unique(all(vec[i])),vec[i].end());
	}
	
	for(int i=0;i<(1<<n)-1;i++)
	{
		int unused=((1<<n)-1)^i;
		int lowbit=exptobit[unused&-unused];
		for(auto x:vec[lowbit])
		{
			dp[i | x.first]=min(dp[i | x.first],dp[i]+x.second);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}
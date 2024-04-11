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
ll dp[(1<<20)][25];
int n;
bool connect[25][25];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n;
	int m;
	cin>>m;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--;
		y--;
		connect[x][y]=connect[y][x]=true;
	}
	ll res=0;
	for(int st=0;st<n;st++)
	{
		memset(dp,0,sizeof(dp));
		for(int mask=0;mask<(1<<st);mask++)
		{
			for(int last=0;last<=st;last++)
			{
				dp[mask][last]=0;
			}
		}
		dp[0][st]=1;
		for(int mask=0;mask<(1<<st);mask++)
		{
			for(int last=0;last<=st;last++)
			{
//				cout<<dp[mask][last]<<endl;
				if(!dp[mask][last]) continue;
				if(connect[last][st] && mask&mask-1) res+=dp[mask][last];
				for(int x=0;x<st;x++)
				{
					if((1<<x) & mask) continue;
					if(!connect[x][last]) continue;
					dp[mask | (1<<x)][x]+=dp[mask][last];
				}
			}
		}
	}
	cout<<res/2<<endl;
	return 0;
}
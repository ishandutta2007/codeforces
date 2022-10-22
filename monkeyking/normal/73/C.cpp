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
int dp[105][105][26];
int a[26][26];
char c[105];
int k,n;

int main()
{
//	freopen("input.txt","r",stdin);
	scanf("%s",c);
	cin>>k;
	n=strlen(c);
	int m;
	cin>>m;
	char x,y;
	int cost;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>cost;
		a[x-'a'][y-'a']=cost;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int last=0;last<26;last++)
			{
				dp[i][j][last]=-inf;
			}
		}
	}
	for(int i=0;i<26;i++)
	{
		dp[1][(c[0]!=(i+'a'))][i]=0;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int last=0;last<26;last++)
			{
				for(int next=0;next<26;next++)
				{
					dp[i+1][j+(c[i]!=(next+'a'))][next]=max(dp[i+1][j+(c[i]!=(next+'a'))][next],dp[i][j][last]+a[last][next]);
				}
			}
		}
	}
//	cout<<a['o'-'a']['s'-'a']<<endl;
//	cout<<dp[3][3]['o'-'a']<<endl;
	int res=-inf;
	for(int change=0;change<=k;change++)
	{
		for(int last=0;last<26;last++)
		{
			res=max(res,dp[n][change][last]);
		}
	}
	cout<<res<<endl;
	return 0;
}
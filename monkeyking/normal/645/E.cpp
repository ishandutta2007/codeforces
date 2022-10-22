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
#include <deque>
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
const int mod=1e9+7;
using namespace std;
int dp[1000005][26];
int n;
char c[1000005];
int k;
int a[26];
deque <int> que;
int use[26];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	scanf("%s",c);
	dp[0][c[0]-'a']=1;
	int len=strlen(c);
	for(int i=0;i<k;i++)
	{
		use[i]=-1;
	}
	use[c[0]-'a']=0;
	for(int i=1;i<len;i++)
	{
		use[c[i]-'a']=i;
		for(int j=0;j<k;j++)
		{
			if(c[i]==j+'a')
			{
				for(int o=0;o<k;o++)
				{
					dp[i][j]+=dp[i-1][o];
					dp[i][j]%=mod;
				}
				dp[i][j]++;
			}
			else
			{
				dp[i][j]=dp[i-1][j];
				dp[i][j]%=mod;
			}
		}
	}
//	cout<<use[0]<<' '<<use[1]<<' '<<use[2]<<endl;
	for(int i=0;i<26;i++)
	{
		a[i]=dp[len-1][i];
	}
	int mink=0;
	for(int i=0;i<n;i++)
	{
		mink=0;
		for(int j=1;j<k;j++)
		{
			if(use[mink]>use[j]) mink=j;
		}
		use[mink]=len+i;
		for(int j=0;j<k;j++)
		{
			if(j==mink) continue;
			a[mink]+=a[j];
			a[mink]%=mod;
		}
		a[mink]++;
	}
//	for(int i=0;i<k;i++)
//	{
//		cout<<a[i]<<' ';
//	}
//	cout<<endl;
	int res=0;
	for(int i=0;i<k;i++)
	{
		res+=a[i];
		res%=mod;
	}
	res++;
	res%=mod;
	cout<<res<<endl;
	return 0;
}
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
#include <time.h>
#define Endl endl
#define mp make_pair
#define ll long long 
#define ull unsinged long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
#define srand() mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand(l,r) uniform_int_distribution<int>(l,r)(rng)
template <typename T1,typename T2> inline void chmin(T1 &x,T2 b) {if(b<x) x=b;}
template <typename T1,typename T2> inline void chmax(T1 &x,T2 b) {if(b>x) x=b;}
const int inf=1039074182;
using namespace std;
vector <vector<int> > dp;
string s,t;
int fail[100005];
int n,m;
int nextj[100005][26];
bool weight[100005][26];

void build()
{
	int j=fail[0]=-1;
	for(int i=1;i<=m;i++)
	{
		while(j>=0 && t[i-1]!=t[j]) j=fail[j];
		fail[i]=++j;
	}
	for(int i=1;i<=m;i++)
	{
		while(t[i]==t[fail[i]]) fail[i]=fail[fail[i]];
	}
}

int main()
{
	double startTime=clock();
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin>>s>>t;
	n=s.size();
	m=t.size();
	dp.resize(n+1);
	for(int i=0;i<=n;i++)
	{
		dp[i].resize(m+1,-1);
	}
	build();
	dp[0][0]=0;
	int nj;
	for(int j=0;j<=m;j++)
	{
		for(char c='a';c<='z';c++)
		{
			int nj=j;
			if(nj==m) nj=fail[nj];
			while(nj>=0 && c!=t[nj]) nj=fail[nj];
			nj++;
			nextj[j][c-'a']=nj;
			weight[j][c-'a']=(nj==m);
		}
	}
	double secPassed=(clock()-startTime)/CLOCKS_PER_SEC;
	assert(secPassed<=1);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(dp[i][j]==-1) continue;
			if(s[i]!='?')
			{
				chmax(dp[i+1][nextj[j][s[i]-'a']],dp[i][j]+weight[j][s[i]-'a']);
			}
			else
			{
				for(int k=0;k<26;k++)
				{
					chmax(dp[i+1][nextj[j][k]],dp[i][j]+weight[j][k]);
				}
			}
		}
	}
	int res=0;
	for(int i=0;i<=m;i++)
	{
		chmax(res,dp[n][i]);
	}
	cout<<res<<endl;
	return 0;
}
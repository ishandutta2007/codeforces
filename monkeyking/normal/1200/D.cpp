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
int k,n;
char c[2005][2005];
int okcol[2005][2005];
int okrow[2005][2005];
int sumcol[2005][2005];
int sumrow[2005][2005];
int havecol[2005];
int haverow[2005];
int sumhavecol[2005][2005];
int sumhaverow[2005][2005];

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		int low=n,up=-1;
		for(int j=0;j<n;j++)
		{
			if(c[i][j]=='B') low=min(low,j),up=max(up,j);
		}
		if(low==n)
		{
			haverow[i]=true;
			res++;
			for(int j=0;j<n;j++)
			{
				okrow[i][j]=true;
			}
			continue;
		}
		for(int j=max(0,up-k+1);j<=low;j++)
		{
			okrow[i][j]=true;
		}
	}
	for(int j=0;j<n;j++)
	{
		int low=n,up=-1;
		for(int i=0;i<n;i++)
		{
			if(c[i][j]=='B') low=min(low,i),up=max(up,i);
		}
		if(low==n)
		{
			havecol[j]=true;
			res++;
			for(int i=0;i<n;i++)
			{
				okcol[i][j]=true;
			}
			continue;
		}
		for(int i=max(0,up-k+1);i<=low;i++)
		{
			okcol[i][j]=true;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			sumhavecol[i][0]+=havecol[j];
			sumcol[i][0]+=okcol[i][j];
		}
		for(int j=1;j<n;j++)
		{
			sumcol[i][j]=sumcol[i][j-1]-okcol[i][j-1]+(j+k-1<n?okcol[i][j+k-1]:0);
			sumhavecol[i][j]=sumhavecol[i][j-1]-havecol[j-1]+(j+k-1<n?havecol[j+k-1]:0);
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<k;i++)
		{
			sumrow[0][j]+=okrow[i][j];
			sumhaverow[0][j]+=haverow[i];
		}
		for(int i=1;i<n;i++)
		{
			sumrow[i][j]=sumrow[i-1][j]-okrow[i-1][j]+(i+k-1<n?okrow[i+k-1][j]:0);
			sumhaverow[i][j]=sumhaverow[i-1][j]-haverow[i-1]+(i+k-1<n?haverow[i+k-1]:0);
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//		{
//			cout<<okrow[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans=max(ans,res+sumrow[i][j]+sumcol[i][j]-sumhaverow[i][j]-sumhavecol[i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
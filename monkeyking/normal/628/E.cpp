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
int n,m;
char c[3005][3005];
int lnei[3005][3005];
int rnei[3005][3005];
int a[3005];
int b[3005];
int len;
int bit[6005];
int nn;
vector <int> table[3005];

inline void add(int x,int delta)
{
	while(x<=nn)
	{
		bit[x]+=delta;
		x+=x&(-x);
	}
}

inline int query(int x)
{
	int res=0;
	while(x>0)
	{
		res+=bit[x];
		x&=(x-1);
	}
	return res;
}

inline int sum(int l,int r)
{
	return query(r)-(l==1?0:query(l-1));
}

int solve()
{
	nn=1;
	while(nn<len)
	{
		nn<<=1;
	}
	int time=0;
	for(int i=len-1;i>=0;i--)
	{
		if(time+b[i]<=len) table[time+b[i]].push_back(i);
		time++;
	}
	time=0;
	int res=0;
	for(int i=len-1;i>=0;i--)
	{
		add(i+1,1);
		for(int j=0;j<table[time].size();j++)
		{
			add(table[time][j]+1,-1);
		}
		res+=sum(i+1,min(i+a[i],len));
		time++;
	}
	for(int i=0;i<=len;i++)
	{
		table[i].clear();
	}
	memset(bit,0,4*nn+4);
	return res;
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%s",c[i]);
	}
	for(int i=0;i<n;i++)
	{
		lnei[i][0]=(c[i][0]=='z');
		for(int j=1;j<m;j++)
		{
			if(c[i][j]=='z')
			{
				lnei[i][j]=lnei[i][j-1]+1;
			}
			else
			{
				lnei[i][j]=0;
			}
		}
		rnei[i][m]=0;
		for(int j=m-1;j>=0;j--)
		{
			if(c[i][j]=='z')
			{
				rnei[i][j]=rnei[i][j+1]+1;
			}
			else
			{
				rnei[i][j]=0;
			}
		}
	}
	ll res=0;
	for(int i=0;i<m;i++)
	{
		len=0;
		int ni=0,nj=i;
		while(ni<n && nj>=0)
		{
			if(c[ni][nj]=='z')
			{
				a[len]=lnei[ni][nj];
				b[len]=rnei[ni][nj];
				len++;
			}
			else
			{
				if(len) res+=solve();
				len=0;
			}
			ni++;
			nj--;
		}
		if(len) res+=solve();
	}
	for(int i=1;i<n;i++)
	{
		len=0;
		int ni=i,nj=m-1;
		while(ni<n && nj>=0)
		{
			if(c[ni][nj]=='z')
			{
				a[len]=lnei[ni][nj];
				b[len]=rnei[ni][nj];
				len++;
			}
			else
			{
				if(len) res+=solve();
				len=0;
			}
			ni++;
			nj--;
		}
		if(len) res+=solve();
	}
	cout<<res<<endl;
	return 0;
}
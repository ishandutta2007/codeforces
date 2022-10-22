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
const int mod=1e9+7;
using namespace std;
int w[8];

struct Matrix
{
	vector <vector<int> >a;
	int row;
	int column;
	bool initialized=false;
	void error()
	{
		cout<<"Error occured in Matrix!!\n";
		exit(0);
	}
	void init(int n,int m)
	{
		initialized=true;
		row=n;
		column=m;
		a.resize(n);
		for(int i=0;i<n;i++)
		{
			a[i].resize(m);
		}
		clear();
	}
	void clear()
	{
		if(!initialized)
		{
			error();
		}
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				a[i][j]=0;
			}
		}
	}
	void E()
	{
		clear();
		if(row!=column)
		{
			error();
		}
		for(int i=0;i<row;i++)
		{
			a[i][i]=1;
		}
	}
	void print()
	{
		if(!initialized)
		{
			error();
		}
		cout<<"Matrix: \n";
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{
				cout<<a[i][j]<<' ';
			}
			cout<<endl;
		}
		cout<<endl;
	}
};

Matrix operator * (Matrix a,Matrix b)
{
	int n=a.row;
	int m=b.column;
//	a.print();
//	b.print();
	if(a.column!=b.row)
	{
		a.error();
	}
	int l=a.column;
	Matrix res;
	res.init(n,m);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<l;k++)
			{
				res.a[i][j]+=(1LL*a.a[i][k]*b.a[k][j])%mod;
				res.a[i][j]%=mod;
			}
		}
	}
	return res;
}

Matrix fastpow(Matrix basic,ll n)
{
	if(basic.row!=basic.column) basic.error();
//	n--;
	Matrix res;
	res.init(basic.row,basic.row);
	res.E();
	while(n)
	{
		if(n&1) res=res*basic;
		basic=basic*basic;
		n>>=1;
	}
	return res;
}
Matrix base[8];

inline bool valid(int l,int m,int r,int len)
{
	if(len==1)
	{
		return (l==0 || r==0);
	}
	for(int i=0;i<len;i++)
	{
		if(((1<<i) & l)==false) continue;
		if(((1<<i) & r)==false) continue;
		if(i && ((1<<(i-1)) & m)==false) continue;
		if(i!=len-1 && ((1<<i) & m)==false) continue;
		return false;
	}
	return true;
}

void calc(int x)
{
	base[x].init((1<<x),(1<<x));
	for(int left=0;left<(1<<x);left++)
	{
		for(int mid=0;mid<(1<<(x-1));mid++)
		{
			for(int right=0;right<(1<<x);right++)
			{
				if(!valid(left,mid,right,x)) continue;
				base[x].a[left][right]++;
			}
		}
	}
	
}

Matrix hyperdim(int x)
{
	Matrix res;
	res.init((1<<(x+1)),1<<x);
	for(int i=(1<<(x));i<(1<<(x+1));i++)
	{
		res.a[i][i-(1<<x)]=1;
	}
	return res;
}

int main()
{
//	freopen("input.txt","r",stdin);
	for(int i=1;i<=7;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=7;i++)
	{
		calc(i);
	}
	Matrix now;
	now.init(2,1);
	now.a[1][0]=1;
	for(int i=1;i<=7;i++)
	{
//		if(i==2)
//		{
//			now.print();
//		}
//		cout<<i<<" done\n";
		now=fastpow(base[i],w[i])*now;
//		if(i==2)
//		{
//			base[2].print();
//			now.print();
//		}
//		cout<<i<<" done\n";
		now=hyperdim(i)*now;
//		cout<<i<<" done\n";
	}
	cout<<now.a[(1<<8)-1][0]<<endl;
	return 0;
}
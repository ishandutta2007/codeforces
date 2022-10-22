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
vector <vector<char> > vec;
vector <vector<int> >sum;
vector <vector<int> >add;
int n,m;
char c[1000005];

inline bool query(int x,int y,int len)
{
	if(x+len>n || y+len>m) return false;
//	cout<<sum[x+len-1][y+len-1]<<endl;
//	cout<<"FUCK"<<endl;
//	cout<<x<<' '<<y<<' '<<len<<endl;
	return (len*len==sum[x+len-1][y+len-1]-(y==0?0:sum[x+len-1][y-1])-(x==0?0:sum[x-1][y+len-1])+(x==0 || y==0?0:sum[x-1][y-1]));
}

bool check(int t)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			add[i][j]=0;
		}
	}
	t=t*2+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!query(i,j,t)) continue;
//			cout<<i<<' '<<j<<endl;
			add[i][j]++;
			if(i+t<n) add[i+t][j]--;
			if(j+t<m) add[i][j+t]--;
			if(i+t<n && j+t<m) add[i+t][j+t]++;
		}
	}
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			cout<<add[i][j]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i) add[i][j]+=add[i-1][j];
			if(j) add[i][j]+=add[i][j-1];
			if(i && j) add[i][j]-=add[i-1][j-1];
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vec[i][j]=='X')
			{
				if(add[i][j]<=0) return false;
			}
		}
	}
	return true;
}

void print(int t)
{
	t=t*2+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			add[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!query(i,j,t)) {}else add[i+t/2][j+t/2]=1;
		}
//		puts("");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(add[i][j]) putchar('X');else putchar('.');
		}
		puts("");
	}
}

int main()
{
//	freopen("input.txt","r",stdin);
	cin>>n>>m;
	vec.resize(n);
	sum.resize(n);
	add.resize(n);
	for(int i=0;i<n;i++)
	{
		vec[i].resize(m);
		sum[i].resize(m);
		add[i].resize(m);
	}
	for(int i=0;i<n;i++)
	{
		scanf("%s",c);
		for(int j=0;j<m;j++)
		{
			vec[i][j]=c[j];
		}
	}
	sum[0][0]=(vec[0][0]=='X');
	for(int i=1;i<n;i++)
	{
		sum[i][0]=sum[i-1][0]+(vec[i][0]=='X');
	}
	for(int j=1;j<m;j++)
	{
		sum[0][j]=sum[0][j-1]+(vec[0][j]=='X');
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(vec[i][j]=='X');
		}
	}
	int l=0,r=min(n,m),m,res;
	while(l<=r)
	{
		m=l+r>>1;
		if(check(m))
		{
			res=m;
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	cout<<res<<endl;
	print(res);
	return 0;
}
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<string>
#include<bitset>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=310;
const int MOD=1000000007;

int n,q,t;
vector<int> w,c,v[MaxN];
int a[MaxN],u[MaxN],uu[MaxN];
int F[MaxN][100010];

void add(int &x,int y)
{
	x+=y;
	if (x>=MOD) x-=MOD;
}

int main()
{
	cin>>n>>q>>t;
	ll tt=t;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		u[y]=1;
	}
	for (int k=1;k<=n;++k)
	{
		if (u[k]) continue;
		vector<int> w,c;
		for (int x=k;;x=v[x][0])
		{
			if (uu[x])
			{
				puts("0");
				return 0;
			}
			uu[x]=1;
			w.push_back(x);
			c.push_back(a[x]);
			if (v[x].empty()) break;
		}
		int m=w.size();
		
		for (int i=0;i<m;++i)
			tt-=(m-i-1)*c[i];
		
		for (int i=1;i<m;++i)
			c[i]+=c[i-1];
		for (int i=0;i<m;++i)
		{
			::w.push_back(w[i]);
			::c.push_back(c[i]);
		}
	}
	
	if (w.size()!=n)
	{
		puts("0");
		return 0;
	}
	
	if (tt<0)
	{
		puts("0");
		return 0;
	}
	
	t=tt;
	/*
	for (int i=0;i<n;++i)
		printf("%d ",w[i]);
	puts("");
	for (int i=0;i<n;++i)
		printf("%d ",c[i]);
	puts("");
	*/
	for (int i=0;i<=n;++i)
		for (int j=0;j<=t;++j)
			F[i][j]=0;
	F[n][0]=1;
	for (int i=n;i>=0;--i)
	{
		for (int j=0;j<=t;++j)
		{
			if (!F[i][j]) continue;
			if (i) add(F[i-1][j],F[i][j]);
			if (i<n) if (j+c[i]<=t) add(F[i][j+c[i]],F[i][j]);
		}
	}
	cout<<F[0][t]<<endl;
	return 0;
}
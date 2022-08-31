#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<string>
#include<queue>
#include<iomanip>
#include<limits>
#include<typeinfo>
#include<functional>
#include<numeric>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MaxN=52;

int k,x,n,m;

string get(int n,int x,int p)
{
	string s;
	for (int i=1;i<=x;++i)
		s+="AC";
	if (2*x==n) return s;
	if (2*x==n-1)
	{
		if (p>>1) s+='A';
		if (p&1) s="C"+s;
		if (!p) s+='B';
		return s;
	}
	while (s.size()<n-2) s+='B';
	if (p>>1) s+='A'; else s+='B';
	if (p&1) s="C"+s; else s="B"+s;
	return s;
}

ll s[MaxN],tA[MaxN],tC[MaxN];

bool check(int x,int px,int y,int py)
{
	s[1]=x;
	tA[1]=px>>1;
	tC[1]=px&1;
	s[2]=y;
	tA[1]=py>>1;
	tC[1]=py&1;
	for (int i=3;i<=k;++i)
	{
		s[i]=s[i-2]+s[i-1]+tA[i-2]*tC[i-1];
		tC[i]=tC[i-2];
		tA[i]=tA[i-1];
	}
	if (s[k]!=::x) return false;
	cout<<get(n,x,px)<<endl<<get(m,y,py)<<endl;
	return true;
}

bool may(int n,int i,int p)
{
	if (2*i==n&&p) return false;
	if (2*i==n-1)
	{
		if (p==3) return false;
	}
	return true;
}

int main()
{
	cin>>k>>x>>n>>m;
	for (int i=0;i<=n/2;++i) for (int pi=0;pi<4;++pi)
	{
		if (!may(n,i,pi)) continue;
		for (int j=0;j<=m/2;++j) for (int pj=0;pj<4;++pj)
		{
			if (!may(m,j,pj)) continue;
			if (check(i,pi,j,pj))
			{
				return 0;
			}
		}
	}
	puts("Happy new year!");
	return 0;
}
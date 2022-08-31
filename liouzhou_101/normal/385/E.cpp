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

ll A[6][6]=
{
	{2,1,1,0,1,0},
	{1,2,0,1,1,0},
	{1,1,1,0,1,0},
	{1,1,0,1,1,0},
	{0,0,0,0,1,1},
	{0,0,0,0,0,1}
};

ll n;
ll v[6][6],t[6][6];

void calc(ll tt)
{
	if (!tt)
	{
		for (int i=0;i<6;++i)
			for (int j=0;j<6;++j)
				v[i][j]=(i==j);
		return;
	}
	calc(tt/2);
	for (int i=0;i<6;++i)
		for (int j=0;j<6;++j)
		{
			t[i][j]=v[i][j];
			v[i][j]=0;
		}
	for (int i=0;i<6;++i)
		for (int j=0;j<6;++j)
			for (int k=0;k<6;++k)
				(v[i][j]+=t[i][k]*t[k][j])%=n;
	if (tt%2)
	{
	for (int i=0;i<6;++i)
		for (int j=0;j<6;++j)
		{
			t[i][j]=v[i][j];
			v[i][j]=0;
		}
	for (int i=0;i<6;++i)
		for (int j=0;j<6;++j)
			for (int k=0;k<6;++k)
				(v[i][j]+=A[i][k]*t[k][j])%=n;
	}
}

int main()
{
	ll sx,sy,dx,dy,t;
	cin>>n>>sx>>sy>>dx>>dy>>t;
	calc(t);
	ll p[]={sx,sy,dx,dy,0,1};
	ll px=0,py=0;
	for (int i=0;i<6;++i)
	{
		(px+=v[0][i]*p[i])%=n;
		(py+=v[1][i]*p[i])%=n;
	}
	if (px<0) px+=n;
	if (py<0) py+=n;
	if (!px) px=n;
	if (!py) py=n;
	cout<<px<<" "<<py<<endl;
	return 0;
}
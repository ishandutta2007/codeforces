#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<bitset>
#include<vector>
#include<string>
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

const int MaxN=110;
const int INF=1000000000;

int n,d;
int a[MaxN];
pii p[MaxN];
int F[MaxN],u[MaxN];

int getdis(pii a,pii b)
{
	return abs(a.X-b.X)+abs(a.Y-b.Y);
}

int main()
{
	cin>>n>>d;
	for (int i=2;i<n;++i)
		cin>>a[i];
	for (int i=1;i<=n;++i)
		cin>>p[i].X>>p[i].Y;
	for (int i=1;i<=n;++i)
		F[i]=INF;
	F[1]=0;
	while (1)
	{
		pii t(INF,0);
		for (int i=1;i<=n;++i)
			if (!u[i]) t=min(t,pii(F[i],i));
		int x=t.Y;
		if (!x) break;
		u[x]=1;
		for (int i=1;i<=n;++i)
			if (!u[i]) F[i]=min(F[i],F[x]+getdis(p[x],p[i])*d-a[i]);
	}
	cout<<F[n]<<endl;
	return 0;
}
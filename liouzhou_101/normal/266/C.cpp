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

const int MaxN=1010;

int n;
int x[MaxN],y[MaxN];
vector<int> vx[MaxN],vy[MaxN];

int a[MaxN],b[MaxN];

bool cmp_a(int i,int j)
{
	return vx[i].size()<vx[j].size();
}

bool cmp_b(int i,int j)
{
	return vy[i].size()<vy[j].size();
}

int u[MaxN];
int xto[MaxN],yto[MaxN];
vector<pii> p1,p2;

void solve(int* to,vector<pii> &p)
{
	for (int i=1;i<=n;++i)
	{
		u[i]=0;
		//d[i]=i;
	}
	for (int i=1;i<=n;++i)
	{
		if (u[i]) continue;
		int x=i;
		while (x!=to[x])
		{
			if (u[x]) break;
			u[x]=1;
			if (to[x]==i) break;
			p.push_back(pii(i,to[x]));
			x=to[x];
		}
	}
}

int main()
{
	cin>>n;
	for (int i=1;i<n;++i)
	{
		cin>>x[i]>>y[i];
		vx[x[i]].push_back(y[i]);
		vy[y[i]].push_back(x[i]);
	}
	for (int i=1;i<=n;++i)
		a[i]=b[i]=i;
	sort(a+1,a+n+1,cmp_a);
	sort(b+1,b+n+1,cmp_b);
	int use=0;
	for (int i=1;i<=n;++i)
	{
		xto[a[i]]=i;
		for (int j=0;j<vx[a[i]].size();++j)
		{
			if (yto[vx[a[i]][j]]) continue;
			++use;
			yto[vx[a[i]][j]]=use;
		}
	}
	for (int i=1;i<=n;++i)
		if (!yto[i])
		{
			++use;
			yto[i]=use;
		}
	solve(xto,p1);
	solve(yto,p2);
	cout<<p1.size()+p2.size()<<endl;
	for (int i=0;i<p1.size();++i)
		printf("%d %d %d\n",1,p1[i].X,p1[i].Y);
	for (int i=0;i<p2.size();++i)
		printf("%d %d %d\n",2,p2[i].X,p2[i].Y);
	return 0;
}
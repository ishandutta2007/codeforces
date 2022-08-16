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

const int MaxN=5010;

int n,m;
int a[MaxN],b[MaxN];
map<int,int> f;
map<int,int> s[MaxN];
int u[32000];
int ans;
map<int,int> g[MaxN];

int main()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
		cin>>a[i];
	for (int i=1;i<=m;++i)
	{
		cin>>b[i];
		f[b[i]]=-1;
	}
	for (int i=2;i<=31622;++i)
		if (!u[i])
		{
			if (!f.count(i)) f[i]=1;
			for (int j=i+i;j<=31622;j+=i)
				u[j]=1;
			for (int k=1;k<=n;++k)
			{
				while (a[k]%i==0)
				{
					a[k]/=i;
					s[k][i]++;
					ans+=f[i];
				}
			}
		}
	for (int k=1;k<=n;++k)
		if (a[k]>1)
		{
			int t=a[k];
			if (!f.count(t)) f[t]=1;
			s[k][t]++;
			ans+=f[t];
		}
	g[1]=s[1];
	for (int k=2;k<=n;++k)
	{
		for (auto p : s[k])
		{
			int x=p.X,y=p.Y;
			if (g[k-1].count(x))
				g[k][x]=min(g[k-1][x],y);
		}
	}
	for (int k=n;k>=1;--k)
	{
		if (g[k].empty()) continue;
		int delta=0;
		for (auto p : g[k])
		{
			delta+=f[p.X]*p.Y;
		}
		if (delta<0)
		{
			ans-=delta*k;
			for (int i=1;i<=k;++i)
				for (auto p : g[k])
					g[i][p.X]-=p.Y;
		}
	}
	cout<<ans<<endl;
	return 0;
}
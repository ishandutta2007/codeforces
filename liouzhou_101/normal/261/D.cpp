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

const int MaxN=100010;
const int INF=1000000000;

int n,maxb,t;
int b[MaxN],d[MaxN];
int F[250000];

inline int place(int x,int y)
{
	return (y&1)*n+x;
}

bool cmp(int i,int j)
{
	return b[i]<b[j]||b[i]==b[j]&&i>j;
}

void solve()
{
	for (int i=1;i<=n;++i)
	{
		scanf("%d",&b[i]);
		d[i]=i;
	}
	sort(d+1,d+n+1,cmp);
	for (int i=n;i>=1;--i)
		F[place(i,1)]=1;
	int ans=1;
	for (int i=2;i<=maxb;++i)
	{
		pii x(INF,0),y(INF,0);
		int flag=0;
		for (int k=1;k<=n;++k)
		{
			if (b[d[k]]==b[d[k-1]]) continue;
			for (int j=k;j<=n;++j) if (b[d[k]]==b[d[j]])
			{
				if ((F[place(d[j],i)]=min(x.X+(x.Y>=d[j]),y.X+(y.Y>=d[j])))<=t)
				{
					ans=i;
					flag=1;
				}
			}
			else break;
			for (int j=k;j<=n;++j) if (b[d[k]]==b[d[j]])
			{
				pii u(F[place(d[j],i-1)],d[j]);
				if (u.X<x.X)
				{
					y=x;
					x=u;
				}
				else if (u.X==x.X)
				{
					x.Y=min(x.Y,u.Y);
				}
				else if (u.X<y.X)
				{
					y=u;
				}
				else if (u.X==y.X)
				{
					y.Y=min(y.Y,u.Y);
				}
			}
			else break;
		}
		if (!flag) break;
	}
	cout<<ans<<endl;
}

int main()
{
	int T;
	cin>>T;
	cin>>n>>maxb>>t;
	while (T--)
	{
		solve();
	}
	return 0;
}
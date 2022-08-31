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
const ll INF=1000000000000000000LL;

int n,m;

struct node
{
	ll t;
	int x,y,p,u;
	bool operator < (const node &A) const
	{
		return t<A.t;
	}
}p[MaxN];

ll ans[MaxN];

void init()
{
	cin>>n>>m;
	for (int i=1;i<=n;++i)
	{
		scanf("%I64d%d%d",&p[i].t,&p[i].x,&p[i].y);
		p[i].p=i;
	}
	sort(p+1,p+n+1);
}

set<pii> U,D;

void work()
{
	int nowx=1;
	ll nowt=0;
	p[n+1].t=INF;
	for (int i=1;i<=n+1;++i)
	{
		if (p[i].t==p[i-1].t) continue;
		while (1)
		{
			if (U.empty()&&D.empty()) break;
			if (U.size()>=D.size())
			{
				set<pii>::iterator it=U.begin();
				if (it->X-nowx>p[i].t-nowt)
				{
					nowx+=p[i].t-nowt;
					nowt=p[i].t;
					break;
				}
				nowt+=it->X-nowx;
				nowx=it->X;
				while (1)
				{
					if (U.empty()) break;
					it=U.begin();
					if (it->X!=nowx) break;
					if (!p[it->Y].u)
					{
						if (p[it->Y].y>nowx)
							U.insert(pii(p[it->Y].y,it->Y));
						else
							D.insert(pii(p[it->Y].y,it->Y));
						p[it->Y].u=1;
					}
					else
						ans[p[it->Y].p]=nowt;
					U.erase(it);
				}
			}
			else
			{
				set<pii>::iterator it=--D.end();
				if (nowx-it->X>p[i].t-nowt)
				{
					nowx-=p[i].t-nowt;
					nowt=p[i].t;
					break;
				}
				nowt+=nowx-it->X;
				nowx=it->X;
				while (1)
				{
					if (D.empty()) break;
					it=--D.end();
					if (it->X!=nowx) break;
					if (!p[it->Y].u)
					{
						if (p[it->Y].y>nowx)
							U.insert(pii(p[it->Y].y,it->Y));
						else
							D.insert(pii(p[it->Y].y,it->Y));
						p[it->Y].u=1;
					}
					else
						ans[p[it->Y].p]=nowt;
					D.erase(it);
				}
			}
		}
		if (i==n+1) break;
		nowt=p[i].t;
		for (int j=i;j<=n;++j)
		{
			if (p[j].t!=nowt) break;
			if (p[j].x==nowx)
			{
				p[j].u=1;
				if (p[j].y>nowx)
					U.insert(pii(p[j].y,j));
				else
					D.insert(pii(p[j].y,j));
			}
			else if (p[j].x>nowx)
				U.insert(pii(p[j].x,j));
			else
				D.insert(pii(p[j].x,j));
		}
	}
	for (int i=1;i<=n;++i)
		printf("%I64d\n",ans[i]);
}

int main()
{
	init();
	work();
	return 0;
}
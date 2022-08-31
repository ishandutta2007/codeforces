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
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef pair<ll,ll> pll;

#define X first
#define Y second

const int MaxN=100010;
const int MaxK=10010;

ll h,INF;
int n,m,k;
ll a[MaxN];
int c[MaxN],u[MaxN];
vector<int> p[MaxK];
vector<pll> v[MaxK];
set<pii> H;

void addway(ll x)
{
	for (int i=0;i<k;++i)
		v[i].push_back(pll((i+x)%k,x));
}

ll d[MaxK];

void build()
{
	for (int i=0;i<k;++i)
		d[i]=INF;
	d[1]=1;
	priority_queue<pll> Q;
	Q.push(pll(-1,1));
	while (!Q.empty())
	{
		int x=Q.top().Y;
		ll y=-Q.top().X;
		Q.pop();
		if (d[x]!=y) continue;
		for (vector<pll>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (d[it->X]>y+it->Y)
				Q.push(pll(-(d[it->X]=y+it->Y),it->X));
	}
	H.clear();
	H.insert(pii(0,0));
	for (int i=0;i<k;++i)
		for (vector<int>::iterator it=p[i].begin();it!=p[i].end();++it)
			if (a[*it]>=d[i])
			{
				u[*it]=1;
				H.insert(pii(c[*it],-*it));
			}
}

int main()
{
	cin>>h>>n>>m>>k;
	INF=h+10;
	for (int i=1;i<=n;++i)
	{
		scanf("%I64d%d",&a[i],&c[i]);
		p[a[i]%k].push_back(i);
	}
	build();
	while (m--)
	{
		int t;
		scanf("%d",&t);
		if (t==1)
		{
			ll x;
			scanf("%I64d",&x);
			addway(x);
			build();
		}
		else if (t==2)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if (u[x])
			{
				H.erase(pii(c[x],-x));
				H.insert(pii(c[x]-y,-x));
			}
			c[x]-=y;
		}
		else
		{
			set<pii>::iterator it=--H.end();
			printf("%d\n",it->X);
			c[-it->Y]=0;
			if (it->Y) H.erase(it);
		}
	}
	return 0;
}
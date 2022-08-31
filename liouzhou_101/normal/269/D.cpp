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

int n,t;

struct node
{
	int h,l,r;
}p[MaxN];

bool cmp_l(int i,int j)
{
	return p[i].l<p[j].l;
}

bool cmp_r(int i,int j)
{
	return p[i].r<p[j].r;
}

int a[MaxN],b[MaxN];

map<int,int> H;

vector<pii> v[MaxN];
int d[MaxN];

void addedge(int x,int y)
{
	int d=min(p[x].r,p[y].r)-max(p[x].l,p[y].l);
	v[x].push_back(pii(y,d));
	::d[y]++;
}

void deal(int &j,int lim)
{
	while (j<=n&&p[b[j]].r<=lim)
	{
		map<int,int>::iterator it,itx,ity;
		it=itx=ity=H.find(p[b[j]].h);
		if (it!=H.begin())
		{
			--itx;
			addedge(it->Y,itx->Y);
		}
		if (++ity!=H.end())
		{
			addedge(ity->Y,it->Y);
		}
		H.erase(it);
		++j;
	}
}

void init()
{
	cin>>n>>t;
	for (int i=1;i<=n;++i)
	{
		scanf("%d%d%d",&p[i].h,&p[i].l,&p[i].r);
		a[i]=b[i]=i;
	}
	sort(a+1,a+n+1,cmp_l);
	sort(b+1,b+n+1,cmp_r);
	p[n+1]=(node){t,-INF,INF};
	p[n+2]=(node){0,-INF,INF};
	H[t]=n+1;
	H[0]=n+2;
	int j=1;
	for (int i=1;i<=n;++i)
	{
		deal(j,p[a[i]].l);
		H[p[a[i]].h]=a[i];
		map<int,int>::iterator it,itx,ity;
		it=itx=ity=H.find(p[a[i]].h);
		if (it!=H.begin())
		{
			--itx;
			addedge(it->Y,itx->Y);
		}
		if (++ity!=H.end())
		{
			addedge(ity->Y,it->Y);
		}
	}
	deal(j,INF);
}

bool cmp_h(pii a,pii b)
{
	return p[a.X].h>p[b.X].h;
}

vector<pii> w[MaxN];

int F[MaxN],u[MaxN];

int DP(int x)
{
	if (u[x]) return F[x];
	u[x]=1;
	for (vector<pii>::iterator it=w[x].begin();it!=w[x].end();++it)
		F[x]=max(F[x],min(DP(it->X),it->Y));
	return F[x];
}

void work()
{
	for (int i=1;i<=n+2;++i)
	{
		sort(v[i].begin(),v[i].end(),cmp_h);
		map<int,int> s;
		for (vector<pii>::iterator it=v[i].begin();it!=v[i].end();++it)
		{
			map<int,int>::iterator a,b,c;
			a=b=s.lower_bound(p[it->X].l);
			int flag=0;
			if (a!=s.begin())
			{
				--a;
				if (a->Y>p[it->X].l) flag=1;
			}
			if (b!=s.end())
			{
				if (b->X<p[it->X].r) flag=1;
			}
			if (!flag)
				w[i].push_back(*it);
			if (s.count(p[it->X].l))
				s[p[it->X].l]=max(s[p[it->X].l],p[it->X].r);
			else
				s[p[it->X].l]=p[it->X].r;
			a=b=s.find(p[it->X].l);
			if (b!=s.begin())
			{
				--b;
				if (b->Y>a->X)
				{
					b->Y=max(b->Y,a->Y);
					s.erase(a);
					a=b;
				}
			}
			while (1)
			{
				b=a;
				++b;
				if (b==s.end()) break;
				if (a->Y<b->X) break;
				a->Y=max(a->Y,b->Y);
				s.erase(b);
			}
		}
	}
	F[n+2]=INF*2;
	u[n+2]=1;
	cout<<DP(n+1)<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
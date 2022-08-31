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

int n,L,W;
vector<pii> v[MaxN];

void init()
{
	cin>>n>>L>>W;
	for (int i=2;i<=n;++i)
	{
		int p,w;
		scanf("%d%d",&p,&w);
		v[i].push_back(pii(p,w));
		v[p].push_back(pii(i,w));
	}
}

ll ans;
int head,tail,Q[MaxN];
int u[MaxN],size[MaxN],most[MaxN],pre[MaxN],dis[MaxN],deep[MaxN],belong[MaxN];
vector<pii> list,have[MaxN];

int a[MaxN];

void add(int x,int p)
{
	for (;x<=n;x+=x&-x)
		a[x]+=p;
}

int get(int x)
{
	int p=0;
	for (;x;x-=x&-x)
		p+=a[x];
	return p;
}

ll calc(vector<pii> &v)
{
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();++i)
		add(v[i].Y,1);
	int j=v.size()-1;
	ll ans=0;
	for (int i=0;i<v.size();++i)
	{
		while (j>=0)
		{
			if (v[i].X+v[j].X<=W) break;
			add(v[j].Y,-1);
			--j;
		}
		if (j<0) continue;
		ans+=get(max(L-v[i].Y,0));
	}
	for (;j>=0;--j)
		add(v[j].Y,-1);
	return ans;
}

void solve(int root)
{
	u[Q[head=tail=1]=root]=1;
	while (head<=tail)
	{
		int x=Q[head++];
		size[x]=1;
		most[x]=0;
		for (vector<pii>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!u[it->X])
			{
				u[Q[++tail]=it->X]=1;
				pre[it->X]=x;
			}
	}
	root=Q[tail];
	for (int k=tail;k>=1;--k)
	{
		int i=Q[k];
		size[pre[i]]+=size[i];
		most[pre[i]]=max(most[pre[i]],size[i]);
		most[i]=max(most[i],tail-size[i]);
		if (most[i]<most[root]) root=i;
		u[i]=0;
	}
	u[Q[head=tail=1]=root]=1;
	deep[root]=dis[root]=0;
	list.clear();
	for (vector<pii>::iterator it=v[root].begin();it!=v[root].end();++it)
		have[it->X].clear();
	while (head<=tail)
	{
		int x=Q[head++];
		for (vector<pii>::iterator it=v[x].begin();it!=v[x].end();++it)
			if (!u[it->X])
			{
				u[Q[++tail]=it->X]=1;
				deep[it->X]=deep[x]+1;
				dis[it->X]=dis[x]+it->Y;
				belong[it->X]=(x==root)?it->X:belong[x];
				list.push_back(pii(dis[it->X],deep[it->X]));
				have[belong[it->X]].push_back(pii(dis[it->X],deep[it->X]));
			}
	}
	ans+=calc(list);
	for (int i=2;i<=tail;++i)
		u[Q[i]]=0;
	for (vector<pii>::iterator it=v[root].begin();it!=v[root].end();++it)
		if (!u[it->X]) ans-=calc(have[it->X]);
	for (int k=2;k<=tail;++k)
	{
		int i=Q[k];
		if (deep[i]<=L&&dis[i]<=W) ans+=2;
	}
	for (vector<pii>::iterator it=v[root].begin();it!=v[root].end();++it)
		if (!u[it->X]) solve(it->X);
}

void work()
{
	solve(1);
	cout<<ans/2<<endl;
}

int main()
{
	init();
	work();
	return 0;
}
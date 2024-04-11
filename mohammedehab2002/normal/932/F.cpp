#include <iostream>
#include <assert.h>
#include <functional>
#include <vector>
#include <set>
using namespace std;
struct line
{
	long long m,b;
	mutable function<const line*()> succ;
	bool operator<(const line& rhs) const
	{
		if (rhs.b!=(1LL<<62))
		return (m<rhs.m);
		const line* s=succ();
		if (!s)
		return 0;
		return b-s->b<rhs.m*(s->m-m);
	}
};
struct hull:public multiset<line>
{
	bool bad(iterator y)
	{
		auto z=next(y);
		if (y==begin())
		{
			if (z==end())
			return 0;
			return (y->m==z->m && y->b<=z->b);
		}
		auto x=prev(y);
		if (z==end())
		return (y->m==x->m && y->b<=x->b);
		return 1.0*(x->b-y->b)*(z->m-y->m)>=1.0*(y->b-z->b)*(y->m-x->m);
	}
	void add(long long m,long long b)
	{
		auto it=insert({m,b});
		if (bad(it))
		{
			erase(it);
			return;
		}
		it->succ=[=]{return (next(it)==end()? 0:&*next(it));};
		while (next(it)!=end() && bad(next(it)))
		erase(next(it));
		while (it!=begin() && bad(prev(it)))
		erase(prev(it));
	}
	long long eval(long long x)
	{
		line l=*lower_bound((line){x,(1LL<<62)});
		return x*l.m+l.b;
	}
};
hull h;
int sz[100005];
long long a[100005],b[100005],dp[100005];
vector<int> v[100005];
void pre(int node,int p)
{
	sz[node]=1;
	for (int u:v[node])
	{
		if (u!=p)
		{
			pre(u,node);
			sz[node]+=sz[u];
		}
	}
}
void add(int node,int p)
{
	h.add(-b[node],-dp[node]);
	for (int u:v[node])
	{
		if (u!=p)
		add(u,node);
	}
}
void dfs(int node,int p,bool keep)
{
	int big=0;
	for (int u:v[node])
	{
		if (u!=p && sz[u]>sz[big])
		big=u;
	}
	for (int u:v[node])
	{
		if (u!=p && u!=big)
		dfs(u,node,0);
	}
	if (big)
	dfs(big,node,1);
	for (int u:v[node])
	{
		if (u!=p && u!=big)
		add(u,node);
	}
	if (!h.empty())
	dp[node]=-h.eval(a[node]);
	if (!keep)
	h.clear();
	else
	h.add(-b[node],-dp[node]);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&a[i]);
	for (int i=1;i<=n;i++)
	scanf("%I64d",&b[i]);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	pre(1,0);
	dfs(1,0,1);
	for (int i=1;i<=n;i++)
	printf("%I64d ",dp[i]);
}
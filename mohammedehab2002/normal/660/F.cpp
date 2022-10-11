#include <iostream>
#include <assert.h>
#include <functional>
#include <vector>
#include <set>
using namespace std;
bool query=0;
struct line
{
	long long m,b;
	mutable function<const line*()> succ;
	bool operator<(const line& rhs) const
	{
		if (!query)
		return m<rhs.m;
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
		it->succ=[=]{ return (next(it)==end())? 0:&*next(it); };
		if (bad(it))
		{
			erase(it);
			return;
		}
		while (next(it)!=end() && bad(next(it)))
		erase(next(it));
		while (it!=begin() && bad(prev(it)))
		erase(prev(it));
	}
	long long eval(long long x)
	{
		query=1;
		line l=*lower_bound((line){x,0});
		query=0;
		return l.m*x+l.b;
	}
};
hull h;
long long cum[200005],cumW[200005];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		long long a;
		scanf("%I64d",&a);
		cum[i]=cum[i-1]+a;
		cumW[i]=cumW[i-1]+i*a;
	}
	long long ans=0;
	h.add(0,0);
	for (int i=1;i<=n;i++)
	{
		ans=max(ans,cumW[i]+h.eval(cum[i]));
		h.add(-i,i*cum[i]-cumW[i]);
	}
	printf("%I64d",ans);
}
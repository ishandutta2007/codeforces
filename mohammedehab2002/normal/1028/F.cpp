#include <iostream>
#include <algorithm>
#include <complex>
#include <map>
#include <set>
using namespace std;
#define point complex<long long>
struct cmp
{
	bool operator()(const point &a,const point &b) const
	{
		if (a.real()==b.real())
		return a.imag()<b.imag();
		return a.real()<b.real();
	}
};
map<long long,set<point,cmp> > m;
map<point,int,cmp> cnt;
point normalize(point a)
{
	int g=__gcd(real(a),imag(a));
	return a/point(g,0);
}
void upd(long long r,point p,int a)
{
	for (auto p2:m[r])
	{
		cnt[normalize(p+p2)]+=a;
		cnt[normalize(p+p2)]+=a*(int)(p!=p2);
	}
}
int main()
{
	int q,c=0;
	scanf("%d",&q);
	while (q--)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		point p(x,y);
		long long r=norm(p);
		if (t==1)
		{
			c++;
			m[r].insert(p);
			upd(r,p,1);
		}
		else if (t==2)
		{
			c--;
			upd(r,p,-1);
			m[r].erase(p);
		}
		else
		printf("%d\n",c-cnt[normalize(p)]);
	}
}
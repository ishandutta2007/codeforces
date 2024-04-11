#include<cstdio>
#include<algorithm>
#define abs Mrabs
#define int long long
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::next_permutation;
const int inf=0x3f3f3f3f3f3f3f3f;
inline int abs(int x)
{
	return x<0?-x:x;
}
struct point
{
	int x,y;
	inline bool operator<(const point th) const
	{
		if(x!=th.x)
			return x<th.x;
		else
			return y<th.y;
	}
	inline void in()
	{
		scanf("%lld%lld",&x,&y);
	}
}p[4];
int ans,xmn,xmx,ymn,ymx;
inline int getans(int t)
{
	return 2*(max(0ll,xmn-t)+max(0ll,t-xmx)+max(0ll,ymn-t)+max(0ll,t-ymx));
}
inline void solve()
{
	int base;
	register int i,j;
	for(i=0;i<4;i++)
		p[i].in();
	ans=inf;sort(p,p+4);
	do
	{
		xmn=ymn=inf;xmx=ymx=-inf;base=0;
		base+=abs(p[0].x-p[1].x)+abs(p[2].x-p[3].x);
		for(i=0;i<2;i++)
			for(j=2;j<4;j++)
				xmn=min(xmn,abs(p[i].x-p[j].x)),xmx=max(xmx,abs(p[i].x-p[j].x));
		swap(p[1],p[2]);
		base+=abs(p[0].y-p[1].y)+abs(p[2].y-p[3].y);
		for(i=0;i<2;i++)
			for(j=2;j<4;j++)
				ymn=min(ymn,abs(p[i].y-p[j].y)),ymx=max(ymx,abs(p[i].y-p[j].y));
		swap(p[1],p[2]);
		ans=min(ans,getans(xmn)+base);
		ans=min(ans,getans(xmx)+base);
		ans=min(ans,getans(ymn)+base);
		ans=min(ans,getans(ymx)+base);
	}while(next_permutation(p,p+4));
	printf("%lld\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%lld",&T);
	while(T--)
		solve();
	return 0;
}
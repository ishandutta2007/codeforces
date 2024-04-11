#include<cstdio>
#include<algorithm>
using std::sort;
const int N=3e5+5;
int n;
struct cell
{
	int id,l,r;
}e[N];
inline bool cmp(cell a,cell b)
{
	if(a.l!=b.l)
		return a.l<b.l;
	return a.r>b.r;
}
signed main()
{
	int now;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		e[i].id=i;
		scanf("%d%d",&e[i].l,&e[i].r);
	}
	sort(e+1,e+n+1,cmp);
	now=n;
	for(i=n-1;i>=1;i--)
	{
		if(e[now].r<=e[i].r)
		{
			printf("%d %d\n",e[now].id,e[i].id);
			return 0;
		}
		if(e[i].r<e[now].r)
			now=i;
	}
	puts("-1 -1");
	return 0;
}
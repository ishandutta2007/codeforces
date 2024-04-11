#include<cstdio>
#include<algorithm>
using std::sort;
const int N=1e5+5;
int n;
struct point
{
	int x,y;
}a[N],b[N];
signed main()
{
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	for(i=1;i<=n;i++)
		scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+n+1,[](point p,point q)->bool
	{
		if(p.x!=q.x)
			return p.x<q.x;
		return p.y<q.y;
	});
	sort(b+1,b+n+1,[](point p,point q)->bool
	{
		if(p.x!=q.x)
			return p.x>q.x;
		return p.y>q.y;
	});
	printf("%d %d\n",a[1].x+b[1].x,a[1].y+b[1].y);
	return 0;
}
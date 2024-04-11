#include<cstdio>
#include<algorithm>
#include<cmath>
#define min(a,b) (a<b?a:b)
#define int long long
const int N(1e6+5);
int n,ans;
struct node
{
	int a,l;
}e[N];
inline bool cmpext(node x,node y)
{
	return x.a<y.a; 
}
inline bool cmp(node x,node y)
{
	return x.l<y.l;
}
inline int len(int x)
{
	int i=(int)sqrt(x);
	return min(x-i*i,(i+1)*(i+1)-x);
}
signed main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&e[i].a);
		e[i].l=len(e[i].a);
	}
	std::sort(e+1,e+n+1,cmpext);
	std::stable_sort(e+1,e+n+1,cmp);
	for(int i=1;i<=n>>1;i++)
		ans+=e[i].l;
	for(int i=(n>>1)+1;i<=n;i++)
		if(!e[i].l)
		{
			ans++;
			if(!e[i].a)
				ans++;
		}
	printf("%I64d\n",ans);
	return 0;
}
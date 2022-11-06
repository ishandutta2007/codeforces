#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define int long long
using std::random_shuffle;
using std::sort;
const int N=1e6+5;
int n,ans;
int x[N],y[N];
int p[N],res[N],best[N];
int ansx,ansy;
inline bool cmp(int a,int b)
{
	return sqr(x[a])+sqr(y[a])>sqr(x[b])+sqr(y[b]);
}
signed main()
{
	int T=30;
	register int i;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for(i=1;i<=n;i++)
		p[i]=i;
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(sqr(ansx+x[p[i]])+sqr(ansy+y[p[i]])<sqr(ansx-x[p[i]])+sqr(ansy-y[p[i]]))
			ansx+=x[p[i]],ansy+=y[p[i]],res[p[i]]=1;
		else
			ansx-=x[p[i]],ansy-=y[p[i]],res[p[i]]=-1;
	}
	ans=sqr(ansx)+sqr(ansy);
	memmove(best+1,res+1,sizeof(int)*n);
	while(T--)
	{
		ansx=0;ansy=0;
		random_shuffle(p+1,p+n+1);
		for(i=1;i<=n;i++)
		{
			if(sqr(ansx+x[p[i]])+sqr(ansy+y[p[i]])<sqr(ansx-x[p[i]])+sqr(ansy-y[p[i]]))
				ansx+=x[p[i]],ansy+=y[p[i]],res[p[i]]=1;
			else
				ansx-=x[p[i]],ansy-=y[p[i]],res[p[i]]=-1;
		}
		if(sqr(ansx)+sqr(ansy)<ans)
		{
			ans=sqr(ansx)+sqr(ansy);
			memmove(best+1,res+1,sizeof(int)*n);
		}
	}
	for(i=1;i<=n;i++)
		printf("%lld ",best[i]);
	putchar('\n');
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using std::sort;
using std::vector;
inline int abs(int x)
{
	return x<0?-x:x;
}
const int N=2005;
struct edge
{
	int u,v,w;
};
int n,ans;
int c[N],k[N],x[N],y[N];
int cbk,bk[N];
vector<edge> E,ET;
int dis[N];
inline int dist(int i,int j)
{
	return (k[i]+k[j])*(abs(x[i]-x[j])+abs(y[i]-y[j]));
}
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
signed main()
{
	register int i,j;
	scanf("%lld",&n);
	for(i=1;i<=n+1;i++)
		dis[i]=i;
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&x[i],&y[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	for(i=1;i<=n;i++)
		scanf("%lld",&k[i]);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			E.push_back(edge{i,j,dist(i,j)});
	for(i=1;i<=n;i++)
		E.push_back(edge{i,n+1,c[i]});
	sort(E.begin(),E.end(),[](edge a,edge b)->bool
	{
		return a.w<b.w;
	});
	for(edge e:E)
		if(find(e.u)!=find(e.v))
		{
			ans+=e.w;dis[find(e.u)]=find(e.v);
			if(e.v==n+1)
				cbk++,bk[e.u]=1;
			else
				ET.push_back(e);
		}
	printf("%lld\n",ans);
	printf("%lld\n",cbk);
	for(i=1;i<=n;i++)
		if(bk[i])
			printf("%lld ",i);
	putchar('\n');
	printf("%lld\n",(int)ET.size());
	for(edge e:ET)
		printf("%lld %lld\n",e.u,e.v);
	return 0;
}
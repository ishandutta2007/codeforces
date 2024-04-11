#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n;
int w[N],deg[N],p[N],rk[N];
int ans[N];
vector<int> e[N];
set<pair<int,int> > S;
//struct edge
//{
//	int u,v,w;
//};
//vector<edge> E;

inline void solve()
{
	int x,y;
	register int i,j;
	scanf("%lld",&n);S.clear();
	for(i=1;i<=n;i++)
		e[i].clear();
	for(i=1;i<=n;i++)
		scanf("%lld",&w[i]),p[i]=i;
	memset(deg+1,0,sizeof(int)*n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld%lld",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
		deg[x]++;deg[y]++;
	}
	sort(p+1,p+n+1,[](int x,int y)->bool
	{
		return w[x]<w[y];
	});
	ans[n-1]=0;
	for(i=1;i<=n;i++)
		ans[n-1]+=deg[i]*w[i];
	int cur=n-1;
	for(i=1;i<=n;i++)
	{
		x=p[i];
		for(j=1;j<=deg[x]-1;j++)
			ans[cur-1]=ans[cur]-w[x],cur--;
	}
	for(i=1;i<=n-1;i++)
		printf("%lld%c",ans[i],i==n-1?'\n':' ');
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
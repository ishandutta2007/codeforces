#include<cstdio>
#include<cstring>
const int N=1e5+5;
int n,m,ans;
int r[N],c[N],suc[N],vis[N];
inline void run(int x)
{
	int ro=x;
	if(suc[x]==x||suc[x]==0)
		return;
	for(;!vis[x]&&suc[x];x=suc[x])
		vis[x]=1,ans++;
	if(x==ro)
		ans++;
	return;
}
inline void solve()
{
	register int i;
	scanf("%d%d",&n,&m);ans=0;
	memset(suc+1,0,sizeof(int)*n);
	memset(vis+1,0,sizeof(int)*n);
	for(i=1;i<=m;i++)
		scanf("%d%d",&r[i],&c[i]),suc[r[i]]=c[i];
	for(i=1;i<=n;i++)
		if(!vis[i])
			run(i);
	printf("%d\n",ans);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}
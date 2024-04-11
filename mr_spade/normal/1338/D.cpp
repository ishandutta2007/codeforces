#include<cstdio>
#include<vector>
using std::vector;
using std::max;
const int N=1e5+5;
int n,ans;
vector<int> e[N];
int f[N],g[N];
void dfs(int x,int father)
{
	int cnt=0;
	for(int y:e[x])
		if(y!=father)
			cnt++;
	for(int y:e[x])
		if(y!=father)
		{
			dfs(y,x);
			ans=max(ans,f[y]+g[x]+1);
			ans=max(ans,f[y]+f[x]-1+(father!=0));
			ans=max(ans,g[y]+f[x]+(father!=0));
			g[x]=max(g[x],f[y]);
			f[x]=max(f[x],f[y]+cnt-1);
			f[x]=max(f[x],g[y]+cnt);
		}
	ans=max(ans,f[x]+(father!=0));
	return;
}
signed main()
{
	int x,y;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	printf("%d\n",ans);
	return 0;
}
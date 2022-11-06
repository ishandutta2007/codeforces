#include<cstdio>
const int N=1e5+5;
int n,ans;
int size[N];
int v[N<<1],first[N],next[N<<1];
void dfs(int now,int father)
{
	register int go;
	size[now]=1;
	for(go=first[now];go;go=next[go])
		if(v[go]!=father)
			dfs(v[go],now),size[now]+=size[v[go]];
	return;
}
signed main()
{
	register int i;
	scanf("%d",&n);
	if(n&1)
		return puts("-1"),0;
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&v[i+n-1],&v[i]);
		next[i]=first[v[i+n-1]];first[v[i+n-1]]=i;
		next[i+n-1]=first[v[i]];first[v[i]]=i+n-1;
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
		if(!(size[i]&1))
			ans++;
	printf("%d\n",ans-1);
	return 0;
}
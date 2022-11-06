#include<cstdio>
const int N=2e5+5;
int n,tot=1;
int father[N],ind[N],degree[N];
int v[N<<1],first[N],next[N<<1];
void dfs(int now,int p)
{
	register int go;
	father[now]=p;
	for(go=first[now];go;go=next[go])
		if(v[go]!=father[now])
		{
			dfs(v[go],now);
			if(!(degree[v[go]]&1))
				degree[now]--,ind[v[go]]=0;
			else
				ind[v[go]]=1;
		}
	return;
}
void dfs2(int now)
{
	register int go;
	for(go=first[now];go;go=next[go])
		if(v[go]!=father[now]&&!ind[v[go]])
			dfs2(v[go]);
	printf("%d\n",now);
	for(go=first[now];go;go=next[go])
		if(v[go]!=father[now]&&ind[v[go]])
			dfs2(v[go]);
	return;
}
signed main()
{
	int from,to;
	register int i;
	scanf("%d",&n);
	if(!(n&1))
		return puts("NO"),0;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&from);to=i;
		if(from)
		{
			degree[from]++;degree[to]++;
			v[tot+1]=from;v[tot]=to;
			next[tot]=first[from];first[from]=tot;
			next[tot+1]=first[to];first[to]=tot+1;tot+=2;
		}
	}
	dfs(1,0);
	if(degree[1]&1)
		return puts("NO"),0;
	puts("YES");
	dfs2(1);
	return 0;
}
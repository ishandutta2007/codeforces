#include<cstdio>
#include<stack>
#define index Mr_Spade
using std::stack;
const int N=2e5+5;
int n,m,t,tot,index;
int u[N];
int v[N<<1],first[N],next[N<<1];
int degree[N];
int dfn[N],low[N],com[N],cnt[N];
bool instack[N];
stack<int> st;
inline void add_edge(int from,int to)
{
	tot++;
	v[tot]=to;next[tot]=first[from];first[from]=tot;
	return;
}
void dfs(int now)
{
	register int go;
	dfn[now]=low[now]=++index;
	st.push(now);instack[now]=1;
	for(go=first[now];go;go=next[go])
		if(!dfn[v[go]])
		{
			dfs(v[go]);
			if(low[v[go]]<low[now])
				low[now]=low[v[go]];
		}
		else if(instack[v[go]]&&dfn[v[go]]<low[now])
			low[now]=dfn[v[go]];
	if(dfn[now]==low[now])
	{
		com[now]=++tot;
		while(st.top()!=now)
		{
			com[st.top()]=tot;
			cnt[tot]++;
			instack[st.top()]=0;
			st.pop();
		}
		cnt[tot]++;
		instack[now]=0;
		st.pop();
	}
	return;
}
signed main()
{
	int a,b;
	register int i,go;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++)
		scanf("%d",&u[i]);
	while(m--)
	{
		scanf("%d%d",&a,&b);
		if((u[a]+1)%t==u[b])
			add_edge(b,a);
		if((u[b]+1)%t==u[a])
			add_edge(a,b);
	}
	tot=0;
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(i=1;i<=n;i++)
		for(go=first[i];go;go=next[go])
			if(com[i]!=com[v[go]])
				degree[com[v[go]]]++;
	int ans=0;
	for(i=1;i<=tot;i++)
		if(!degree[i])
			if(!ans||cnt[i]<cnt[ans])
				ans=i;
	printf("%d\n",cnt[ans]);
	for(i=1;i<=n;i++)
		if(com[i]==ans)
			printf("%d ",i);
	putchar('\n');
	return 0;
}
#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define index Mr_Spade
using std::sort;
using std::vector;
using std::stack;
const int N=1e5+5,M=1e5+5;
int n,index,cnt,tot;
int v[M],first[N],next[M];
int dfn[N],low[N],com[N];
bool inst[N];
stack<int> st;
inline void add_edge(int from,int to)
{
	v[++tot]=to;next[tot]=first[from];first[from]=tot;
	return;
}
void dfs(int now)
{
	register int go;
	dfn[now]=low[now]=++index;
	st.push(now);inst[now]=1;
	for(go=first[now];go;go=next[go])
		if(!dfn[v[go]])
		{
			dfs(v[go]);
			if(low[v[go]]<low[now])
				low[now]=low[v[go]];
		}
		else if(inst[v[go]]&&dfn[v[go]]<low[now])
			low[now]=dfn[v[go]];
	if(low[now]==dfn[now])
	{
		com[now]=++cnt;
		while(st.top()!=now)
		{
			com[st.top()]=cnt;
			inst[st.top()]=0;
			st.pop();
		}
		st.pop();
	}
	return;
}
inline void scc()
{
	register int i;
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	return;
}
namespace b_m
{
	const int N=1e5+5;
	int n;
	int a[N],p[N],rank[N];
	vector<int> V[N];
	inline bool cmp(int x,int y)
	{
		return a[x]<a[y];
	}
	inline void input()
	{
		register int i;
		scanf("%d",&n);::n=n;
		for(i=1;i<=n;i++)
			p[i]=i,scanf("%d",&a[i]);
		sort(p+1,p+n+1,cmp);
		for(i=1;i<=n;i++)
			rank[p[i]]=i;
		for(i=1;i<=n;i++)
			add_edge(i,rank[i]);
		return;
	}
	inline void output()
	{
		register int i,j;
		scc();
		printf("%d\n",cnt);
		for(i=1;i<=n;i++)
			V[com[i]].push_back(i);
		for(i=1;i<=cnt;i++)
		{
			printf("%d ",V[i].size());
			for(j=0;j<(int)V[i].size();j++)
				printf("%d ",V[i][j]);
			putchar('\n');
		}
		return;
	}
}
signed main()
{
	b_m::input();
	b_m::output();
	return 0;
}
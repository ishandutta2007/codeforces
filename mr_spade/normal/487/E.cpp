#pragma GCC optimize("Ofast","inline")
#include<cstdio>
#include<vector>
#include<set>
#include<stack>
using std::min;
using std::swap;
using std::vector;
using std::multiset;
using std::stack;
const int N=2e5+5,M=1e6+5,inf=0x3f3f3f3f;
int n,m,q,idx,tot,cnt;
int a[N];
int dfn[N],low[N];
int v[M<<1],first[N],next[M<<1];
vector<int> g[N];
multiset<int> S[N];
stack<int> st;
int id[N],father[N],hson[N],deep[N],size[N],top[N];
namespace zkw_sgt
{
	int M,sgt[N<<2];
	inline void build(int n)
	{
		register int i;
		for(M=1;M<=n;M<<=1);
		for(i=1;i<=M+n;i++)
			sgt[i]=inf;
		return;
	}
	inline void modify(int pos,int k)
	{
		register int i;
		sgt[M+pos]=k;
		for(i=(M+pos)>>1;i;i>>=1)
			sgt[i]=min(sgt[i<<1],sgt[i<<1|1]);
		return;
	}
	inline int query(int l,int r)
	{
		int res=inf;
		for(l=M+l-1,r=M+r+1;l^r^1;l>>=1,r>>=1)
			res=min(res,min((l&1)?inf:sgt[l^1],(r&1)?sgt[r^1]:inf));
		return res;
	}
}
inline void add_edge(int from,int to)
{
	tot+=2;
	v[tot+1]=from;v[tot]=to;
	next[tot]=first[from];first[from]=tot;
	next[tot+1]=first[to];first[to]=tot+1;
	return;
}
inline void tree_add_edge(int from,int to)
{
	g[from].push_back(to);
	g[to].push_back(from);
	return;
}
void dfs(int now,int pe)
{
	register int go;
	dfn[now]=low[now]=++idx;
	for(go=first[now];go;go=next[go])
	{
		if((go^1)==pe)
			continue;
		if(!dfn[v[go]])
		{
			st.push(go);
			dfs(v[go],go);
			if(low[v[go]]<low[now])
				low[now]=low[v[go]];
		}
		else if(dfn[v[go]]<low[now])
			low[now]=dfn[v[go]];
	}
	if(low[now]>=dfn[v[pe^1]])
	{
		cnt++;
		while(!st.empty()&&st.top()!=pe)
		{
			tree_add_edge(cnt,v[st.top()]);
			st.pop();
		}
		tree_add_edge(cnt,now);
		if(!st.empty()&&st.top()==pe)
		{
			tree_add_edge(cnt,v[pe^1]);
			st.pop();
		}
	}
	return;
}
void dfs1(int now)
{
	vector<int>::iterator it;
	if(father[now]>n)
		S[father[now]].insert(a[now]);
	size[now]=1;deep[now]=deep[father[now]]+1;
	for(it=g[now].begin();it!=g[now].end();it++)
		if(*it!=father[now])
		{
			father[*it]=now;
			dfs1(*it);
			if(!hson[now]||size[*it]>size[hson[now]])
				hson[now]=*it;
			size[now]+=size[*it];
		}
	return;
}
void dfs2(int now,int root)
{
	vector<int>::iterator it;
	id[now]=++idx;top[now]=root;
	if(now>n)
		zkw_sgt::modify(id[now],*S[now].begin());
	else
		zkw_sgt::modify(id[now],a[now]);
	if(hson[now])
		dfs2(hson[now],root);
	for(it=g[now].begin();it!=g[now].end();it++)
		if(*it!=father[now]&&*it!=hson[now])
			dfs2(*it,*it);
	return;
}
inline int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		x=father[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	return y;
}
inline int query(int x,int y)
{
	int res=inf;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		res=min(res,zkw_sgt::query(id[top[x]],id[x]));
		x=father[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	res=min(res,zkw_sgt::query(id[y],id[x]));
	return res;
}
char s[100];
signed main()
{
	int u,v,w;
	register int i;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	cnt=n;dfs(1,0);idx=0;
	zkw_sgt::build(cnt);
	for(i=n+1;i<=cnt;i++)
		S[i].insert(inf);
	dfs1(1);
	dfs2(1,1);
	while(q--)
	{
		scanf("%s%d%d",s,&u,&v);
		if(s[0]=='C')
		{
			zkw_sgt::modify(id[u],v);
			if(u!=1)
			{
				S[father[u]].erase(S[father[u]].find(a[u]));
				S[father[u]].insert(v);
				zkw_sgt::modify(id[father[u]],*S[father[u]].begin());
			}
			a[u]=v;
		}
		else
		{
			w=lca(u,v);
			if(w>n)
				printf("%d\n",min(query(u,v),a[father[w]]));
			else
				printf("%d\n",query(u,v));
		}
	}
	return 0;
}
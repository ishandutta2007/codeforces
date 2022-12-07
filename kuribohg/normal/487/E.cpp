#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<set>
#include<vector>
using namespace std;
const int MAXN=400010;
const int INF=1000000000;
int n,m,Q,weight[MAXN];
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int low[MAXN],dfn[MAXN],inv[MAXN],dfs_clock,tot;
bool is_cut[MAXN];
int belongn[MAXN],id[MAXN],who[MAXN],max_id;
vector<int> bcc[MAXN];
void Tarjan(int x,int father)
{
	static pair<int,int> S[MAXN];
	static int top;
	low[x]=dfn[x]=++dfs_clock;
	int ch=0;
	for(int i=head[x];i;i=next[i])
	{
		if((i^father)==1) continue;
		ch++;
		if(!dfn[to[i]])
		{
			S[++top]=make_pair(x,to[i]);
			Tarjan(to[i],i);
			low[x]=min(low[x],low[to[i]]);
			if(low[to[i]]>=dfn[x])
			{
				if(x!=1) is_cut[x]=true;
				++tot;
				pair<int,int> tmp,now;
				tmp=make_pair(x,to[i]);
				now=make_pair(-1,-1);
				while(now!=tmp)
				{
					now=S[top--];
					if(belongn[now.first]!=tot)
						belongn[now.first]=tot,bcc[tot].push_back(now.first);
					if(belongn[now.second]!=tot)
						belongn[now.second]=tot,bcc[tot].push_back(now.second);
				}
			}
		}
		else if(dfn[to[i]]<dfn[x])
		{
			S[++top]=make_pair(x,to[i]);
			low[x]=min(low[x],dfn[to[i]]);
		}
	}
	if(father==0&&ch>=2) is_cut[x]=true;
}
int dep[MAXN],size[MAXN],son[MAXN],top[MAXN],fa[MAXN];
multiset<int> S[MAXN];
void DFS(int x)
{
	size[x]=1;
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa[x])
		{
			dep[to[i]]=dep[x]+1;
			fa[to[i]]=x;
			DFS(to[i]);
			size[x]+=size[to[i]];
			if(size[to[i]]>size[son[x]]) son[x]=to[i];
		}
}
void BuildTree(int x,int tp)
{
	dfn[x]=++dfs_clock,top[x]=tp,inv[dfs_clock]=x;
	if(son[x]) BuildTree(son[x],tp);
	for(int i=head[x];i;i=next[i])
		if(to[i]!=son[x]&&to[i]!=fa[x])
			BuildTree(to[i],to[i]);
}
struct Node
{
	int l,r;
	int Min;
}T[MAXN<<2];
void MakeTree(int x,int l,int r)
{
	T[x].l=l,T[x].r=r;
	if(l==r) {T[x].Min=(*S[inv[l]].lower_bound(-1));return;}
	int mid=(l+r)>>1;
	MakeTree(x<<1,l,mid);
	MakeTree(x<<1|1,mid+1,r);
	T[x].Min=min(T[x<<1].Min,T[x<<1|1].Min);
}
void Change(int x,int pos,int tar)
{
	if(T[x].l==T[x].r) {T[x].Min=tar;return;}
	int mid=(T[x].l+T[x].r)>>1;
	if(pos<=mid) Change(x<<1,pos,tar);
	else Change(x<<1|1,pos,tar);
	T[x].Min=min(T[x<<1].Min,T[x<<1|1].Min);
}
int Query(int x,int l,int r)
{
	if(T[x].l==l&&T[x].r==r) return T[x].Min;
	int mid=(T[x].l+T[x].r)>>1;
	if(r<=mid) return Query(x<<1,l,r);
	else if(l>mid) return Query(x<<1|1,l,r);
	else return min(Query(x<<1,l,mid),Query(x<<1|1,mid+1,r));
}
int LCA;
int TreeQuery(int p,int q)
{
	int ans=INF;
	while(top[p]!=top[q])
	{
		if(dep[top[p]]<dep[top[q]]) swap(p,q);
		ans=min(ans,Query(1,dfn[top[p]],dfn[p]));
		p=fa[top[p]];
	}
	if(dfn[p]<dfn[q]) ans=min(ans,Query(1,dfn[p],dfn[q])),LCA=p;
	else ans=min(ans,Query(1,dfn[q],dfn[p])),LCA=q;
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),adde(x,y);
	Tarjan(1,0);
	max_id=tot;
	for(int i=1;i<=n;i++) head[i]=0;
	cnt=1;
	for(int i=1;i<=n;i++)
		if(is_cut[i]) id[i]=++max_id,who[id[i]]=i;
		else id[i]=belongn[i];
	for(int i=1;i<=tot;i++)
		for(int j=0;j<bcc[i].size();j++)
			if(is_cut[bcc[i][j]]) adde(id[bcc[i][j]],i);
	DFS(1);
	dfs_clock=0;
	BuildTree(1,1);
	for(int i=1;i<=n;i++)
		if(!is_cut[i]) S[id[i]].insert(weight[i]);
		else S[fa[id[i]]].insert(weight[i]);
	for(int i=1;i<=max_id;i++) S[i].insert(INF);
	MakeTree(1,1,max_id);
	while(Q--)
	{
		char c[10];
		int a,b;
		scanf("%s%d%d",c,&a,&b);
		if(c[0]=='A')
		{
			if(a==b) {printf("%d\n",weight[a]);continue;}
			int ans=TreeQuery(id[a],id[b]);
			if(LCA>tot) ans=min(ans,weight[who[LCA]]);
			else if(fa[LCA]!=0) ans=min(ans,weight[who[fa[LCA]]]);
			printf("%d\n",ans);
		}
		else
		{
			if(is_cut[a])
			{
				int o=fa[id[a]];
				S[o].erase(S[o].find(weight[a]));
				weight[a]=b;
				S[o].insert(b);
				Change(1,dfn[o],*S[o].lower_bound(-1));
			}
			else
			{
				S[id[a]].erase(S[id[a]].find(weight[a]));
				weight[a]=b;
				S[id[a]].insert(b);
				Change(1,dfn[id[a]],*S[id[a]].lower_bound(-1));
			}
		}
	}
	return 0;
}
#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int fib[MaxN]={1,1,2,3,5};
int pit[MaxN]={0,1,2,3,0};
inline void Initalize(const register int len)
{
	register int pos=3;
	do
	{
		++pos;
		fib[pos]=fib[pos-1]+fib[pos-2];
		pit[fib[pos]]=pos;
	}
	while(fib[pos]<=len);
}
struct Vertex
{
	int idx;
	int fa;
	int siz;
	int head;
};
Vertex vt[MaxN];
struct Edge
{
	int u;
	int v;
	bool ok;
	int next;
};
Edge ed[MaxN];
inline void add_edge(const register int u,const register int v,const register int pos)
{
	ed[pos].u=u;
	ed[pos].v=v;
	ed[pos].ok=true;
	ed[pos].next=vt[u].head;
	vt[u].head=pos;
}
inline bool CheckHeart(const register int len,const register int u)
{
	if(((len-vt[u].siz)<<1)>len)
		return false;
	register int v;
	for(register int e=vt[u].head;e;e=ed[e].next)
	{
		if(!ed[e].ok)
			continue;
		if(!ed[ed[e].next].ok)
			ed[e].next=ed[ed[e].next].next;
		v=ed[e].v;
		if(v==vt[u].fa)
			continue;
		if((vt[v].siz<<1)>len)
			return false;
	}
	return true;
}
inline void Dfs_Basics(const register int len,const register int u,register int& Heart)
{
	register int v;
	vt[u].siz=1;
	for(register int e=vt[u].head;e;e=ed[e].next)
	{
		if(!ed[e].ok)
			continue;
		if(!ed[ed[e].next].ok)
			ed[e].next=ed[ed[e].next].next;
		v=ed[e].v;
		if(v==vt[u].fa)
			continue;
		vt[v].fa=u;
		vt[v].idx=e;
		Dfs_Basics(len,v,Heart);
		vt[u].siz+=vt[v].siz;
	}
	if(CheckHeart(len,u))
		Heart=u;
}
inline void SetRoot(const register int len,const register int u,register int& Heart)
{
	vt[u].fa=0;
	vt[u].idx=0;
	Dfs_Basics(len,u,Heart);
}
inline void GainRoot(const register int len,const register int u,register int& Root)
{
	register int temp;
	SetRoot(len,u,Root);
	SetRoot(len,Root,temp);
}
inline void GetSpecial(const register int x,const register int u,register int& t1,register int& t2)
{
	register int v;
	for(register int e=vt[u].head;e;e=ed[e].next)
	{
		if(!ed[e].ok)
			continue;
		if(!ed[ed[e].next].ok)
			ed[e].next=ed[ed[e].next].next;
		v=ed[e].v;
		if(v==vt[u].fa)
			continue;
		GetSpecial(x,v,t1,t2);
	}
	if(vt[u].siz==x)
		((t1==0)?(t1=u):(t2=u));
}
inline bool Check(const register int len,const register int u)
{
	if(pit[len]==0)
		return false;
	if(pit[len]<=3)
		return true;
	register int Root,t1=0,t2=0;
	GainRoot(len,u,Root);
	GetSpecial(fib[pit[len]-2],Root,t1,t2);
	if(t1==0&&t2==0)
		return false;
	if(t2==0)
	{
		ed[vt[t1].idx].ok=false;
		ed[vt[t1].idx^1].ok=false;
		return Check(fib[pit[len]-2],t1)&&Check(fib[pit[len]-1],Root);
	}
	ed[vt[t1].idx].ok=false;
	ed[vt[t2].idx].ok=false;
	ed[vt[t1].idx^1].ok=false;
	ed[vt[t2].idx^1].ok=false;
	return Check(fib[pit[len]-2],t1)&&Check(fib[pit[len]-3],Root)&&Check(fib[pit[len]-2],t2);
}
int main()
{
	register int n;
	scanf("%d",&n);
	Initalize(n);
	register int u,v;
	rep(i,2,n)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v,i+i-2);
		add_edge(v,u,i+i-1);
	}
	if(Check(n,1))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
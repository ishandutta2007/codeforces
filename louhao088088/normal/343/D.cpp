#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0;
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return x;
}
#define ls rt<<1
#define rs rt<<1|1
const int maxn=500005*4;
struct edge
{
	int v,nex;
}e[maxn];
struct tree
{
	int l,r,num,tag;
}tr[maxn];
int head[maxn],a[maxn],n,m,r,op,x,y,cnt=0,z;
int s[maxn],son[maxn],fa[maxn],h[maxn],top[maxn],id[maxn],idx=0,b[maxn];
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt; }
void dfs1(int u)
{
	h[u]=h[fa[u]]+1;s[u]=1;
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(fa[u]==v)continue;
		fa[v]=u;dfs1(v);s[u]+=s[v];
		if(s[son[u]]<s[v])son[u]=v;
	}
} 
void dfs2(int u,int topp)
{
	id[u]=++idx;
	b[idx]=a[u];
	top[u]=topp;
	if(son[u])dfs2(son[u],topp);
	for(int i=head[u];i;i=e[i].nex)
	{
		int v=e[i].v;
		if(v==fa[u]||v==son[u])continue;
		dfs2(v,v);
	}
}
void push(int rt)
{
	if(tr[rt].tag!=-1)
	{
		tr[ls].tag=tr[rt].tag,tr[rs].tag=tr[rt].tag;
		tr[ls].num=(tr[rt].tag*(tr[ls].r-tr[ls].l+1));
		tr[rs].num=(tr[rt].tag*(tr[rs].r-tr[rs].l+1));
		tr[rt].tag=-1;
	}
}
void build(int rt,int l,int r)
{
	tr[rt].l=l,tr[rt].r=r;tr[rt].tag=-1;
	if(l==r)
	{
		tr[rt].num=b[l];return;
	}
	int mid=l+r>>1;
	build(ls,l,mid),build(rs,mid+1,r);
	tr[rt].num=tr[ls].num+tr[rs].num;
}
void Plus(int rt,int l,int r,int z)
{
	if(tr[rt].l>r||tr[rt].r<l)return;
	if(tr[rt].l>=l&&tr[rt].r<=r)
	{
		tr[rt].num=z*(tr[rt].r-tr[rt].l+1);
		tr[rt].tag=z;return;
	}
	push(rt);
	Plus(ls,l,r,z),Plus(rs,l,r,z);
	tr[rt].num=(tr[ls].num+tr[rs].num);
}
int query(int rt,int l,int r)
{
	if(tr[rt].l>r||tr[rt].r<l)return 0;
	if(tr[rt].l>=l&&tr[rt].r<=r)return tr[rt].num;
	push(rt);
	return (query(ls,l,r)+query(rs,l,r));
}
void treePlus(int x,int y,int z)
{
	while(top[x]!=top[y])
    {
        if(h[top[x]]<h[top[y]])swap(x,y);
        Plus(1,id[top[x]],id[x],z);
        x=fa[top[x]];
    }
    if(h[x]>h[y])swap(x,y);
    Plus(1,id[x],id[y],z);
}
int treequery(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
    {
        if(h[top[x]]<h[top[y]])swap(x,y);
        ans=(ans+query(1,id[top[x]],id[x]));
        x=fa[top[x]];
    }
    if(h[x]>h[y])swap(x,y);
    ans=(ans+query(1,id[x],id[y]));
    return ans;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)x=read(),y=read(),add(x,y),add(y,x);
	dfs1(1),dfs2(1,1);
	build(1,1,n);m=read();
	for(int i=1;i<=m;i++)
	{
		op=read();
		if(op==2)
			x=read(),treePlus(x,1,0);
		if(op==3)
			x=read(),printf("%d\n",treequery(x,x));
		if(op==1)
			x=read(),Plus(1,id[x],id[x]+s[x]-1,1);
	}
	return 0;
}
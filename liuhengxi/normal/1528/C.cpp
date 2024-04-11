#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc ((p<<1)|1)
#define empty n
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int tt,n,ans;
int siz[N],dfn[N],ind;
struct segtree
{
	int tag[N<<2],ans;
	void build(int p,int l,int r)
	{
		int mid=(l+r)>>1;
		tag[p]=-1;
		if(r-l>1)build(lc,l,mid),build(rc,mid,r);
	}
	void pushdown(int p){if(~tag[p])tag[lc]=tag[rc]=tag[p],tag[p]=-1;}
	void update(int p,int l,int r,int x,int y,int v)
	{
		int mid=(l+r)>>1;
		if(y<=l||r<=x)return;
		if(x<=l&&r<=y)return tag[p]=v,void();
		pushdown(p);
		update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
	}
	int query(int p,int l,int r,int x)
	{
		int mid=(l+r)>>1;
		if(r-l==1)return tag[p];
		pushdown(p);
		if(x<mid)return query(lc,l,mid,x);
		else return query(rc,mid,r,x);
	}
	void build(){build(1,0,n);ans=0;}
	void update(int x,int y,int v){update(1,0,n,x,y,v);}
	int query(int x){int ans=query(1,0,n,x);return ans==empty?-1:ans;}
}s;
struct tree
{
	int hd[N],cnt;
	struct line
	{
		int next,to;
	}e[N];
	void init(int n){F(i,cnt=0,n)hd[i]=-1;}
	void adline(int u,int v)
	{
		e[cnt].to=v;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void dfs2(int u)
	{
		siz[u]=1;
		dfn[u]=ind++;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			dfs2(v);
			siz[u]+=siz[v];
		}
	}
	void dfs1(int u)
	{
		int fa=s.query(dfn[u]);
		if(~fa)s.update(dfn[fa],dfn[fa]+siz[fa],empty),--s.ans;
		s.update(dfn[u],dfn[u]+siz[u],u),++s.ans;
		if(s.ans>ans)ans=s.ans;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			dfs1(v);
		}
		s.update(dfn[u],dfn[u]+siz[u],empty),--s.ans;
		if(~fa)s.update(dfn[fa],dfn[fa]+siz[fa],fa),++s.ans;
	}
}t1,t2;
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		t1.init(n);t2.init(n);
		F(i,1,n){int f;read(f);t1.adline(--f,i);}
		F(i,1,n){int f;read(f);t2.adline(--f,i);}
		t2.dfs2(ind=0);
		s.build();
		t1.dfs1(ans=0);
		printf("%d\n",ans);
	}
	return 0;
}
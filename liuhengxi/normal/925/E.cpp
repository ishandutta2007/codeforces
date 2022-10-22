#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define inf n
using namespace std;
const int N=1e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,m,hd[N],cnt,t[N],fa[N],dep[N],dfn[N],node[N],ind,siz[N],hc[N],top[N],len[N];
struct datastructure
{
	int m,bl[N],pos[N],b[N],a[N],aa[N],c[N],fakecnt[3*N],*cnt,p[N],ans;
	void pushdown(int i)
	{
		F(j,pos[i],pos[i+1])a[j]=(aa[j]-=b[i]);
		b[i]=0;
	}
	void build(int i)
	{
		pushdown(i);
		sort(a+pos[i],a+pos[i+1]);
		F(j,pos[i],pos[i+1])cnt[a[j]]=0;
		ans-=p[i];
		F(j,pos[i],pos[i+1]+1)if(a[j]>=0||j==pos[i+1])
		{
			ans+=p[i]=j;
			break;
		}
		for(int j=pos[i],k=j;j<pos[i+1];++j)
		{
			if(a[j]!=a[k])k=j;
			++cnt[a[k]];
		}
		F(j,pos[i],pos[i+1])c[j]=cnt[a[j]];
	}
	void blockmodify(int i,int x)
	{
		b[i]-=x;
		if(p[i]<pos[i+1]&&a[p[i]]<b[i])ans+=c[p[i]],p[i]+=c[p[i]];
		if(p[i]>pos[i]&&a[p[i]-1]>=b[i])ans-=c[p[i]-1],p[i]-=c[p[i]-1];
	}
	void brutemodify(int i,int l,int r,int x)
	{
		if(i==m)return;
		pushdown(i);
		F(j,l,r)aa[j]+=x;
		build(i);
	}
	void init()
	{
		cnt=fakecnt+N;
		F(i,0,n)if(len[i])
		{
			int b=max(min((int)sqrt(len[i])/4,len[i]),1);
			F(j,0,len[i])bl[j+i]=m+j/b;
			F(j,m,m+(len[i]+b-1)/b)pos[j]=i+(j-m)*b;
			m+=(len[i]+b-1)/b;
		}
		F(i,0,pos[bl[n]=m]=n)aa[i]=t[node[i]];
		F(i,0,m)build(i),ans-=pos[i];
	}
	void modify(int l,int r,int x)
	{
		int L=pos[bl[l]+1],R=pos[bl[r]];
		if(bl[l]==bl[r])brutemodify(bl[l],l,r,x);
		else
		{
			F(i,bl[l]+1,bl[r])blockmodify(i,x);
			brutemodify(bl[l],l,L,x);
			brutemodify(bl[r],R,r,x);
		}
	}
}ds;
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	fa[u]=f;hc[u]=-1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(!~hc[u]||siz[hc[u]]<siz[v])hc[u]=v;
		siz[u]+=siz[v];
	}
	++siz[u];
}
void dfs(int u)
{
	dfn[node[ind]=u]=ind;++ind;
	++len[dfn[top[u]]];
	if(~hc[u])top[hc[u]]=top[u],dfs(hc[u]);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u]||v==hc[u])continue;
		dfs(top[v]=v);
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int u=i,v;read(v);--v;
		adline(u,v);adline(v,u);
	}
	F(i,0,n)read(t[i]);
	dfs(0,0);dfs(0);
	ds.init();
	while(m--)
	{
		int k;read(k);
		if(k>0)
		{
			--k;
			ds.modify(dfn[k],dfn[k]+1,inf);
			if(k)
			{
				k=fa[k];
				while(true)
				{
					ds.modify(dfn[top[k]],dfn[k]+1,-1);
					if(top[k]==0)break;
					k=fa[top[k]];
				}
			}
		}
		else
		{
			k^=-1;
			ds.modify(dfn[k],dfn[k]+1,-inf);
			if(k)
			{
				k=fa[k];
				while(true)
				{
					ds.modify(dfn[top[k]],dfn[k]+1,1);
					if(top[k]==0)break;
					k=fa[top[k]];
				}
			}
		}
		printf("%d ",ds.ans);
	}
	puts("");
	return 0;
}
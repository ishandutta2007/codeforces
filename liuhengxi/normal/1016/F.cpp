#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
const long long LLINF=0x3fffffffffffffffll;
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
	int next,to,w;
}e[2*N];
int n,m,hd[N],cnt,fa[N],ww[N],siz[N],len[N];
long long a,b=LLINF;
bool on[N];
long long max(long long a,long long b){return a>b?a:b;}
long long min(long long a,long long b){return a<b?a:b;}
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].w=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int f)
{
	fa[u]=f;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		ww[v]=e[i].w;
		dfs1(v,u);
	}
}
void dfs2(int u,int ori,int fa)
{
	++siz[ori];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa||on[v])continue;
		len[ori]=e[i].w;
		dfs2(v,ori,u);
	}
}
int main()
{
	long long pre=0,mx=-LLINF;
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v,w;read(u);read(v);read(w);
		adline(--u,--v,w);adline(v,u,w);
	}
	dfs1(0,0);
	for(int j=n-1;j;j=fa[j])on[j]=true,a+=ww[j];
	on[0]=true;
	F(i,0,n)if(on[i])
	{
		dfs2(i,i,i);if(siz[i]>2)b=0;
	}
	pre=0,mx=-LLINF;
	for(int j=n-1;j;j=fa[j])
	{
		if(len[j])b=min(b,pre-len[j]-mx);
		mx=max(mx,pre+len[j]);
		pre+=ww[j];
	}
	if(len[0])b=min(b,pre-len[0]-mx);
	pre=0,mx=-LLINF;
	for(int j=n-1;j;j=fa[j])
	{
		b=min(b,pre-len[j]-mx);
		if(len[j])mx=max(mx,pre+len[j]);
		pre+=ww[j];
	}
	b=min(b,pre-len[0]-mx);
	for(int j=n-1;j;j=fa[j])if(fa[j])b=min(b,ww[j]+ww[fa[j]]);
	b=max(b,0);
	while(m--)
	{
		int x;read(x);
		if(x<b)printf("%lld\n",a-b+x);
		else printf("%lld\n",a);
	}
	return 0;
}
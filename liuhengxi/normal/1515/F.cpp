#include<cstdio>
#include<cassert>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to,id;
}e[2*N];
int n,m,x,f[N],hd[N],cnt,a[N],ans[N],top,siz[N],p[N],*pp=p,*o[N],k,id[N];
long long s[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].id=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	s[u]=a[u];siz[u]=1;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		s[u]+=s[v];
		siz[u]+=siz[v];
	}
}
bool cmp(int u,int v){return s[u]-x*(siz[u]-1ll)>s[v]-x*(siz[v]-1ll);}
void connect(int u,int fa)
{
	k=0;
	o[u]=pp;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		id[v]=e[i].id;
		o[u][k++]=v;
	}
	sort(o[u],o[u]+k,cmp);
	pp+=k;
	F(i,0,k)
	{
		int v=o[u][i];
		if(s[v]>=x*(siz[v]-1ll))
		{
			connect(v,u);
			ans[top++]=id[v];
		}
		else
		{
			ans[top++]=id[v];
			connect(v,u);
		}
	}
}
int main()
{
	read(n,m,x);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,n)read(a[i]);
	F(i,0,m)
	{
		int u,v;read(u,v);
		if(find(--u)!=find(--v))
		{
			f[f[u]]=f[v];
			adline(u,v,i);adline(v,u,i);
		}
	}
	dfs(0,0);
	if(s[0]<(n-1ll)*x)return puts("NO"),0;
	connect(0,0);
	puts("YES");
	F(i,0,n-1)printf("%d\n",ans[i]+1);
	return 0;
}
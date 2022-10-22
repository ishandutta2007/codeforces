#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
	int next,to,dis;
}e[N<<1];
int n,hd[N],cnt,f[N],r[N],k;
int id[N];
long long l[N],p[N],d[N],ori,ans,pp[N],ss[N],pa[N],sa[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u,int fa)
{
	f[u]=fa;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs1(v,u);
	}
}
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(~id[v]||v==fa)continue;
		dfs(v,u);
		ori=max(ori,d[u]+d[v]+e[i].dis);
		d[u]=max(d[u],d[v]+e[i].dis);
	}
}
int main()
{
	int tu,tv,tw;long long tmp=0;
	read(n);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,n)
	{
		int u,v,w;read(u,v,w);--u,--v;
		if(find(u)==find(v))tu=u,tv=v,tw=w;
		else
		{
			adline(u,v,w);adline(v,u,w);
			f[find(u)]=find(v);
		}
	}
	dfs1(tu,-1);
	for(int u=tv;~u;u=f[u])r[k++]=u;
	F(i,0,n)id[i]=-1;
	F(i,0,k)id[r[i]]=i;
	adline(tu,tv,tw);adline(tv,tu,tw);
	F(i,0,k)dfs(r[i],r[i]);
	F(i,0,n)
	{
		int u=e[i<<1].to,v=e[i<<1|1].to,w=e[i<<1].dis;
		if(~id[u]&&~id[v])l[id[(id[u]-id[v]+k)%k==1?v:u]]=w;
	}
	F(i,0,k)p[i+1]=p[i]+l[i];
	F(i,(pp[0]=d[r[0]],1),k)pp[i]=max(pp[i-1],d[r[i]]+p[i]);
	for(int i=k;~--i;)ss[i]=max(ss[i+1],d[r[i]]+p[k]-p[i]);
	tmp=(pa[0]=d[r[0]])+l[0];
	for(int i=1;i<k;tmp+=l[i++])pa[i]=max(pa[i-1],d[r[i]]+tmp),tmp=max(tmp,d[r[i]]);
	tmp=0;
	for(int i=k-1;~i;tmp+=l[--i])sa[i]=max(sa[i+1],d[r[i]]+tmp),tmp=max(tmp,d[r[i]]);
	ans=pa[k-1];
	F(i,0,k-1)ans=min(ans,max(pp[i]+ss[i+1],max(pa[i],sa[i+1])));
	ans=max(ans,ori);
	printf("%lld\n",ans);
	return 0;
}
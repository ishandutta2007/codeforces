#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5e5+5,INF=0x3fffffff;
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
	int next,to,type;
}e[2*N];
int n,k,m,hd[N],cnt,f[N],u[N],v[N],w[N],fa[N],dep[N],x[N];
long long ans;
bool used[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v,int t=1)
{
	e[cnt].to=v;
	e[cnt].type=t;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int f)
{
	fa[u]=f;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==f)continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}
void dfs(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa[u])continue;
		if(e[i].type&&~ans)
		{
			if(x[v]==INF)ans=-1;
			else ans+=x[v];
		}
		dfs(v);
	}
}
int main()
{
	read(n);read(k);read(m);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,k)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
		f[find(v)]=find(u);
	}
	F(i,0,m)
	{
		read(u[i]);read(v[i]);read(w[i]);
		if(find(--u[i])!=find(--v[i]))
		{
			f[find(u[i])]=find(v[i]);
			adline(u[i],v[i],0);adline(v[i],u[i],0);
			used[i]=true;
		}
	}
	F(i,0,n)x[f[i]=i]=INF;
	dfs(0,0);
	F(i,0,m)if(!used[i])
	{
		int a=u[i],b=v[i],c=w[i];
		while(a!=b)
		{
			if(dep[a]<dep[b])a^=b^=a^=b;
			if(a==find(a))f[a]=fa[a],x[a]=c;
			else a=f[a];
		}
	}
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}
#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct edge
{
	int u,v,w;
	bool operator<(edge b){return w<b.w;}
}ee[N];
struct line
{
	int next,to;
}e[2*N];
int n,m,W,hd[N],cnt,f[N],deg[N];
long long ans;
bool g[5005][5005],vis[N],use[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int find1(int u){return f[u]==u?u:f[u]=find1(f[u]);}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1,f[i]=i;
	F(i,0,m)
	{
		int u,v,w;
		read(u);read(v);read(w);
		adline(--u,--v);
		adline(v,u);
		++deg[u],++deg[v];
		W^=w;
		ee[i].u=u;ee[i].v=v;ee[i].w=w;
	}
	sort(ee,ee+m);
	if(n<5000)
	{
		F(u,0,n)
		{
			for(int i=hd[u];~i;i=e[i].next)
			{
				int v=e[i].to;
				g[u][v]=g[v][u]=1;
			}
		}
		F(u,0,n)F(v,0,n)if(!g[u][v])f[find1(u)]=find1(v);
	}
	else
	{
		int first=-1;
		F(u,0,n)if(deg[u]<4000)
		{
			if(~first)f[u]=first;
			else first=u;
		}
		F(u,0,n)if(deg[u]>=4000)
		{
			F(v,0,n)vis[v]=false;
			for(int i=hd[u];~i;i=e[i].next)
			{
				int v=e[i].to;
				vis[v]=true;
			}
			F(v,0,n)if(!vis[v])f[find1(v)]=find1(u);
		}
	}
	cnt=0;
	F(i,0,m)if(find1(ee[i].u)!=find1(ee[i].v))
	{
		f[find1(ee[i].u)]=find1(ee[i].v);
		ans+=ee[i].w;
		++cnt;
		use[i]=true;
	}
	if(m+n-1-cnt==n*(n-1ll)/2)
	{
		ans+=W;
		F(i,0,n)f[i]=i;
		F(i,0,m)if(use[i])f[find1(ee[i].u)]=find1(ee[i].v);
		F(i,0,m)if(!use[i]&&find1(ee[i].u)!=find1(ee[i].v))
		{
			if(ee[i].w<W)
			{
				ans-=W-ee[i].w;
				break;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
#include<cstdio>
#include<utility>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fi first
#define se second
using namespace std;
const int N=1005;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct line
{
	int next,to,dis;
}e[2*N];
int n,hd[N],cnt,deg[N],rt,x[2*N],y[2*N],z[2*N],m,f[N],val[N];
inline void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
inline void add(int u,int v,int w){x[m]=u,y[m]=v;z[m++]=w;}
inline void modify(int u,int w){for(;u!=rt;u=f[u])val[u]-=w;}
pair<int,int> dfs(int u,int fa)
{
	pair<int,int> leaf={-1,-1};
	f[u]=fa;
	if(deg[u]==1&&u!=rt)return make_pair(u,-1);
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to,delta;if(v==fa)continue;
		val[v]=e[i].dis;
		pair<int,int> result=dfs(v,u);
		(~leaf.fi?leaf.se:leaf.fi)=result.fi;
		if(~result.se)
		{
			add(rt,result.fi,delta=val[v]>>1);
			add(rt,result.se,delta);
			add(result.fi,result.se,-delta);
			modify(v,delta<<=1);
		}
		else add(rt,result.fi,delta=val[v]),modify(result.fi,delta);
	}
	return leaf;
}
int main()
{
	F(i,0,read(n))hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v,w;--read(u),--read(v),read(w);
		++deg[u],++deg[v];
		adline(u,v,w);adline(v,u,w);
	}
	F(i,0,n)if(deg[i]==2)return puts("NO"),0;
	F(i,0,n)if(deg[i]==1)rt=i,i=n;
	dfs(rt,rt);
	puts("YES");
	printf("%d\n",m);
	F(i,0,m)printf("%d %d %d\n",x[i]+1,y[i]+1,z[i]);
	return 0;
}
#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,MOD=1000000007;
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
struct query
{
	int next,id;
}qq[2*N];
int n,hd[N],cnt,a[N],q,x[N],y[N],w[N],qhd[N],qcnt,f[N],lca[N],ans[N];
bool vis[N];
int pow(int a1,int b)
{
	long long c=1,a=a1;
	while(b)
	{
		if(b&1)c=c*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return (int)c;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
int find(int u){return f[u]==u?u:f[u]=find(f[u]);}
namespace number
{
	const int N=10000005,NN=10000000,M=7e5;
	int pri[N],pos[N],cnt,a[M];
	bool vis[N];
	void init()
	{
		vis[0]=vis[1]=true;
		F(i,2,NN+1)
		{
			pos[i+1]=pos[i];
			if(!vis[i])
			{
				pri[cnt++]=i;
				for(int j=NN/i;j;j/=i)++pos[i+1];
			}
			F(j,0,cnt)
			{
				if(i*pri[j]>NN)break;
				vis[i*pri[j]]=true;
				if(i%pri[j]==0)break;
			}
		}
	}
	void add(int x,int type)
	{
		int i=2;
		while(i*i<=x)
		{
			int t=0;
			while(x%i==0)++t,x/=i;
			if(t)a[pos[i]+t-1]+=type;
			++i;
		}
		if(x!=1)a[pos[x]]+=type;
	}
	int query(int x)
	{
		int i=2,ans=1;
		while(i*i<=x)
		{
			int t=0,tt=0;
			while(x%i==0)++t,x/=i;
			F(j,pos[i],pos[i+1])
			{
				tt+=a[j]*(j-pos[i]+1<t?j-pos[i]+1:t);
			}
			ans=(long long)ans*pow(i,tt)%MOD;
			++i;
		}
		if(x!=1)
		{
			int tt=0;
			F(j,pos[x],pos[x+1])
			{
				tt+=a[j];
			}
			ans=(long long)ans*pow(x,tt)%MOD;
		}
		return ans;
	}
}
using number::init;using number::add;using number::query;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void adquery(int u,int id)
{
	qq[qcnt].id=id;
	qq[qcnt].next=qhd[u];
	qhd[u]=qcnt++;
}
void dfs(int u,int fa)
{
	add(a[u],1);
	for(int i=qhd[u];~i;i=qq[i].next)
	{
		int id=qq[i].id;
		if(vis[id])
		{
			if(x[id]!=u)x[id]^=y[id]^=x[id]^=y[id];
			lca[id]=find(y[id]);
			ans[id]=(long long)ans[id]*gcd(w[id],a[lca[id]])%MOD;
		}
		else vis[id]=true;
		ans[id]=(long long)ans[id]*query(w[id])%MOD;
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
	}
	f[u]=fa;
	add(a[u],-1);
}
void dfs2(int u,int fa)
{
	add(a[u],1);
	for(int i=qhd[u];~i;i=qq[i].next)
	{
		int id=qq[i].id;
		ans[id]=(long long)ans[id]*pow(query(w[id]),MOD-3)%MOD;
	}
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs2(v,u);
	}
	add(a[u],-1);
}
int main()
{
	read(n);
	F(i,0,n)qhd[i]=hd[i]=-1,f[i]=i;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)read(a[i]);
	read(q);
	F(i,0,q)
	{
		read(x[i]);read(y[i]);read(w[i]);
		adquery(--x[i],i);adquery(--y[i],i);
		ans[i]=1;
	}
	init();
	dfs(0,0);
	qcnt=0;F(i,0,n)qhd[i]=-1;
	F(i,0,q)adquery(lca[i],i);
	dfs2(0,0);
	F(i,0,q)printf("%d\n",ans[i]);
	return 0;
}
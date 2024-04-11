#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5,MOD=1000000007;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct basis
{
	static const int K=62;
	long long v[K],o;
	int cnt;
	void operator+=(long long x)
	{
		o|=x;
		for(int i=K;~--i;)if(x>>i&1)
		{
			if(!v[i])v[i]=x,++cnt;
			x^=v[i];
		}
	}
}b[N];
struct line
{
	int next,to;long long dis;
}e[2*N];
int hd[N],cnt;
inline void adline(int u,int v,long long w){e[cnt].to=v;e[cnt].next=hd[u];e[cnt].dis=w;hd[u]=cnt++;}
long long sum[N];
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		sum[v]=sum[u]^e[i].dis;
		dfs(v,u);
	}
}
int n,m,u[M],v[M],f[N],zero[N],one[N],ans;
long long w[M];
bool on[M];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n,m);
	F(i,0,n)f[i]=i,hd[i]=-1;
	F(i,0,m)read(u[i],v[i],w[i]),--u[i],--v[i];
	F(i,0,m)if(find(u[i])!=find(v[i]))
	{
		f[f[u[i]]]=f[v[i]];
		on[i]=true;
		adline(u[i],v[i],w[i]);
		adline(v[i],u[i],w[i]);
	}
	F(i,0,n)if(find(i)==i)dfs(i,i);
	F(i,0,m)
	{
		int c=find(u[i]);
		b[c]+=sum[u[i]]^sum[v[i]]^w[i];
	}
	F(k,0,62)
	{
		long long co=(1ll<<k)%MOD;
		F(i,0,n)one[i]=zero[i]=0;
		F(i,0,n)++(sum[i]>>k&1?one:zero)[f[i]];
		F(i,0,n)if(f[i]==i)
		{
			if(b[i].o>>k&1)
			{
				long long c=(1ll<<(b[i].cnt-1))%MOD;
				one[i]+=zero[i];
				zero[i]=one[i]-1;
				(ans+=int(co*one[i]%MOD*zero[i]%MOD*c%MOD*500000004%MOD))%=MOD;
			}
			else
			{
				long long c=(1ll<<b[i].cnt)%MOD;
				(ans+=int(co*one[i]%MOD*zero[i]%MOD*c%MOD))%=MOD;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
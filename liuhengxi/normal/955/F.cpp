#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,LogN=21;
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
struct line
{
	int next,to;
}e[2*N];
int n,logn,hd[N],cnt,dp1[N],f[N][LogN],g[N][LogN],s[N],t;
long long ans;
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	f[u][1]=n;
	g[u][1]=n;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		dp1[u]=max(dp1[u],dp1[v]);
		F(k,1,logn+1)g[u][k]=max(g[u][k],g[v][k]);
	}
	F(k,1,logn)
	{
		int &a=f[u][k+1];
		t=0;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(v==fa)continue;
			s[t++]=f[v][k];
		}
		sort(s,s+t,greater<int>());
		s[t]=0;
		while(s[a]>a)++a;
	}
	F(k,1,logn+1)g[u][k]=max(g[u][k],f[u][k]);
	F(k,1,logn+1)ans+=g[u][k]-!!g[u][k];
	ans+=++dp1[u];
}
int main()
{
	read(n);
	while((1<<logn)<=n)++logn;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;--read(u);--read(v);
		adline(u,v);adline(v,u);
	}
	dfs(0,0);
	printf("%lld\n",ans);
	return 0;
}
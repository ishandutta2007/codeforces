#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,M=2e5+5;
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
	int next,to;
}e[2*M];
int n,sqrtn,m,hd[N],cnt,u[M],v[M],fa[N],dep[N],c[N];
bool vis[N],is[M];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(vis[v])continue;
		is[i>>1]=true;
		dep[v]=dep[fa[v]=u]+1;
		dfs(v);
	}
}
int main()
{
	read(n,m);
	while(sqrtn*sqrtn<n)++sqrtn;
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		read(u[i],v[i]);
		adline(--u[i],--v[i]);adline(v[i],u[i]);
	}
	dfs(0);
	--sqrtn;
	F(i,0,m)if(dep[u[i]]%sqrtn==dep[v[i]]%sqrtn)
	{
		int a=u[i],b=v[i],len=0;
		if(dep[a]<dep[b])a^=b^=a^=b;
		for(int a_=a;a_!=b;a_=fa[a_])++len;
		puts("2");
		printf("%d\n",++len);
		for(;a!=b;a=fa[a])printf("%d ",a+1);
		printf("%d\n",b+1);
		return 0;
	}
	F(i,0,n)++c[dep[i]%sqrtn];
	F(i,0,sqrtn)if(c[i]>sqrtn)
	{
		int cnt=0;
		puts("1");
		F(j,0,n)if(dep[j]%sqrtn==i&&cnt<=sqrtn)++cnt,printf("%d ",j+1);
		puts("");
		return 0;
	}
	return 0;
}
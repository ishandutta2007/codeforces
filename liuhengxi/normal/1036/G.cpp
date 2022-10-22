#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5,M=(1<<20)+5;
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
}e[N];
int n,m,hd[N],cnt,k/*number of sources/sinks*/,s[25],t[25],f[N],a[M],pop[M];
bool iss[N],ist[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	if(f[u])return;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		f[u]|=f[v];
	}
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1,iss[i]=ist[i]=true;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);
		ist[u]=false;iss[v]=false;
	}
	F(i,0,n)if(iss[i])s[k++]=i;
	k=0;
	F(i,0,n)if(ist[i])t[k++]=i;
	F(i,0,k)f[t[i]]=1<<i;	
	F(i,0,k)dfs(s[i]),a[1<<i]=f[s[i]];
	F(i,1,1<<k)pop[i]=pop[i^(i&-i)]+1;
	F(i,1,(1<<k)-1)
	{
		a[i]=a[i&-i]|a[i^(i&-i)];
		if(pop[a[i]]<=pop[i])return puts("NO"),0;
	}
	puts("YES");
	return 0;
}
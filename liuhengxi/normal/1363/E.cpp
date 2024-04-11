#include<cstdio>
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
struct line
{
	int next,to;
}e[2*N];
int n,hd[N],cnt,a[N],b[N],c[N];
long long ans;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	int d=0;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		a[v]=a[u]<a[v]?a[u]:a[v];
		dfs(v,u);
		b[u]+=b[v];
		c[u]+=c[v];
	}
	d=b[u]<c[u]?b[u]:c[u];
	b[u]-=d;c[u]-=d;
	ans+=2ll*d*a[u];
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),read(b[i]),read(c[i]),hd[i]=-1;
	F(i,0,n)if(b[i]&&c[i])--b[i],--c[i];
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	if(b[0]||c[0])ans=-1;
	printf("%lld\n",ans);
	return 0;
}
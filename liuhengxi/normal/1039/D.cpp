#include<cstdio>
#include<cmath>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int n,hd[N],cnt,f[N],g[N],ans[N],m,node[N],ind,to[N],pos[N],ch[N],ind2;
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	pos[u]=ind2;
	for(int i=hd[u];~i;i=e[i].next)if(e[i].to!=fa)to[ind2++]=e[i].to,++ch[u];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
	}
	node[ind++]=u;
}
int dp(int k)
{
	int max1,max2,u,v;
	F(j,0,n)
	{
		max1=0,max2=0;u=node[j];
		f[u]=g[u]=0;
		F(i,pos[u],pos[u]+ch[u])
		{
			f[u]+=f[v=to[i]];
			if(g[v]>max1)max2=max1,max1=g[v];
			else if(g[v]>max2)max2=g[v];
		}
		if(max1+max2+1>=k)++f[u];
		else g[u]=max1+1;
	}
	return f[0];
}
int findbound(int x,int l,int r)// find the first answer < x
{
	int mid;
	while(r-l>1)// (l,r]
	{
		mid=(l+r)>>1;
		if(dp(mid)<x)r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n);
	m=sqrt(n*log10(n));
	m=min(max(m,1),n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	dfs(0,0);
	F(i,1,m+1)ans[i]=dp(i);
	for(int l=m+1,r=m+1;l<=n;l=r)
	{
		int x=dp(l);
		r=findbound(x,l,n+1);
		F(i,l,r)ans[i]=x;
	}
	F(i,1,n+1)printf("%d\n",ans[i]);
	return 0;
}
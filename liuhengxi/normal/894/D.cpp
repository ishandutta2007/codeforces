#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define v1 ((u<<1)+1)
#define v2 ((u<<1)+2)
using namespace std;
const int N=1e6+5,M=2e7+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,l[N],siz[N],p[N],dis[M];
long long sum[M];
int dfs1(int u){return u<n?siz[u]=1+dfs1(v1)+dfs1(v2):0;}
void dfs2(int u)
{
	int i,j,x,y,a,b;
	if(siz[u]==1)return;
	dfs2(v1);
	if(siz[u]==2)return dis[p[u]+1]=sum[p[u]+1]=l[v1],void();
	dfs2(v2);
	i=p[v1],j=p[v2];
	x=p[v1+1],y=p[v2+1];
	a=l[v1],b=l[v2];
	F(k,p[u]+1,p[u+1])
	{
		if(i<x&&(j==y||dis[i]+a<dis[j]+b))dis[k]=dis[i++]+a;
		else dis[k]=dis[j++]+b;
	}
	F(k,p[u]+1,p[u+1])sum[k]=sum[k-1]+dis[k];
}
long long query(int u,int h)
{
	int l=p[u]-1,r=p[u]+siz[u],mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(h<dis[mid])r=mid;
		else l=mid;
	}
	if(l>=p[u])return h*(long long)(l-p[u]+1)-sum[l];
	return 0;
}
int main()
{
	read(n);read(m);
	F(i,1,n)read(l[i]);
	dfs1(0);
	F(i,0,n)p[i+1]=p[i]+siz[i];
	dfs2(0);
	while(m--)
	{
		int a,h;
		long long ans=0;
		read(a);read(h);--a;
		ans+=query(a,h);
		h-=l[a];
		while(a&&h>0)
		{
			int b=((a-1)^1)+1;
			ans+=h;
			ans+=query(b,h-l[b]);
			a=((a+1)>>1)-1;
			h-=l[a];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
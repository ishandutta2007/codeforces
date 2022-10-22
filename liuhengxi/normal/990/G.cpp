#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
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
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],u[N],v[N],w[N],hd[N],cnt,m,fa[N],siz[N];
long long f[N];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int u,int v,long long &ans)
{
	u=find(u);v=find(v);
	if(u==v)return;
	if(siz[u]<siz[v])swap(u,v);
	ans+=(long long)siz[u]*siz[v];
	siz[fa[v]=u]+=siz[v];
}
int main()
{
	F(i,0,read(n))m=max(m,read(a[i]));
	F(i,0,++m)hd[i]=-1;
	F(i,0,n-1)adline(w[i]=gcd(a[--read(u[i])],a[--read(v[i])]),i);
	F(i,0,n)siz[fa[i]=i]=1;
	F(d,1,m)
	{
		for(int j=d;j<m;j+=d)for(int i=hd[j];~i;i=e[i].next)
		{
			int k=e[i].to;
			merge(u[k],v[k],f[d]);
		}
		for(int j=d;j<m;j+=d)for(int i=hd[j];~i;i=e[i].next)
		{
			int k=e[i].to;
			siz[fa[u[k]]=u[k]]=1;
			siz[fa[v[k]]=v[k]]=1;
		}
	}
	for(int i=m-1;i;--i)for(int j=i<<1;j<m;j+=i)f[i]-=f[j];
	F(i,0,n)++f[a[i]];
	F(i,1,m)if(f[i])printf("%d %lld\n",i,f[i]);
	return 0;
}
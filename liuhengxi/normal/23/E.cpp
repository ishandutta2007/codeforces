#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef unsigned int u32;
typedef unsigned long long u64;
const int N=705;
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
struct u512{u32 a[16];};
u512 operator*(u512 a,u512 b)
{
	u512 c;
	for(u32 i=0;i<16;++i)c.a[i]=0;
	for(u32 i=0;i<16;++i)for(u32 j=0,d=0;i+j<16;++j)
	{
		u64 tmp=(u64)a.a[i]*b.a[j]+c.a[i+j]+d;
		c.a[i+j]=(u32)tmp;
		d=(u32)(tmp>>32);
	}
	return c;
}
u512 operator*(u512 a,u32 b)
{
	for(u32 i=0,d=0;i<16;++i)
	{
		u64 tmp=(u64)b*a.a[i]+d;
		a.a[i]=(u32)tmp;
		d=(u32)(tmp>>32);
	}
	return a;
}
bool operator<(u512 a,u512 b)
{
	for(u32 i=16;~--i;)if(a.a[i]!=b.a[i])return a.a[i]<b.a[i];
	return false;
}
u32 operator%(u512 &a,u32 b)
{
	u32 d=0;
	for(u32 i=16;~--i;)
	{
		u64 tmp=((u64)d<<32)+a.a[i];
		a.a[i]=(u32)(tmp/b);
		d=(u32)(tmp%b);
	}
	return d;
}
struct line
{
	int next,to;
}e[2*N];
int n,hd[N],cnt,top;
char sta[N];
u512 f[N][N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int dfs(int u,int fa)
{
	int siz=1;
	f[u][1].a[0]=1;
	for(int _=hd[u];~_;_=e[_].next)
	{
		int v=e[_].to,m;
		if(v==fa)continue;
		m=dfs(v,u);
		for(int i=siz;i;--i)for(int j=m;~j;--j)f[u][i+j]=max(f[u][i+j],f[u][i]*f[v][j]);
		siz+=m;
	}
	F(i,1,siz+1)f[u][0]=max(f[u][0],f[u][i]*i);
	return siz;
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u,v);--u,--v;
		adline(u,v);adline(v,u);
	}
	dfs(0,0);
	while(f[n][0]<f[0][0])
	{
		sta[top++]=(char)((f[0][0]%10)+48);
	}
	while(top)putchar(sta[--top]);
	puts("");
	return 0;
}
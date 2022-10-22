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
}e[N];
int n,c[N],hd[N],cnt,f[N][2],p[N],s[N],a[N],b[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	if(c[u])
	{
		f[u][0]=0;
		f[u][1]=1;
		for(int i=hd[u],v=e[i].to;~i;i=e[i].next,v=e[i].to)
		{
			dfs(v);
			f[u][1]=(long long)f[u][1]*(f[v][0]+f[v][1])%MOD;
		}
	}
	else
	{
		int m=0;
		f[u][0]=1;
		for(int i=hd[u],v=e[i].to;~i;i=e[i].next,v=e[i].to)
		{
			dfs(v);
			f[u][0]=(long long)f[u][0]*(f[v][0]+f[v][1])%MOD;
			++m;
		}
		for(int i=hd[u],v=e[i].to,k=0;~i;i=e[i].next,v=e[i].to,++k)
		{
			a[k]=f[v][1];
			b[k]=(a[k]+f[v][0])%MOD;
		}
		s[m]=p[0]=1;
		F(i,0,m)p[i+1]=(long long)p[i]*b[i]%MOD;
		for(int i=m-1;~i;--i)s[i]=(long long)s[i+1]*b[i]%MOD;
		F(i,0,m)
		{
			f[u][1]+=(long long)p[i]*a[i]%MOD*s[i+1]%MOD;
			f[u][1]%=MOD;
		}
	}
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,1,n)
	{
		int fa;read(fa);
		adline(fa,i);
	}
	F(i,0,n)read(c[i]);
	dfs(0);
	printf("%d\n",f[0][1]);
	return 0;
}